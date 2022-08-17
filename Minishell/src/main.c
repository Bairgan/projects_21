#include "../include/minishell.h"


void ft_handler(int sig) //handler for signals
{
	printf("> "); //!nice but it saved in history
	// printf(" Handle signal number %d\n", sig);
	// rl_replace_line(">", 0);
	//rl_redisplay();
	// printf(" Handle signal number %d, lastpid [%d]\n", sig, arr->also->last_pid);
	if(sig == SIGINT)
 	{
		if(arr)
		kill(arr->also->last_pid, SIGINT);	//kill child proc with CTRL-C
	}

}

int start_builtin(t_list *ptr, t_envlist *head, t_cdata *cdata, int p)//запуск встроеных ф.
{

	if((ft_strcmp(ptr->cmd, "echo")) == 0) //ECHO
		ft_echo(ptr, head, p);
    if(ft_strncmp(ptr->cmd, "env", 3) == 0) // ENV распечатать переменные окружения
		ft_env(head, p);
	if(ft_strncmp(ptr->cmd, "pwd", 3) == 0) //PWD вывести текущий рабочий каталог
		ft_pwd(head, p);
	if(ft_strcmp(ptr->cmd, "cd") == 0)
		ft_cd(ptr, head, cdata);
    if(ft_strcmp(ptr->cmd, "export") == 0) //! сделать для пайпа
		ft_export(ptr, head, cdata, 0);
    if(ft_strcmp(ptr->cmd, "unset") == 0)
		ft_unset(arr, head, cdata);
	if(ft_strcmp(ptr->cmd, "<<") == 0)
		ft_heredoc(ptr, head, cdata, "STOP");//!make delimiter
	if(ft_strcmp(ptr->cmd, "exit") == 0)
		exit(1);
//	printf("V\n");
	return(0);
}

//sent to error.c
int	ft_syntax_error_check_2(t_list *ptr)
{

	//!не могу доделать, непонятно что с парсингом

	t_list *tmp;
	int i;

	tmp = ptr;
	i = 0;
	while(tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}

	printf("ErErErErErErErErErErErErErErErErErErErEr[ Pipes [%d]  Nodes [%d]    ]  \n", ptr->also->num_pipe, i);
	if(i - ptr->also->num_pipe == 1)
		{
			printf("Fucking Error\n");

		}
	return (0);
}



int ft_do_smthng(char **envp, t_envlist * head, t_cdata *cdata)
{
	int i = 0;
//	printf("A\n");
//	printf("A.2 %s\n", arr->cmd);
	i = check_builtin(arr->cmd);
//	printf("B\n");
//	if (arr->red != NULL)
//	{
//		printf("ARR->RED %s\n", arr->red->content);
//	}
	if (i == 1 && arr->pipe == 0)
		{
		//	
			start_builtin(arr, head, cdata, 0);//!
		//	printf("C_0\n");
			return (0);
		}
	//	if (arr == NULL)
	//		printf("ARR IS NONE\n");
	printf("DO-->[%s]\n", arr->cmd);
	if ((i == 0) && arr->pipe == 0)
		{
			ft_start_ext_cmd(arr, head, envp, cdata);
		}
	if(arr->pipe == 1)//если есть пайп, запускаем пайп
		{
				printf("HAVE PIPE\n");
				//!chek line!!
				if(ft_syntax_error_check_2(arr) == 1)
				{
					printf("Minishell: syntax error near unexpected token `newline'\n");
					return(1);
				}
				ft_pipe(envp, head, cdata);
				return(0);
		}
	return (0);
}



int lsh_execute_r() //это я пока не знаю зачем
{
	return (1);
}
/*

		line = readline("Minishell:> "); / надо сделать как в баше стоку запроса?
*/


void lsh_loop(char **envp)
{
	char *line;
	//t_data *data;
	t_envlist env_list;//список для хренения переменных env
	t_envlist * head;//указатель на головной элемент
	t_cdata cdata;
    int status = 1;

    cdata.my_home = NULL;
    cdata.my_oldpwd = NULL;
	cdata.num_pipe = 0;
    cdata.my_pwd = NULL;
	cdata.exit_stat = 0;
	cdata.last_pid = -777;
	//arr->cdatptr = &cdata; //save ptr to cdata in 1 list of arr for global usage

	head = &env_list;

	init_list(head);//инницаилизация 1 эелемента кольцевогог списка, когда next \ prev  указывают на него же
	head = ft_env_parsing(head, envp);//парсим envp, в закольцованный список
	//ft_cd_store_parsing(&cdata, head); //save some useful env for cd,

    while (status)
	{
	//	printf("E\n");
		ft_cd_store_parsing(&cdata, head); //save some useful env for cd,
		printf(".......DEBUG.......Last procc exit status (macros)[%d], real[%d]\n", ft_exit_status_check(&cdata), cdata.exit_stat);//!del
		line = lsh_read_line();
		if (line == NULL)//Was intered CTRL-D / EOF - EXIT\n"
			{
				printf("Was entered CTRL-D / EOF - EXIT\n");//!del
				exit(0);
			}
		if (line[0] == '\0')//EMPTY STRING\n
			{
				printf("EMPTY STRING\n");//!del
				continue;
			}
	//	data = ft_datanew(envp);
		ft_line_parsing(line, &cdata, envp, &head);
		printf("BETWEEN PARS_AND_TDSM\n");//!del
		// printf("---------------------------------PARSING--------------------------\n");
		// printf("cmd [%s], arg [%s], red [%s], fin1 [%s]\n", arr->cmd, arr->arg->content, arr->red->content, arr->fin[1]);
		// printf("---------------------------------PARSING--------------------------\n");
	//	printf("A.0 %s\n", arr->cmd);
		ft_do_smthng(envp, head, &cdata);
	//	printf("A\n");
		status = lsh_execute();
	//	printf("B\n");
		unlink(".tmpfile");//del tmpfile
	//	printf("C\n");
		arr = NULL;
	//	printf("D\n");
	//	rl_on_new_line();

	//	free(line);
	}
	/*char *sg;
	FILE *file = fopen(history_get, "r+");
	fgets(sg, 255, file);
	printf("HISTORY %s\n", sg);*/
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	//struct sigaction	sa; //for signals

	//sa.sa_handler = &ft_handler;
	//sigaction (SIGINT, &sa, NULL); //hadle ctrl-c
	//sigaction (SIGQUIT, &sa, NULL); //handle ctrl-\ (quit)

	//rl_catch_signals = 0;//rline wouldnot catch a signals, no ^c in line

	if (signal(SIGQUIT, ft_handler) == SIG_ERR) {
    	printf("failed to register interrupts with kernel\n");
  	}
	// if (signal(SIGINT, ft_handler) == SIG_ERR) { //hadlne CTRL-C
    // 	printf("failed to register interrupts with kernel\n");
  	// }

    lsh_loop(envp);

    return(0);
	//return EXIT_SUCCESS;
}
