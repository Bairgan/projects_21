#include "../../include/minishell.h"

int ft_cd_store_parsing(t_cdata *cdata, t_envlist * head)
{
    char *str;
    str = NULL;
//	printf("F\n");
    if ((str = ft_search_envp_list(head, "HOME")) != NULL) //!malloc
        cdata->my_home = ft_strdup(str);//!malloc
    else
        cdata->my_home = NULL;
//	printf("G\n");
	ft_memset(str, 0, sizeof(str));
    if ((str = ft_search_envp_list(head, "PWD")) != NULL)
        cdata->my_pwd = ft_strdup(str);//!malloc
    else
        cdata->my_pwd = NULL;	
	ft_memset(str, 0, sizeof(str));
//	printf("H\n");
	if ((str = ft_search_envp_list(head, "OLDPWD")) != NULL)
	{
	//	printf("K\n");
        cdata->my_oldpwd = ft_strdup(str);//!malloc
	}
    else
	{
	//	printf("L\n");
        cdata->my_oldpwd = NULL;
	}
//	printf("I\n");
	free(str);
//	printf("J\n");
	return (0);		
}

int ft_change_in_envp(t_envlist * head, char *en, char *str)//changing value in list
{
	t_envlist * ptr;
	ptr = head->next; //1st element is LOCK
    printf("recieved in ft_change_in  [%s] [%s]\n", en, str);//!del
	while(ptr != head)
    {
        if(ft_strcmp(ptr->name, en) == 0)
            {
                
				ptr->value = ft_strdup(str);
				return (0);
            }

        ptr = ptr->next;
    }
	push_back(head, en, str);	 //adding, if no oldpwd in list
		
	return (0);
}

int ft_check_cd_arg(char **tmp)
{
	int i;
	int m;

	i = 0;
	m = 0;
	while (tmp != NULL && tmp[i] != NULL)
	{
		if (ft_strcmp(tmp[i], "-") == 0 || ft_strcmp(tmp[i], "--") == 0)
			m++;
		i++;
	}
	//printf("J\n");
	if (i > 1 && m > 0)
		return (0);
	return (1);
}

int ft_home_word_count(char *str)
{
	int i = 0;
	int j = 0;

	while (str[i])
	{
		if (str[i] == '/')
			j++;
		i++;
	}
	printf("J %d\n", j);
	return (j);
}

