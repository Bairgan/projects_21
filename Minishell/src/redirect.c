#include "../include/minishell.h"

int ft_file_open(char *red_type, char *filename, t_cdata * cdata, t_list *ptr)
{
	
	int file;
	
	if(ft_strcmp(red_type, ">") == 0)
		file = open(filename, O_RDWR | O_CREAT, 0777); //open wronly or create, if it doesn't exist,
														// with chmod 777 (in octal)
	if(ft_strcmp(red_type, ">>") == 0)
		file = open(filename, O_RDWR | O_CREAT | O_APPEND, 0777); //add in file
	
	if(ft_strcmp(red_type, "<") == 0)
		{
		
		file = open(filename, O_RDONLY); //read for < in file
		printf("fileopen <: filename [%s], filefd [%d]\n", filename, file);//!del
		if(file < 0)
			{
			ft_putstr_uni("Minishell: " , 2);
			perror(filename);//std eroro if no such file
			exit(1);
			}
		}
	if(ft_strcmp(red_type, "<<") == 0)
		file = ft_heredoc(ptr, cdata->head,cdata, filename); //create file by heredoc
	return (file);													
}

int ft_redirect_switch(int fd, char *red_type)
{
	
	if(ft_strcmp(red_type, ">") == 0 || ft_strcmp(red_type, ">>") == 0)
		dup2(fd, STDOUT_FILENO); //for > and >>
	if(ft_strcmp(red_type, "<") == 0 || ft_strcmp(red_type, "<<") == 0)
		{
		dup2(fd, STDIN_FILENO); //for <
		}		
	return (0);
}

int ft_redirect_to(t_list *ptr, t_cdata *cdata)
{
	
	t_arg *red; //ptr to redirect
	red = ptr->red;
	int *file = malloc(sizeof(int) * arr->num_red); //filefd for redirect
	int i;
	
	i = 0;
	while (i < ptr->num_red)
	{
		
		file[i] = ft_file_open(red->content, red->next->content, cdata, ptr);
		printf("ft_redirect_to numred [%d], i: [%d], filefd[%d]\n",ptr->num_red, i, file[i]);//!del
		if(ptr->num_red == 1)
			{
				ft_redirect_switch(file[i], red->content);
				//dup2(file[i], STDOUT_FILENO); //if only 1 file
				return(0);
			}
		ft_redirect_switch(file[i], red->content);	
		red = red->next;			
		red = red->next;
		i++;		
	}
    //ft_redirect_switch(file[i - 1], kostyl);
	//dup2(file[i - 1], STDOUT_FILENO); //redirect output into file
	i = 0;
	while (i < ptr->num_red)
	{
		close(file[i]);
		i++;
	}
	free(file);
	return (0);
}

int ft_make_redirect(int type, t_list *ptr, t_cdata * cdata)

{
 //will return stdout
	int stdoutcopy;
	int stdincopy;

	//printf("C_3\n");
	if (ft_strcmp(ptr->red->content, "<") == 0 || ft_strcmp(ptr->red->content, "<<") == 0)
	{
		
	//	printf("C_4\n");
		// if (ptr->red->next == NULL)
		// 	{
		// 	printf("Minishell: syntax error near unexpected token `newline'\n");
		// 	}
		stdincopy = dup(STDIN_FILENO); //copy and return stdin for builtin to get stdout back
		ft_redirect_to(ptr, cdata);
	}
	if (ft_strcmp(ptr->red->content, ">") == 0 || ft_strcmp(ptr->red->content, ">>") == 0)
	{
	//	printf("C_5\n");
		stdoutcopy = dup(STDOUT_FILENO); //copy and return stdout for builtin to get stdout back
		ft_redirect_to(ptr, cdata);
	}
	return(stdoutcopy);
}


/*
working version

int ft_child_redirect()
{
	t_arg *red; //ptr to redirect
	red = arr->red;
	int *file = malloc(sizeof(int) * arr->num_red); //filefd for redirect
	int i;

	i = 0;
	
	while (i < arr->num_red)
	{
		file[i] = ft_file_open(red->content, red->next->content);
		printf("numred [%d], i: [%d], filefd[%d]\n",arr->num_red, i, file[i]);//!del
		if(arr->num_red == 1)
			{
				dup2(file[i], STDOUT_FILENO); //if only 1 file
				return(0);
			}
		red = red->next;			
		red = red->next;
		i++;		
	}
    dup2(file[i - 1], STDOUT_FILENO); //redirect output into file
	i = 0;
	while (i < arr->num_red)
	{
		close(file[i]);
		i++;
	}
	free(file);
	return (0);
}



working version 2

int ft_child_redirect()
{
	t_arg *red; //ptr to redirect
	red = arr->red;
	int *file = malloc(sizeof(int) * arr->num_red); //filefd for redirect
	int i;

	i = 0;
	
	while (i < arr->num_red)
	{
		file[i] = ft_file_open(red->content, red->next->content);
		printf("numred [%d], i: [%d], filefd[%d]\n",arr->num_red, i, file[i]);//!del
		if(arr->num_red == 1)
			{
				dup2(file[i], STDOUT_FILENO); //if only 1 file
				return(0);
			}
		red = red->next;			
		red = red->next;
		i++;		
	}
    dup2(file[i - 1], STDOUT_FILENO); //redirect output into file
	i = 0;
	while (i < arr->num_red)
	{
		close(file[i]);
		i++;
	}
	free(file);
	return (0);
}

int ft_redirect_to(t_list *ptr)
{
	t_arg *red; //ptr to redirect
	red = ptr->red;
	int *file = malloc(sizeof(int) * arr->num_red); //filefd for redirect
	int i;
	char * kostyl;//! for > >> <, but need red->prev

	kostyl = NULL;
	i = 0;
	while (i < ptr->num_red)
	{
		file[i] = ft_file_open(red->content, red->next->content);
		kostyl = ft_strdup(red->content);//!kostyl del
		printf("ft_redirect_to numred [%d], i: [%d], filefd[%d]\n",ptr->num_red, i, file[i]);//!del
		if(arr->num_red == 1)
			{
				ft_redirect_switch(file[i], red->content);
				//dup2(file[i], STDOUT_FILENO); //if only 1 file
				return(0);
			}
		red = red->next;			
		red = red->next;
		i++;		
	}
    ft_redirect_switch(file[i - 1], kostyl);
	//dup2(file[i - 1], STDOUT_FILENO); //redirect output into file
	i = 0;
	while (i < ptr->num_red)
	{
		close(file[i]);
		i++;
	}
	free(file);
	return (0);
}

*/
