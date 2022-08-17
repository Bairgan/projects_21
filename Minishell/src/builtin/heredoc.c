#include "../../include/minishell.h"

int ft_heredoc(t_list *arr, t_envlist *head, t_cdata *cdata, char *delimiter)
{
	int status;
	int temp_file;
	char *line;
		

	status = 1;
	temp_file = open(".tmpfile", O_RDWR | O_CREAT, 0777); //create tempfile

	printf("-----------------------------Heredoc start!-------------------------------\n");
	
	line = NULL;
	while (status)
	{
		line = readline("heredoc >>"); //read line
		if(ft_strcmp(line, delimiter) == 0)
			{
				status = 0;
				break;
			}
		printf("%s\n", line);//!del
		
		write(temp_file, line, ft_strlen(line)); //write in file
		write(temp_file, "\n", 1);
	}
	close(temp_file);
	temp_file = open(".tmpfile", O_RDONLY); //read for < in file
	
	
	free(line);
	return (temp_file);
}