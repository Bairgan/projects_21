#include "../include/minishell.h"


int ** ft_open_pipe(t_cdata * cdata)//open pipe fd
{
	int i;
	int **arr;

	if (!(arr = (int **)malloc(sizeof(int *) * cdata->num_pipe)))
		{
			printf("ERROR1\n");
			return (NULL);
		}
	i = 0;
	while(i < cdata->num_pipe)
	{
		if(!(arr[i] = malloc(sizeof(int) * 2)))
			{
			printf("ERROR1\n");
			return (NULL);
		}
		
		i++;
	}
	i = 0;
	while(i < cdata->num_pipe)
	{
		if (pipe(arr[i]) == -1)
        	{
            printf("Pipe error\n");
            return(NULL);
            }
		i++;	
	}
	return(arr);
}

int ft_close_pipe(t_cdata * cdata, int ** arr_fd)
{
	int i;
	int n;

	i = 0;
	while(i < cdata->num_pipe)
	{
		n = 0;
		while(n <= 1)
		{
			close(arr_fd[i][n]);
			n++;
		}
		i++;
	}
	return (0);
}

void ft_free_arr(int **arr_fd, t_cdata *cdata)
{
	int i;
	i = 0;
	while(i < cdata->num_pipe)
	{
		free(arr_fd[i]);
		i++;
	}
	free(arr_fd);
	free(cdata->pid);
}

int ft_first_pipe(t_cdata *cdata, int ** arr_fd, t_list *ptr, char ** envp)
{
	char * path;
    path = NULL;
	printf("first pipe cmd - [%s]\n",ptr->cmd); //!del
	path = ft_path_handler(ptr, cdata->head, cdata);

		
	if (path == NULL)//? try to pass that into execve
		{
			printf("path returned before error [%s]\n", path);
			printf("Minishell: %s: No such file or directory\n", ptr->cmd);
			return(1);
		}
	if(path != NULL)
	{
    	cdata->pid[cdata->pid_num] = fork();
	
		if (cdata->pid[cdata->pid_num] < 0) //? do wee need this? for norma
		{
			printf("Fork 1 error\n");
				return(1);
  		}
		printf("first fork - pipe[%d]\n",cdata->usedfd); //!del
	
		if (cdata->pid[cdata->pid_num] == 0)
		{	
			dup2(arr_fd[cdata->usedfd][1], STDOUT_FILENO); //use pipe 0, then pipen ++
			ft_close_pipe(cdata, arr_fd);
			if(check_builtin(ptr->cmd) == 1)
				{
				start_builtin(ptr, cdata->head, cdata, 1);
				return (0);
				}
			else
			{
				//path = ft_path_handler(ptr, cdata->head, cdata);
				//path = ft_findpath_pipe(cdata->head, ptr); //проверяем путь до исполняемого файла
				
				execve(path, ptr->fin, envp);//запускаем дочернюю программу
				free(path);
				ft_error_exit(errno, ptr->cmd, cdata);
				//execlp("ls", "ls", "-la", NULL);//!del
				//return 1;//?вот тут не понял, почему нужна return 1, вроде же программа в форке до лжна сама выполниться и закрыться
			}
			
			return(1);  
        }

	}
	return (0);
}

int ft_middle_pipes(t_cdata *cdata, int ** arr_fd, t_list *ptr, char ** envp)
{
	char * path;
    path = NULL;

	path = ft_path_handler(ptr, cdata->head, cdata);
	if (path == NULL)//? try to pass that into execve
		{
			printf("path returned before error [%s]\n", path);
			printf("Minishell: %s: No such file or directory\n", ptr->cmd);
			return(1);
		}

    cdata->pid[cdata->pid_num] = fork();
    if (cdata->pid[cdata->pid_num] < 0)
     {
           printf("Fork 2 error\n");
            return(1);
    }
	

	
	if (cdata->pid[cdata->pid_num] == 0)
	{	
		dup2(arr_fd[cdata->usedfd - 1][0], STDIN_FILENO); //use pipe 0 (previous)
        dup2(arr_fd[cdata->usedfd][1], STDOUT_FILENO); //sent into  pipe 1 (next)
		ft_close_pipe(cdata, arr_fd);
        if(check_builtin(ptr->cmd) == 1) //? do i nedd it here? builtin in the middle?
            {
			start_builtin(ptr, cdata->head, cdata, 1);
			return(1);
			}
        else
        {
			//path = ft_findpath_pipe(cdata->head, ptr); //проверяем путь до исполняемого файла
			execve(path, ptr->fin, envp);//запускаем дочернюю программу
			free(path);
			ft_error_exit(errno, ptr->cmd, cdata);
			return(1);
		}
		return (0);
        //execlp("head", "head", NULL);
	}
	//ft_close_pipe(cdata, arr_fd);//!?
	return (0);
}


