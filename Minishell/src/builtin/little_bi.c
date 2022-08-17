#include "../../include/minishell.h"


int ft_env(t_envlist *head, int p)
{
	int		stdout_copy;

	if(arr->num_red > 0)
			stdout_copy = ft_make_redirect(1, arr, arr->also);
	print_list(head);
	if(arr->num_red > 0)
			{
				dup2(stdout_copy, STDOUT_FILENO);
				close(stdout_copy);
			}
	if (p == 1)	
		exit (0); //check if run in child, and exit
	return (0);
}

int ft_pwd(t_envlist *head, int p)
{
	char	*buff;
	int		stdout_copy;

	buff = NULL;
	buff = ft_search_envp_list(head, "PWD");
	if(arr->num_red > 0)
			stdout_copy = ft_make_redirect(1, arr, arr->also);
	ft_putstr_uni(buff, 1);
    ft_putstr_uni("\n", 1);
	if(arr->num_red > 0)
			{
				dup2(stdout_copy, STDOUT_FILENO);
				close(stdout_copy);
			}
	free(buff);
	if (p == 1)	
		exit (0); //check if run in child, and exit
	return (0);		
}