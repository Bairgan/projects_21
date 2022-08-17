#include "../../include/minishell.h"


void ft_set(char **line) //? malloc for 1 byte and set it in 0
{
         *line = (char*)malloc(sizeof(char) * 1);
         ft_memset(*line, 0, sizeof(*line));
}

void ft_skip_space(char **line)
{
	while (**line == ' ' && **line != '\0')
		(*line)++;
}

char *lsh_read_line(void)
{
	char *inpt;

	inpt = readline(" > ");
	if (ft_strlen(inpt) > 0)
		add_history(inpt);
	//printf("%s", inpt);
	//printf("\n");
	return (inpt);
}

int lsh_execute()
{
	return (1);
}

char *ft_realloc(char *gen)
{
	size_t i;
	char *dest;

	i = ft_strlen(gen);
	dest = (char*)malloc(sizeof(char) * (i + 1));  // !!АЛАРМ ТЕЧЕМ 
	ft_memset(dest, 0, sizeof(dest));
	dest = ft_strdup(gen);
	return (dest);
}

int	ft_path_parsing(char **line, char **s, t_data *data, t_cdata *cdata)
{
	char *st;
	int i;
	char *path = NULL;
	unsigned char tmp[5] = "SHELL";

	i = 0;
	//printf("C %c\n", **line);
	if (**line == '$' || **line == '~')
	{
		(*line)++;
	//	printf("P_L %c\n", **line);
		ft_set(&st);
	//	
		while (**line != ' ' && **line != '\0' && **line != '\"' && **line != '\'' && **line != '$' && **line != '=')
		{
			st = ft_realloc(st);
			st[i] = **line;
			(*line)++;
		//	printf("ST_I %c\n", **line);
			i++;
		}
	//	printf("D\n");
		st = ft_realloc(st);
		st[i] = '\0';
	//	printf("____________ST %s\n", st);
		path = ft_search_in_envp_l(data, st, cdata);
		//printf("E pATH %s\n", path);
		//printf("G_1 %s\n", *s);
		if (path != NULL)
		{
		//	printf("f\n");
			ft_strcat(s, &path);
		}
		
		printf("G %s\n", *s);
	}
	if (path)
		return (ft_strlen(path));
	else
	{
		(*line) -= i;
		if (**line == '0')
			ft_strlcat(*s, (const char *)tmp, ft_strlen((char *)tmp) + ft_strlen(*s) + 1);
		if (!(**line >= '0' && **line <= '9'))
			(*line) += i;
		else
			(*line)++;
		return (0);
	}
}

void	ft_db_quote(char **line, char **l, t_data *data, t_cdata *cdata)
{
        int i;
        char *se;

        i = 0;
		
		ft_set(&se);
        if (**line == '\"' && **line != '\0')
        {
                (*line)++;
                while (**line != '\"' && **line != '\0')
                {
                        se = ft_realloc(se);
			//			printf("DB_CH %c\n", **line);
                        if (**line != '\"' && **line != '$')
                                se[i] = **line;
						if (**line == '$')
						{
					//		printf("T\n");
							i += ft_path_parsing(line, &se, data, cdata) - 1;
						//	printf("SE %s\n", se);
							(*line)--;
						}
                        i++;
                        (*line)++;
                }
		(*line)++;
		se = ft_realloc(se);
		se[i] = '\0';
	 	ft_strcat(l, &se);
	//	 printf("DB_L %s\n", *l);
	}
	
	//return (i);
}

void ft_quote(char **line, char **l)
{
	int i;
	char *s;

	i = 0;
	ft_set(&s);
	if (**line == '\'' && **line != '\0')
	{
		(*line)++;
		while (**line != '\'' && **line != '\0')
		{
			s = ft_realloc(s);
			if (**line != '\'')
				s[i] = **line;
			i++;
			(*line)++;
		}
		(*line)++;
	}
	s = ft_realloc(s);
	s[i] = '\0';
	ft_strcat(l, &s);
}

