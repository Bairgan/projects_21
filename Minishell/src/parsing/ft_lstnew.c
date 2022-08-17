#include "../../include/minishell.h"

t_list	*ft_lstnew(t_list *prev, t_cdata *cdata)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (tmp == NULL)
		return (tmp);
	tmp->arg = NULL;
	tmp->red = NULL;
	tmp->arg = NULL;
	tmp->fin = NULL;
	tmp->also = cdata;
	tmp->num_red = 0;
	tmp->echo_nflag = 0;
	tmp->pipe = 0;
	tmp->home_cd = 0;
	tmp->cmd = NULL;
	tmp->prev = prev;
	tmp->next = NULL;

	return (tmp);
}

t_list *ft_lst_next(t_list *first, t_list *next)
{
	t_list *tmp;

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
