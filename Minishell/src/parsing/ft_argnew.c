#include "../../include/minishell.h"

t_arg *ft_argnew(char *content, t_arg *prev)
{
	t_arg *tmp;

	tmp = (t_arg *)malloc(sizeof(t_arg));
	if (tmp == NULL)
		return (tmp);
	tmp->content = content;
	tmp->prev = prev;
	tmp->next = NULL;
	return (tmp);
}

t_arg *ft_arg_next(t_arg *first, t_arg *next)
{
	t_arg *tmp;

	tmp = first;
	if (tmp == NULL)
	{
		first = next;
		return (first);
	}
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = next;
	return (first);
}