void ft_red_plus(char **line, char **s, t_data *data, t_cdata *cdata)
{
	int i;

	i = 0;
	while (**line != ' ' && **line != '\0')
	{
		if (**line == '$')
		{
	//		printf("A\n");
			i += ft_path_parsing(line, s, data, cdata);
		//	(*line)--;
		//	printf("B %c\n", **line);
		//	printf("PR GEN %s\n", gen);
		}
		if (**line != '\'' &&  **line != '\"' && **line != '\0' && **line != ' ' && **line != '|' && **line != '$')
		{
			*s = ft_realloc(*s);
			(*s)[i] = **line;
			i++;
		}
		else if (**line == '\'')
		{
			ft_quote(line, s);
		//	printf("I %d\n", i);
		//	printf("DB %s\n", gen);
		//	printf("LINE %c\n", **line);
			i = ft_strlen(*s);
			(*line)--;
		}
		else if (**line == '\"')
		{
			ft_db_quote(line, s, data, cdata);
			i = ft_strlen(*s);
			
			(*line)--;
		}
		(*line)++;
		if (((*s)[i - 1] == '>' || (*s)[i - 1] == '<') && **line != (*s)[i - 1])
			break;
	}
	(*s)[i] = '\0';
	printf("RED_0 %s\n", *s);
}

void ft_parsing_redirect(char **line, t_data *data, t_cdata *cdata)
{
	//t_arg *ra;
	t_arg *tm1 = NULL;
	t_arg *tm = NULL;
	char *s;	
	int z;

	z = 2;
//	printf("C\n");
	if (arr->red)
		tm1 = arr->red;
//	printf("D\n");
	if (line[0][0] != '\0' && (line[0][0] == '>' || line[0][0] == '<'))
	{
	//	printf("G\n");
		arr->num_red += 1;
	//	printf("F\n");
		while (**line != '\0' && z != 0 && **line != ' ')
		{
			ft_set(&s);
			ft_red_plus(line, &s, data, cdata);
		//	printf("S %s\n", s);
			tm1 = ft_argnew(s, tm);
		//	printf("E %s\n", tm1->content);
			arr->red = ft_arg_next(arr->red, tm1);
		//	if (arr->red != NULL)
		//		printf("HAVE ARR->RED\n");
			tm = tm1;
			/*ra = ft_argnew(s, tm1);
			arr->red = ra;
			tm1 = ra;
			ra = ra->next;*/
			ft_skip_space(line);
			z--;
		}
	}
}

void ft_parsing_flag(char **line)
{
	int c;


	c = 0;
	if ((*line)[c] == '-' && (*line)[c + 1] == 'n' && !ft_strcmp("echo", arr->cmd))
	{
		if ((*line)[c + 2] == 'n' || (*line)[c + 2] == ' ' || (*line)[c + 2] == '|' || (*line)[c + 2] == '>' || (*line)[c + 2] == '<')
		{
			arr->echo_nflag = 1;
			(*line) += 2;
			while (**line == 'n')
				(*line)++;
		}
	}
	else
		arr->echo_nflag = 0;
}



void ft_char(char **line, char **l)
{
	int i;
	char *s;

	i = 0;
	ft_set(&s);
	while (**line != '\'' && **line != '\"' && **line != '\0' && **line != ' ' && **line != '$' && **line != '>' && **line != '<')
	{
		s = ft_realloc(s);
		s[i] = **line;
		i++;
		(*line)++;
	}
	//if (**line == '~')
//	printf("X\n");
	if (s)
	{
		s[i] = '\0';
		ft_strcat(l, &s);
	}
}



char *ft_parsing_cmd(char **line, t_data *data, t_cdata *cdata)
{
	char *gen;
	int i;

	i = 0;
	gen = (char*)malloc(sizeof(char) * 0);
	ft_memset(gen, 0, sizeof(gen));
	ft_skip_space(line);
//	printf("%c\n", **line);
//	printf("GEN STR_2 %s\n", gen);
	while (**line != '\0' && **line != ' ')// && **line != '|')
	{
		if (**line == '$')
		{
		//	printf("A\n");
			i += ft_path_parsing(line, &gen, data, cdata) + 1;
		//	(*line)--;
		//	printf("B %c\n", **line);
			printf("P GEN %s\n", gen);
		//	printf("I %d\n", i);
			(*line)--;
		}
		
	//	printf("%c\n", **line);
		if (**line != '\'' &&  **line != '\"' && **line != '\0' && **line != ' ' && **line != '|' && **line != '$' && **line != '>' && **line != '<')//?pars 1 cmd between ' and "
		{
		//	printf("L %c\n", **line)
			gen = ft_realloc(gen);
		//	printf("GEN_5 STR %s\n", gen);
			gen[i] = **line;
			i++;
			gen[i] = '\0';
		}

		if (**line == '|' && i == 0){
			gen = ft_realloc(gen);
			gen[i] = **line;
			i++;
			gen[i] = '\0';
		//	(*line)--;
		}
		
		else if (**line == '\'')
		{
			ft_quote(line, &gen);
		//	printf("I %d\n", i);
		//	printf("DB %s\n", gen);
		//	printf("LINE %c\n", **line);
			i = ft_strlen(gen);
			(*line)--;
		}
		else if (**line == '\"')
		{
			ft_db_quote(line, &gen, data, cdata);
			i = ft_strlen(gen);
			
			(*line)--;
		}
		else if (**line == '\0' || **line == ' ' || **line == '|' || **line == '>' || **line == '<')
			break;
		(*line)++;
	//	printf("GEN STR %s\n", gen);
	}
	printf("PR GEN %s\n", gen);
	gen = ft_realloc(gen);
	gen[i] = '\0';
	printf("GEN %s\n", gen);
	return (gen);
}