int ft_cd(t_list *arr_ptr, t_envlist * head, t_cdata *cdata)
{

	char * path;
	char * oldpwd_tmp;
	char ** tmp = NULL;
	char * str;
	int i = 0;
	char * pwd_tmp = NULL;
	path = NULL;
	
//	oldpwd_tmp = ft_search_envp_list(head, "PWD"); //!MALLOC
//	printf("SAVED PWD [%s]\n", oldpwd_tmp);
//	printf("MY_PWD %s\n", cdata->my_pwd);
	//if just -cd, make HOME -> current working dir 
//	printf("CD_FIN %s\n", arr->fin[1]);
	if (arr->fin[1] != NULL)
		tmp = ft_split(arr_ptr->fin[1], '/');
//	printf("DC\n");
	while (tmp == NULL || (tmp[i] != NULL && ft_check_cd_arg(tmp)))
	{
	//	printf("SA\n");
	//	printf("MY_PWD %s\n", cdata->my_pwd);
		ft_cd_store_parsing(cdata, head);
		
	//	printf("TMP[I] %s\n", tmp[i]);
		if (tmp == NULL || arr->home_cd == 1 || ft_strcmp(tmp[i], "--") == 0)
		{
			if ((chdir(cdata->my_home)) == 0)
			{
				ft_change_in_envp(head, "OLDPWD", cdata->my_pwd);
				ft_change_in_envp(head, "PWD", cdata->my_home);
				if (arr->home_cd == 1)
				{
					i += ft_home_word_count(cdata->my_home) - 1;
					arr->home_cd = 0;
				}
			}
			else
			{
				ft_error_exit(70, arr_ptr->fin[1], cdata);
				return(1);
			}
		//	printf("T[I} %s\n", tmp[i]);
		}
		else if (tmp != NULL || tmp[i] != NULL)
		{
			if (ft_strcmp(tmp[i], "-") != 0 && ft_strcmp(tmp[i], "..") != 0 && ft_strcmp(tmp[i], ".") != 0)
			{
				if ((chdir(tmp[i])) == 0)
				{
				//	printf("M\n");
					if (ft_strcmp(cdata->my_pwd, "/") != 0)
					{
					//	printf("T\n");
						pwd_tmp = ft_strjoin(cdata->my_pwd, "/");
						pwd_tmp = ft_strjoin(pwd_tmp, tmp[i]);
				//		printf("`tmp %s\n", pwd_tmp);
					}
					else
					{
						ft_strcat(&pwd_tmp, &tmp[i]);
						pwd_tmp = ft_strjoin(cdata->my_pwd, pwd_tmp);
					}
				//	printf("T[I] %s\n", tmp[i]);
					ft_change_in_envp(head, "OLDPWD", cdata->my_pwd);
					ft_change_in_envp(head, "PWD", pwd_tmp);
					free(pwd_tmp);
					//printf("B\n");
				}
				else
				{
					ft_error_exit(70, arr_ptr->fin[1], cdata);
					return(1);
				}
			}
			else if (ft_strcmp(tmp[i], "-") == 0)
			{
				if (chdir(cdata->my_oldpwd) == 0)
				{
					printf("%s\n", cdata->my_oldpwd);
					ft_change_in_envp(head, "OLDPWD", cdata->my_pwd);
					ft_change_in_envp(head, "PWD", cdata->my_oldpwd);
				}
				else
				{
					ft_error_exit(70, arr_ptr->fin[1], cdata);
					return(1);
				}
			}
			else if (ft_strcmp(tmp[i], "..") == 0)
			{
				if (chdir("..") == 0 && ft_strcmp(cdata->my_pwd, "/") != 0)
				{
					if (ft_strrchr(cdata->my_pwd, '/') != NULL)
					{
						if (ft_strcmp(cdata->my_pwd, ft_strrchr(cdata->my_pwd, '/')) != 0)
							pwd_tmp = ft_strtrim(cdata->my_pwd, ft_strrchr(cdata->my_pwd, '/') + 1);
						else
							pwd_tmp = ft_strtrim(cdata->my_pwd, ft_strrchr(cdata->my_pwd, '/') + 2);
						pwd_tmp[ft_strlen(pwd_tmp) - 1] = '\0';
					}
					ft_change_in_envp(head, "OLDPWD", cdata->my_pwd);
					ft_change_in_envp(head, "PWD", pwd_tmp);
					free(pwd_tmp);
				}
				else if (ft_strcmp(cdata->my_pwd, "/") == 0)
				{}
				else
				{
					ft_error_exit(70, arr_ptr->fin[1], cdata);
					return(1);
				}
			}
		}
	//	printf("H\n");
	//	printf("TMP[I] %s\n", tmp[i]);
		if (tmp == NULL || tmp[i] == NULL)
			break;
		else
			i++;
	//	printf("R\n");
	}
	//printf("C\n");
/*	if(arr_ptr->fin[1] == NULL || ft_strcmp(arr_ptr->fin[1], "~") == 0 || ft_strcmp(arr_ptr->fin[1], "--") == 0)
		{	
			printf("FIN_1 == 0\n");
			if ((chdir(cdata->my_home)) == 0)
			{
				printf("T\n");
				ft_change_in_envp(head, "OLDPWD", oldpwd_tmp);
				ft_change_in_envp(head, "PWD", cdata->my_home);
				//return (0); //need after debug
			}	
			else
			{
				free(oldpwd_tmp);	//perror("Minishell: cd: ");
				ft_error_exit(70, arr_ptr->fin[1], cdata);
				return(1);
			}
		}
	else if(arr_ptr->fin[1] != NULL)
	{
		if ((chdir(arr_ptr->fin[1])) == 0 || ft_strcmp(arr_ptr->fin[1], "-") == 0)//create new pwd
		{
			
			if(arr_ptr->fin[1][0] != '/')//if path t1/t2 need to + PWD
			{
				printf("H\n");
				printf("STRRCHR %s\n", ft_strrchr(cdata->my_pwd, '/'));
				if (ft_strcmp(arr_ptr->fin[1], "..") == 0)
				{
					if (ft_strrchr(cdata->my_pwd, '/') != NULL)
					{
						printf("LEN %zu\n", ft_strlen(ft_strrchr(cdata->my_pwd, '/')));
						pwd_tmp = ft_strtrim(cdata->my_pwd, ft_strrchr(cdata->my_pwd, '/') + 1);
						pwd_tmp[ft_strlen(pwd_tmp) - 1] = '\0';
						// if (ft_strcmp(pwd_tmp, "\0") == 0)
						// 	pwd_tmp = ft_strjoin(pwd_tmp, "/");
					}
					ft_change_in_envp(head, "OLDPWD", oldpwd_tmp);
					ft_change_in_envp(head, "PWD", pwd_tmp);
					free(pwd_tmp);
				}
				
				else if (ft_strcmp(arr_ptr->fin[1], "-") == 0 && ft_strcmp(cdata->my_pwd, cdata->my_oldpwd) != 0)
				{
					printf("OLD %s\n", cdata->my_oldpwd);
					printf("ZDES\n");
					chdir(cdata->my_oldpwd);
					ft_change_in_envp(head, "OLDPWD", cdata->my_pwd);
					ft_change_in_envp(head, "PWD", cdata->my_oldpwd);
				}
				else if (ft_strcmp(arr_ptr->fin[1], ".") != 0)
				{
					pwd_tmp = ft_strjoin(cdata->my_pwd, "/");
					pwd_tmp = ft_strjoin(pwd_tmp, arr_ptr->fin[1]);
					ft_change_in_envp(head, "OLDPWD", oldpwd_tmp);
					ft_change_in_envp(head, "PWD", pwd_tmp);
					free(pwd_tmp);
				}
				// ft_change_in_envp(head, "OLDPWD", oldpwd_tmp);
				// ft_change_in_envp(head, "PWD", pwd_tmp);
				
			}
			else
			{
				printf("G\n");
				ft_change_in_envp(head, "OLDPWD", oldpwd_tmp);
				printf("NEW PWD [%s]\n",arr_ptr->fin[1]);
				ft_change_in_envp(head, "PWD", arr_ptr->fin[1]);
			}
		}
		else
		{
			
			ft_error_exit(70, arr_ptr->fin[1], cdata);
			//free(pwd_tmp);
			//free(oldpwd_tmp);
			return(1);
		}
}*/

	//!Проблема с парсингом, не знаю как проверить если относительный путь

	// printf("*************************************************************************************\n");
	// printf("cd args: %s, %s\n", arr->fin[1], arr->fin[2]);
	// printf("current PWD - %s\n", ft_search_envp_list(head, "PWD"));	
	// printf("current OLDPWD - %s\n", ft_search_envp_list(head, "OLDPWD"));
	// printf("current HOME - %s\n", ft_search_envp_list(head, "HOME"));	
	// printf("my params [%s] [%s] [%s]\n",  cdata->my_home, cdata->my_oldpwd, cdata->my_pwd);
	
	
//	free(oldpwd_tmp);
    return (0);
}