int ft_last_pipe(t_cdata *cdata, int ** arr_fd, t_list *ptr, char ** envp)
{
	char * path;
	path = NULL;
	
	path = ft_path_handler(ptr, cdata->head, cdata);
	cdata->pid[cdata->pid_num] = fork();
	
	if (cdata->pid[cdata->pid_num] < 0)
    {
          printf("Fork 4 error\n");
            return(1);
    }
	printf("last fork - pipe[%d], cmd %s\n",cdata->usedfd, ptr->cmd); //!del
	if (cdata->pid[cdata->pid_num] == 0)
	{
		dup2(arr_fd[cdata->usedfd][0], STDIN_FILENO);
		ft_close_pipe(cdata, arr_fd);
        if(check_builtin(ptr->cmd) == 1)
            {
				start_builtin(ptr, cdata->head, cdata, 1);
			    return(1);
			}
		if(ptr->num_red > 0) //redirect after last pipe
				ft_make_redirect(2, ptr, cdata);
		if(check_builtin(ptr->cmd) == 1)
            {
				start_builtin(ptr, cdata->head, cdata, 1);
			    return(1);
			}
        else
        {
            //path = ft_findpath_pipe(cdata->head, ptr); //проверяем путь до исполняемого файла
            printf("last pipe, path[%s], cmd[%s]\n", path, ptr->cmd);
			execve(path, ptr->fin, envp);//запускаем дочернюю программу
            return(1);
		}
	}
	return (0);
}

int ft_pipe(char **envp, t_envlist * head, t_cdata *cdata)
{
 	
    int **arr_fd; //for all pipe fd
		
    t_list *ptr; //для отправки в pipe списка с командами отдельно каждый лист
	
  	int status; //
    int i2 = 0; //for waitpid 
    ptr = NULL;
    ptr = arr;//список с командами

  	cdata->pid_num = 0; //for counting child process
	cdata->usedfd = 0; //set pipe counter to 0
    cdata->head = head; //my envp list, head node
	cdata->pid = malloc(sizeof(int) * (cdata->num_pipe + 1)); //!free
	
	arr_fd = ft_open_pipe(cdata);//open pipe
    /* 
    printf("rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr\n"); 
	int i = 0;
	int y;
	while(i < cdata->num_pipe)
	{
		y = 0;
		while (y <= 1)
		{
			printf("fd%d: %d\n", i, arr_fd[i][y]);
			y++;
		}
		i++;	
	}
	t_list *ptr2 = arr;
	while(ptr2 != NULL)
	{
		printf("ptr[%s], ptr-next[%p]\n", ptr2->cmd, ptr2->next);
		ptr2 = ptr2->next;
	}
    printf("rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr\n"); 
	*/

	ft_first_pipe(cdata, arr_fd, ptr, envp);
	cdata->pid_num++; //increase pid counter in parent
	if(ptr->next->next != NULL) //if only 1 pipe
		cdata->usedfd++; //increase pipe_fd counter in parent
	ptr = ptr->next; //send second cmd
		
	while (ptr->next != NULL && arr->also->num_pipe > 1) //if more then 2 command for pipe and it not the lastone
	{
		//printf("SENT ------------------------------ mid cmd[%d]- %s, used fd[%d]\n",cdata->tmp_mid_counter, ptr->cmd, cdata->usedfd);
		ft_middle_pipes(cdata, arr_fd, ptr, envp);
		cdata->pid_num++; //increase pid counter in parent
		if (ptr->next->next != NULL)
			cdata->usedfd++; //increase pipe_fd counter in parent if it not last pipe
		ptr = ptr->next;
	}
	ft_last_pipe(cdata, arr_fd, ptr, envp);
	cdata->pid_num++;
   	ft_close_pipe(cdata, arr_fd);
	
	arr->also->num_pipe = 0;
	
	printf("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\n");//!del 
	printf("pid_num %d usedfd %d\n", cdata->pid_num, cdata->usedfd);
    for(int z = 0; z < cdata->pid_num; z++)
	{
		printf("child pid %d id %d\n", z, cdata->pid[z]);
	}
	printf("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\n"); 
	
	i2 = 0;
	printf("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n");//!del
	while (i2 < cdata->pid_num)
    {
       	printf("wait_for %d\n", cdata->pid[i2]);
		waitpid(cdata->pid[i2], &cdata->exit_stat, 0); //!need exit_proc_status
        i2++;
    }
	printf("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n");
	ft_free_arr(arr_fd, cdata);

    return (0);
}