void ft_parsing_arg(char **line, t_data *data, t_cdata *cdata)
{
	t_arg *tm = NULL;
	t_arg	*tm1 = NULL;
	//t_arg *ar = NULL;
	char *l = NULL;
	
	while (**line != '\0' && !(line[0][0] == '|'))// && line[0][1] != '|'))
	{
		ft_set(&l);
	//	printf("C %c\n", **line);
		while (**line != ' ' && **line != '\0')
		{
		//	printf("6\n");
		if (**line == '~')
		{
			(*line)++;
			if (**line == ' ' || **line == '|' || **line == '>' || **line == '<' || **line == '\0' || **line == '/')
			{
				l = ft_search_in_envp_l(data, "HOME", cdata);
				ft_path_parsing(line, &l, data, cdata);
				arr->home_cd = 1;
			}
			else
				(*line)--;
		}
			ft_quote(line, &l);
		//	printf("7\n");
			ft_char(line, &l);
		//	printf("8\n");
		//	printf("A_CH %c\n", **line);
			ft_db_quote(line, &l, data, cdata);
		//	printf("9\n");
		
		if (**line == '$') 
		{
			ft_path_parsing(line, &l, data, cdata);
		//	printf("CHAR %c\n", **line);
		}
		//	printf("10\n");
			ft_parsing_redirect(line, data, cdata);
		}
	//	printf("L %s\n", l);
		if (ft_strlen(l) != 0 && (**line == ' ' || **line == '\0'))
		{
			tm1 = ft_argnew(l, tm);
			arr->arg = ft_arg_next(arr->arg, tm1);
			tm = tm1;
		}
		if (**line != '\0')
			(*line)++;
		
	}
//	printf("A %s\n", arr->arg->content);
/*	while (arr->red != NULL)
	{
		printf("RED LIST %s\n", arr->red->content);
		arr->red = arr->red->prev;
	}*/

	
}

void ft_parsing_post_cmd(char **line, t_data *data, t_cdata *cdata)
{
//	arr->red = NULL;
//	arr->arg = NULL;
//	printf("TUT\n");
//	if (arr->red != NULL)
//				printf("HAVE RED_5\n");
	ft_parsing_redirect(line, data, cdata);
//	printf("2\n");
//	if (arr->red != NULL)
//				printf("HAVE RED_6\n");
	ft_parsing_flag(line);
//	printf("3\n");
	ft_skip_space(line);
//	printf("4\n");
	ft_parsing_arg(line, data, cdata);
//	printf("5\n");
	ft_skip_space(line);
}

int ft_count_arg(t_arg *som)
{
	t_arg	*tmp;
	int i;

	i = 0;
	tmp = NULL;
	tmp = som;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	//printf("3\n");
	return (i);
}

