#include "../../include/minishell.h"

int ft_count_env_list(t_envlist * head)
{
	t_envlist * tmp;
	int i;

	i = 0;
	tmp = NULL;
	tmp = head->next;
	
	while (tmp != head)
	{
		
		tmp = tmp->next;
		i++;
	}
	//printf("3\n");
	return (i);
}

t_data	*ft_datanew(char **e, t_envlist * head)
{
	t_data *tmp;
	t_envlist * t;

	int count;
	int i = 0;

	tmp = (t_data *)malloc(sizeof(t_data));
	if (tmp == NULL)
		return (tmp);
	count = ft_count_env_list(head);
//	printf("COUNT L %d\n", count);
//	printf("HEAD %s, %d\n", head->next->value, i);
	t = head->next;
	tmp->envp = (char**)malloc(sizeof(char*) * count  + 1);
	while (i < count)
	{
		tmp->envp[i] = (char*)malloc(sizeof(char) * (ft_strlen(t->value) + ft_strlen(t->name) + 2));
		ft_memset(tmp->envp[i], 0, sizeof(tmp->envp[i]));
//		printf("H %s   %s\n", t->name, t->value);
		ft_strlcat(tmp->envp[i], t->name, ft_strlen(t->name) + ft_strlen(tmp->envp[i]) + 1);//ft_strjoin(tmp->envp[i], t->name);
		if (t->value != NULL)
		{
			ft_strlcat(tmp->envp[i], "=", ft_strlen("=") + ft_strlen(tmp->envp[i]) + 1);//ft_strjoin(tmp->envp[i], "=");
			ft_strlcat(tmp->envp[i], t->value, ft_strlen(t->value) + ft_strlen(tmp->envp[i]) + 1);//ft_strjoin(tmp->envp[i], t->value);
			ft_strlcat(tmp->envp[i], "\0", ft_strlen("\0") + ft_strlen(tmp->envp[i]) + 1);//ft_strjoin(tmp->envp[i], "\0");
		}
	//	printf("STR %s\n", tmp->envp[i]);
		i++;
		t = t->next;
	}
	tmp->envp[i] = NULL;
	return (tmp);
}
