#include "../../include/minishell.h"


int ft_echo(t_list *ptr, t_envlist * head, int p)
{
    int i;
	int stdout_copy;
    
	i = 1;
//	printf("C_1\n");
	if(arr->num_red > 0)
			stdout_copy = ft_make_redirect(1, ptr, arr->also);
    //!! надо узнать как работает встроенный в парсинг $PATH, есть вероятность что надо переделать
//	printf("C_2\n");
    while (arr->fin[i] != NULL)
    {
		printf("%s", arr->fin[i]);
		if(ptr->fin[i+1] != NULL)
			printf(" "); 
		i++;
	}	
	if (ptr->echo_nflag == 0)
		printf("\n");
    if(ptr->num_red > 0)
	{
		dup2(stdout_copy, STDOUT_FILENO);
		close(stdout_copy);
	}
	if(p == 1)
		exit(0);
    return (0);
}