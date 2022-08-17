#include "../include/minishell.h"

int ft_count_bufsize(char **envp);
void ft_print_spis_end_env(t_envlist* list_end);
t_envlist *ft_env_lstnew(char *name, char *value, t_envlist *prev);
t_envlist *ft_env_parsing(t_envlist* list_ptr, char **envp);

int ft_putstr_uni(char *s, int out)
{
	//вместо out можно прислать файловый дискриптор... либо печатать в файл через ft_putstrfd? если это вообще надо
	write(out, s, ft_strlen(s));
	//write(out, "\n", 1);

	return (0);
}

int check_builtin(char *cmd) //просто проверка на совпадение со втроенными командами
{
//	printf("C\n");
//	printf("CM_BI %s\n", arr->cmd);
//	printf("D\n");
	if((ft_strcmp(cmd, "echo")) == 0 ||
		 (ft_strcmp(cmd, "cd")) == 0 ||
		 (ft_strcmp(cmd, "pwd")) == 0 ||
		 (ft_strcmp(cmd, "export")) == 0 ||
		 (ft_strcmp(cmd, "unset")) == 0	||
		 (ft_strcmp(cmd, "env")) == 0 ||
		 (ft_strcmp(cmd, "<<")) == 0 ||
		 (ft_strcmp(cmd, "exit")) == 0)
		{
			return (1);
		}
		
	else
		return(0);	
}

char * ft_search_envp_list(t_envlist * envlist, char *str)//поиск по  ENV
{
	//char 	**for_split;
	t_envlist * tmp;
	char	*result;
	
	tmp = NULL;
	tmp = envlist->next;
	//printf("M\n");
	//printf("ENV_L %s\n", str);
	while (tmp->value != NULL)
	{
		//for_split = ft_split(data->envp[i], '=');
		//printf("T %s\n", tmp->value);
		if ((ft_strcmp(tmp->name, str)) == 0)
		{
			result = ft_strdup(tmp->value); //!! надо фришить strdup
			return(result);
		}
		tmp = tmp->next;
	}
	//printf("N\n");
	return (NULL);
}


void ft_print_spis_end_env(t_envlist* list_end) //распечатка списка envp
{
	 t_envlist* tmp;

	 tmp = list_end;
	 while(tmp != NULL)
		{
			printf("%s=", tmp->name);
			printf("%s\n", tmp->value);
			tmp = tmp->prev;
		}
}

t_envlist *ft_env_lstnew(char *name, char *value, t_envlist *prev) //для создания нового элемента списка для парсинга envp
{
 t_envlist *tmp;

 tmp = (t_envlist *)malloc(sizeof(t_envlist));
 if (tmp == NULL)
 	 return (tmp);
 tmp->name = name;
 tmp->value = value;
 tmp->prev = prev;
 tmp->next = NULL;
 return (tmp);
}

int ft_count_bufsize(char **envp) //расчет длинны буфера для  envp
{
	int i;
	int i2;
	int buffs;

	buffs = 0;
	i = 0;
	while(envp[i] != NULL)
	{
		i2 = 0;
		while(envp[i][i2] != '\0')
		{
			i2++;
		}
		if(buffs < i2)
			buffs = i2;
		i++;	
	}
	return(buffs);	
}

t_envlist *ft_env_parsing(t_envlist* list_ptr, char **envp)
{
	t_envlist * tmp; //указатель для временного добавления следующего элемента списка.

	char *buf; // для записи до =
	char *buf2; //для записи после =
	int sze;
	int i;
	int i2;
	int i3;


	tmp = NULL;

	sze = ft_count_bufsize(envp); //расчет максимальной длинный буфера

	i = 0;
	while(envp[i] != NULL)
	{
		buf = malloc(sizeof(char) * 300);//!защита буффера + защита от утечек..
		buf2 = malloc(sizeof(char) * sze);
		i2 = 0;
		while(envp[i][i2] != '\0')
		{
			while(envp[i][i2] !=  '=')
				{

					buf[i2] = envp[i][i2];
					i2++;
				}
			i2++;
			i3 = 0;
			while(envp[i][i2] != '\0')
				{
					buf2[i3] = envp[i][i2];
					i2++;
					i3++;
				}
		}
		buf[i2] = '\0';
		buf2[i3] = '\0';
		tmp = push_front(list_ptr, buf, buf2);
		//printf("new - %s\n", tmp->name);//!del
		//tmp = ft_env_lstnew(buf, buf2, list_ptr); //! это работало - создаем новый элемет, tmp становится указателем на ПОСЛЕДНИЙ элт, перед ним LIST PTR
		//list_ptr = tmp; //! это работало - list ptr  указывает на ПОСЛЕДНИЙ
		i++;
	}

	free(buf);
	free(buf2);
	return (list_ptr);
}


void	ft_split_free(char **str)
{
	int	i;
	
	if (str == NULL)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}