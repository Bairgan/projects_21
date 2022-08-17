#include "../../include/minishell.h"

void sort_export_list(t_envlist **ptr, int size, t_envlist * head)
{
	t_envlist *tmp;
	int i = 1;

	tmp = *ptr;
	while (i != 0)
	{
		i = 0;
		while ((*ptr) != head && (*ptr)->next != head)
		{
			if ((((*ptr)->next->name) != NULL) && (ft_strcmp((*ptr)->name, (*ptr)->next->name)) > 0)
			{
				tmp = (*ptr)->next->next;
				insert_before_2(*ptr, (*ptr)->next);
				(*ptr)->next = tmp;
				i = 1;
			}
			*ptr = (*ptr)->next;
		}
		*ptr = (*ptr)->next->next;
		size--;
	}
	
}

void	ft_print_list_export(t_envlist * head)
{
	t_envlist *ptr;
	int size;

	size = ft_count_env_list(head);
	ptr = head->next;
	sort_export_list(&ptr, size, head);
	while(ptr != head)//печатаем до тех пор пока птр не станет указывать на head, это значит мы дощли до последнго элемента перед LOCK (HEAD), где next указывает на head
	{
		printf("declare -x ");
        printf("%s", ptr->name);
		if (ptr->value != NULL)
			printf("=\"%s\"", ptr->value);
		printf("\n");
		ptr = ptr->next;
	}
	printf("\n");
}

int ft_replace_val(t_envlist* head, char *name, char *val)
{
    t_envlist *ptr;

    ptr = NULL;
    ptr = head->next;
    while(ptr != head)
    {
        if(ft_strcmp(name, ptr->name) == 0)
            {
            ptr->value = ft_strdup(val);
            }
        ptr = ptr->next;
    }
    
    return (0);
}


int *ft_exp_parsing(t_envlist* head, char *str)
{
	char *buf; // для записи до =
	char *buf2; //для записи после =
	
	int i;
	int i2;
	
	buf = malloc(sizeof(char) * ft_strlen(str));//!защита буффера + защита от утечек..
	buf2 = malloc(sizeof(char) * ft_strlen(str));
	
    i = 0;
	while(str[i] !=  '=')
		{
			buf[i] = str[i];
			i++;
		}
	buf[i] = '\0';
    i++;
    i2 = 0;
	while(str[i] != '\0')
	{
		buf2[i2] = str[i];
		i++;
		i2++;
	}
	buf2[i2] = '\0';
     
    if(ft_dup_check(head, buf) == 0)//if no duplication add new
         push_back(head, buf, buf2);
    if(ft_dup_check(head, buf) == 1)
        {
          ft_replace_val(head, buf, buf2); //if dup - replace
        }         
	free(buf);
	free(buf2);
	return (0);
}

int ft_dup_check(t_envlist * head, char *name)
//check if there an entry in list
{
   t_envlist * ptr;
   ptr = head->next; //1st element is LOCK
    while(ptr != head)
    {
        if(ft_strcmp(ptr->name, name) == 0)
            {
                return (1); //ret 1 if entry is there
            }
        ptr = ptr->next;
    }
    return(0);
}


int ft_export_in_envp(t_envlist * head, char *name)//export name+value in list
{
	
	char *val;

    val = NULL;
    
	    //printf("exporting: name: [%s] val: [%s]\n", name, val);//!del
    push_back(head, name, val);	 //adding, if no oldpwd in list
		
	return (0);
}


int ft_export(t_list *ptr, t_envlist * head, t_cdata *cdata, int p)
{
	int i;
    int error_flag;
    int stdout_copy;

    error_flag = 0;
    if(ptr->num_red > 0)
			stdout_copy = ft_make_redirect(1, ptr, arr->also);
    if(ptr->fin[1] == NULL) //if export without args need to print all envp
		{
			ft_print_list_export(head);
        }   
	if(ptr->num_red > 0)//return back stdout
	{
		dup2(stdout_copy, STDOUT_FILENO);
		close(stdout_copy);
	}
    i = 1;
    while(ptr->fin[i] != NULL)
    {
        if((ft_isdigit(ptr->fin[i][0])) == 1 || ptr->fin[i][0] == '=')//if more than 1 params with error
            {
				error_flag = 1;
				ft_error_exit(51, ptr->fin[i], cdata);
				i++;
				continue;
            }
        if(ft_strchr(ptr->fin[i], '=') == NULL)//if there just name
        {
            if((ft_dup_check(head, ptr->fin[i])) == 0)//if no dup -> add
                   ft_export_in_envp(head, ptr->fin[i]);
	    }
        if(ft_strchr(ptr->fin[i], '=') != NULL)
            {
                ft_exp_parsing(head, ptr->fin[i]);//pars and add new value
            }
        
        i++;
    }
    if(ptr->num_red > 0)
	{
		dup2(stdout_copy, STDOUT_FILENO);
		close(stdout_copy);
	}
	if(p == 1)//if it start in pipe
	{
		// if(error_flag == 1)
		// 	ft_error_exit(50, ptr->fin[i], cdata);
		exit(0);
	}
		
	if(error_flag == 1)
		return (1);
	return (0);
}