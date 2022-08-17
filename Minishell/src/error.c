#include "../include/minishell.h"

int ft_error_exit(int err, char *str1, t_cdata *cdata)
{
	//printf("Get error/fail errno[%d], [%s]\n", errno, strerror(errno));//!del
	
	if(err == 13)//for execve error
    {
		printf("Minishell: %s: Permission denied\n", str1);
		exit(126);//that is exit code in bash
	}
	if(err == 50)//for export error
		{
			printf("Minishell: `%s': not a valid identifier\n", str1);
			exit(1);
		}
	if(err == 51)//for export error 2 (in no pipe)
		{	
			ft_putstr_uni("Minishell: `", 2);
			ft_putstr_uni(str1, 2);
			ft_putstr_uni("': not a valid identifier\n", 2);
			cdata->exit_stat = 1;
		}
	if(err == 60)//error for ext_cmd
		{	
		if((ft_strchr(str1, '/')) != NULL) 
			{
			ft_putstr_uni("Minishell: ", 2);
			ft_putstr_uni(str1, 2);
			ft_putstr_uni(": No such file or directory\n", 2);		
			}
		else
			{
			ft_putstr_uni(str1, 2);
			ft_putstr_uni(": command not found\n", 2);	
			}
		cdata->exit_stat = 1;
		}
	if(err == 70)//error for cd
		{	
			ft_putstr_uni("Minishell: ", 2);
			ft_putstr_uni(str1, 2);
			ft_putstr_uni(": No such file or directory\n", 2);
			cdata->exit_stat = 1;		
		}	
	return (1);
}


int ft_sytax_error_check(t_arg *arg)//check comman line cmd > 1 > ?
{
	int i;
	t_arg *tmp;
	
	tmp = arg;
	i = 0;
	while(tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	if( i % 2 != 0)
		return(1);
	return (0);
}

int ft_exit_status_check(t_cdata *cdata)//?
{

    int waitstatus;//looking what would return child process
    int statuscode;

	waitstatus = cdata->exit_stat;
        if(WIFEXITED(waitstatus))//macros -> return true (not equal 0), if child programm was finished correctly
        {
            statuscode = WEXITSTATUS(waitstatus); //macros get exitstatus of children process
			//printf("Procees finished\n");//!del
			return(statuscode);
		
			
		
			// if(statuscode == 0)
            // {
            //     printf("Child process success\n");
            // }
            // else
            //      printf("Child process failure with status code %d\n", statuscode);
        }
		if(WIFSIGNALED(waitstatus))
		{
			statuscode = WTERMSIG(waitstatus);
			//printf("Process was killed by signal\n");//!del
			return(statuscode);
		}
		//WIFSIGNALED(status)
    return(waitstatus);    
}	
