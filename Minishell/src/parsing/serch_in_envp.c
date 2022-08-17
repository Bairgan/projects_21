#include "../../include/minishell.h"


int	ft_strcmp_plus(const char *s1, const char *s2)
{
	size_t	i;
	int		g;
	
	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] == s2[i])
		{
			i++;
		}
		else
		{
			g = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (g);
		}
	}
	return (0);
}

char *ft_search_in_envp_l(t_data *data, char *str, t_cdata *cdata)
{
	char 	**for_split;
	char	*result;
	int		i;
	
	i = 0;
	if (ft_strcmp(str, "?") == 0)
	{
		result = ft_itoa(cdata->exit_stat);
		printf("RESULT ITOA________________________ %s cadata %d\n",result, cdata->exit_stat);
		return (result);
	}
	while (data->envp[i])
	{
		for_split = ft_split(data->envp[i], '=');
		if (ft_strcmp_plus(for_split[0], str) == 0)
		{
		//	printf("CMP\n");
			result = ft_strcpy(for_split[1]);
			ft_split_free(for_split);
			return(result);
		}
		ft_split_free(for_split);
		i++;
	}
	return (NULL);
}
