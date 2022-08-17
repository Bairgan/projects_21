#include "../include/minishell.h"
//ft_strtrim

static char	*endcat(char const *str)
{
	size_t	pi;
	int		i;

	pi = ft_strlen(str) - 1;
	i = (int)pi;
	i++;
	return ((char *)str + i);
}

static char	*startcat(char const *str, char const *set)
{
	int		i;
	size_t	o;

	i = 0;
	o = 0;
	while (set[o])
	{
		if (str[i] == set[o])
		{
			o = 0;
			i++;
		}
		else
			o++;
	}
	return ((char *)str + i);
}

char	*ft_strtrim_start(char const *s1, char const *set)
{
	char	*strstart;
	char	*strend;
	int		len;
	char	*rezult;

	if (!s1 || !set)
		return (NULL);
	strstart = startcat(s1, set);
	strend = endcat(strstart);
	len = strend - strstart;
	if (strstart > strend)
	{
		rezult = malloc (sizeof(char) * 1);
		if (!rezult)
			return (NULL);
		rezult[0] = '\0';
		return (rezult);
	}
	rezult = ft_substr(s1, strstart - s1, len);
	if (!rezult)
		return (NULL);
	return (rezult);
}

char	*ft_strjoin(char const *s1, char const *s2)//copy in libft
{
	char	*str;
	size_t	i;
	size_t	o;

	i = 0;
	o = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[o])
	{
		str[i++] = s2[o++];
	}
	str[i] = '\0';
	return (str);
}

char	*ft_path_handler(t_list *arrptr, t_envlist *head, t_cdata * cdata)
{
 	int 	i;
	int		flag;
	char	**split;
	char	*path;
	char	*tmp_path;

	path = NULL;
	flag = 0;
	i = 0;
	if (arrptr->cmd[0] == '/') //1. /bin/ls search in -that- path
	{
		path = arrptr->cmd;
		if (access(path, 0) == 0)
			flag = 1;
	}
	else if (arrptr->cmd[0] == '.' && arrptr->cmd[1] == '/')//2. ./cmd - look in PWD
	{
		tmp_path = ft_strtrim_start(arrptr->cmd, ".");//remove dot in the beginning
		path = ft_strjoin(cdata->my_pwd, tmp_path);//malloc
		free(tmp_path);
		if (access(path, 0) == 0)
			flag = 1;
		else
		{
			free(path);
			path = NULL;
		}
	}
	else //if just a command
	{
		tmp_path = ft_strjoin("/", arrptr->cmd);
		if ((access((path = (ft_strjoin(cdata->my_pwd, tmp_path))), 0)) == 0)//check bin/ls in current dir
			return(path);
		split = NULL;
		split = ft_split(ft_search_envp_list(head, "PATH"), ':');
		while (split[i])
		{
			path = ft_strjoin(split[i], tmp_path);
			printf(".......DEBUG......New pathhandler: [%s]\n", path);//!del
			if (access(path, 0) == 0)
			{
				flag = 1;
				break ;
			}
			i++;
			free(path);
			path = NULL;
		}
		free(tmp_path);
		ft_split_free(split); //!need to free
	}
	printf("New pathhandler final: [%s]\n", path);//!del
	if (flag == 0)
		return (NULL);
	return (path);

}

int ft_start_ext_cmd(t_list *arrptr, t_envlist *head, char **envp, t_cdata * cdata)//тут выполняетм execve  и форк
{
   // char *tmp_line;
    char * path; 
	pid_t fork_pid_child;

    if(ft_sytax_error_check(arrptr->red) == 1)//this check need to be first
		{
		printf("Minishell: syntax error near unexpected token `newline'\n");
		return (1);
		} 
		
	path = ft_path_handler(arrptr, head, cdata);//сюда возвращается найденный правильный путь //!malloc(2)    

	if (path == NULL)//? try to pass that into execve
		{
			ft_error_exit(60, arrptr->cmd, cdata);
			//printf("path returned before error [%s]\n", path);!del
			
			return(1);
		}
		
	if (path != NULL)
	{
		if((fork_pid_child = fork()) == 0) //делаем форк, при успехе вернет родителю 0
   		{
		//if redirect >
		if(arrptr->num_red > 0)
				ft_make_redirect(1, arrptr, cdata);	
		execve(path, arrptr->fin, envp);
		free(path);
		ft_error_exit(errno, arrptr->cmd, cdata);//print error and exit if execve fail
		}
	
	free(path);
	cdata->last_pid = fork_pid_child; //save pid for stop
    waitpid(fork_pid_child, &cdata->exit_stat, 0);// ожидаем возвращение дочернего пид, options 0 ->WNOHANG (? возврат управления в случае если ни оди дочерний процесс не завершил выполнения)
	}
	return (0);
}
