#include "../../include/minishell.h"

int find_and_del_node(t_envlist * head, char * name)
{
    t_envlist * ptr;
    ptr = head->next; //!нужно ли в такос случае фришить
    while(ptr != head)
    {
        if(ft_strcmp(ptr->name, name) == 0)
            {
                del_node(ptr);
                return(1);
            }
        ptr = ptr->next;
    }
    return(0);
}

int ft_unset(t_list *arr, t_envlist * head, t_cdata *cdata)
{
    int i;

    if(arr->fin[1] == NULL) //if unset without args just finish
		{
			return(0);
        }


    // printf("****************************[ UNSET ]*********************************\n");//!del
	// for(int b = 0; arr->fin[b] != NULL; b++)
    // {
    //   printf("Arg N:[%d] [%s], ", b, arr->fin[b]);
    // }
    // printf("\n");
    // printf("***********************************************************************\n");//!del

    i = 1;
    while(arr->fin[i] != NULL)
    {
        if(ft_dup_check(head, arr->fin[i]) == 1)
            find_and_del_node(head, arr->fin[i]);
        i++;
    }
    return (0);
}