void	ft_list_to_arr()
{
	int i;
	//int j;
	int k = 1;
	
//	printf("1\n");
//	printf("4 %p\n", arr);
	i = ft_count_arg(arr->arg);
//	printf("I %d\n", i);
//	printf("2\n");
//	j = ft_count_arg(arr->red);
	arr->fin = (char**)malloc(sizeof(char*) * i  + 2);
	
//	printf("L_A\n");
//	printf("A_FIN_CMD %s\n", arr->cmd);
	arr->fin[0] = (char*)malloc(sizeof(char) * ft_strlen(arr->cmd));
	ft_memset(arr->fin[0], 0, sizeof(arr->fin[0]));

	//printf("ARR_CMD %s\n", arr->cmd);
	ft_strcat(&arr->fin[0], &arr->cmd);
	//printf("FIN[0] %s\n", arr->fin[0]);
	while (k < i + 1)
	{
		arr->fin[k] = (char*)malloc(sizeof(char) * ft_strlen(arr->arg->content));
		ft_memset(arr->fin[k], 0, sizeof(arr->fin[k]));
		ft_strcat(&arr->fin[k], &arr->arg->content);
		k++;
		arr->arg = arr->arg->next;
	}
//	printf("FI %s\n", arr->fin[1]);
/*	while (k < i + j + 1)
	{
		arr->fin[k] = (char*)malloc(sizeof(char) * ft_strlen(arr->red->content));
		ft_strcat(&arr->fin[k], &arr->red->content);
		k++;
		arr->red = arr->red->next;
	}*/
	arr->fin[i+1] = NULL;
	while (arr->fin[i] != NULL)
	{
		printf("FIN0 %s %d\n", arr->fin[i], i);
		i++;
	}
}

void ft_line_parsing(char *line, t_cdata *cdata, char **envp, t_envlist ** head)
{
	t_list *tmp = NULL;
	t_list *tmp1 = NULL;
	t_data *data;
	t_list	*test;
//	char *some = NULL;

	while (*line != '\0')//| && *line != '|')
	{
		data = ft_datanew(envp, *head);
		ft_skip_space(&line);
			tmp1 = ft_lstnew(tmp, cdata);
		//	printf("A\n");
		//	printf("B\n");
			arr = ft_lst_next(arr, tmp1);
			ft_parsing_redirect(&line, data, cdata);
		//	if (arr->red != NULL)
		//		printf("HAVE RED_2\n");
		//	printf("LINE %c\n", *line);
			arr->cmd = ft_parsing_cmd(&line, data, cdata);
			tmp = tmp1;
			ft_skip_space(&line);
		//	if (arr->red != NULL)
		//		printf("HAVE RED_3\n");
		//	printf("B\n");
			if (*line != '\0')
				ft_parsing_post_cmd(&line, data, cdata);
		//	if (arr->red != NULL)
		//		printf("HAVE RED_4\n");
		//	printf("A\n");
	//	}
		if (*line != '\0' && line[0] == '|' && line[1] != '|' && ft_strcmp(arr->cmd, "|") != 0)
		{
			line += 1;
			ft_skip_space(&line);
			arr->pipe = 1;
			arr->also->num_pipe += 1;
		}
		ft_list_to_arr();                     //!!!!!!!нужно
	//	printf("ARR_CMD %s, ARR_PIPE %d\n", arr->cmd, arr->pipe);
		if (arr->pipe == 1)
			arr = arr->next;
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	}
	if (arr != NULL)
	{
		printf("PA %p\n", arr);
		printf("TEST %s\n", arr->cmd);
	}
	while (arr != NULL)
	{
		int i = 0;
		printf("CMD %s\n", arr->cmd);
		printf("NFLAG %d\n", arr->echo_nflag);
		printf("NUM_RED %d\n", arr->num_red);
		printf("PIPE %d\n", arr->pipe);
		printf("NUM_PIPE %d\n", arr->also->num_pipe);
	/*	while (arr->arg != NULL)
		{
			printf("ARR %s\n", arr->arg->content);
			arr->arg = arr->arg->next;
		}*/
		if (arr->red != NULL)
			printf("FIRST RED  %s\n", arr->red->content);
		/*while (arr->red != NULL)
		{
			printf("RED %s\n", arr->red->content);
			arr->red = arr->red->next;
		}*/
		while (arr->fin[i])
		{
			printf("FIN1 %s\n", arr->fin[i]);
			i++;
		}
		if (arr->next != NULL)
			printf("P %p\n", arr->next);
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		if (arr->prev != NULL)
		{
			tmp = arr;
			arr = arr->prev;
			arr->next = tmp;
		}
		else
			break;
	//	arr = arr->next;
	}
	if (arr != NULL)
		printf("POINTER %p\n", arr->next);
	else
		printf("NONE ARGS\n");
	//printf("P_A %p\n", arr->next->arg);
}

