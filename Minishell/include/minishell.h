#ifndef MINISHELL_H
# define MINISHELL_H

# include <errno.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft/libft.h"
# include <readline/readline.h> //для работы readline
# include <readline/history.h>
# include <sys/stat.h> //для stat()
# include <sys/types.h> //для waipid
# include <sys/wait.h> //для waipid
# include <errno.h>
# include <signal.h>
#include <fcntl.h>

typedef struct s_cdata
{
	char *my_pwd; //for cd
    char *my_oldpwd; //for cd
    char *my_home; //for cd
    int  exit_stat;//for $?
	//for pipe
	int  num_pipe; //pipe quantity
	int pid_num; //child proc. counter
	int *pid; //child proc arr
	int usedfd; //pipe counter
	struct s_envlist *head;
	//
	pid_t last_pid;//last forked child pid to kill

}t_cdata;

typedef struct s_list // основная структура для парсинга
{
	char *cmd;
	struct s_arg *arg;
	struct s_arg *red;//тут вроде редирект
	struct s_cdata *also;//copy of cdata
	char **fin;
	int echo_nflag;
	int home_cd;
	int num_red; //flag-> redirect quantity
    int pipe;
    //struct s_cdata *cdatptr; //pointer for global usage
	struct s_list *next;
	struct s_list *prev;

}		t_list;

t_list *arr;

typedef struct s_arg //структура для аргументов и редиректов
{
	char *content;
	struct s_arg *next;
	struct s_arg *prev;
}		t_arg;

typedef struct s_data //там зачемто валяется  envp?
{
	char **envp;
}		t_data;

typedef struct s_envlist //сюда парсим env
{
	char * name;
	char * value;
    struct s_envlist * next;
	struct s_envlist * prev;

} t_envlist;


t_envlist *ft_env_parsing(t_envlist* list_ptr, char **envp); //парсинг envp, в список записываем до = и от =, возвращает указатель на конец списка
t_envlist *ft_env_lstnew(char *name, char *value, t_envlist *prev); //добавление нового элемента списка для парсинга **envp
void ft_print_spis_end_env(t_envlist* list_end); //!распечатка списка envp, отладочная потом вероятно удалить

//!функции для работы с кольцевым списком
void	print_list(t_envlist * head);
void	print_back_list( t_envlist * head);
void	print_dbg(t_envlist * head);
void	insert_node(t_envlist * head, t_envlist * ins_node);
void	insert_before(t_envlist * node, t_envlist * ins_node);
void	insert_before_2(t_envlist * node, t_envlist * ins_node);
void	remove_node(t_envlist *node);
int		is_empty(t_envlist *head);
t_envlist	*push_front(t_envlist *head, char * name, char * value);
t_envlist	*push_back(t_envlist *head, char * name, char * value);
int		del_node(t_envlist *node);
int		pop_front(t_envlist *head);
int		pop_back(t_envlist *head);
void	init_list(t_envlist *head);
char	*ft_findpath(t_envlist *head);
char	*ft_search_envp_list(t_envlist * envlist, char *str);
//extcmd
int		ft_cmd_handler(t_envlist *head, char **envp, t_cdata * cdata);
int		ft_start_ext_cmd(t_list *arrptr, t_envlist *head, char **envp, t_cdata * cdata);
char	*ft_check_path(char **all_paths);
void	ft_strcat(char **dest, char **src);
char	*ft_path_handler(t_list *arrptr, t_envlist *head, t_cdata * cdata);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim_start(char const *s1, char const *set);
static char	*startcat(char const *str, char const *set);
static char	*endcat(char const *str);
//
int		ft_putstr_uni(char *s, int out);
void	ft_print_list_export(t_envlist * head);
int		check_builtin(char *cmd);
int		start_builtin(t_list *ptr, t_envlist *head, t_cdata *cdata, int p);
//pipe
char	*ft_check_path_pipe(char **all_paths, t_list * ptr);
char	*ft_findpath_pipe(t_envlist *head, t_list * ptr);
int ft_last_pipe(t_cdata *cdata, int ** arr, t_list *ptr, char ** envp);
int		ft_pipe(char **envp, t_envlist * head, t_cdata *cdata);
//redirect
int ft_redirect_to(t_list *ptr, t_cdata *cdata);
int ft_file_open(char *red_type, char *filename, t_cdata * cdata, t_list *ptr);
int ft_make_redirect(int type, t_list *ptr, t_cdata * cdata);
//error
int ft_sytax_error_check(t_arg *arg);
int ft_exit_status_check(t_cdata *cdata);
int ft_error_exit(int err, char *str1, t_cdata *cdata);
//builtin
int ft_echo(t_list *arr, t_envlist * head, int p);
int ft_cd(t_list *arr, t_envlist * head, t_cdata *dir);
int ft_cd_store_parsing(t_cdata *dir, t_envlist * head);
int ft_export(t_list *arr, t_envlist * head, t_cdata *cdata, int p);
int ft_dup_check(t_envlist * head, char *name);
int ft_change_in_envp(t_envlist * head, char *en, char *str);
int *ft_exp_parsing(t_envlist* head, char *str);
int ft_replace_val(t_envlist* head, char *name, char *val);
int ft_unset(t_list *arr, t_envlist * head, t_cdata *cdata);
int find_and_del_node(t_envlist * head, char * name);
int ft_env(t_envlist *head, int p);
int ft_pwd(t_envlist *head, int p);
int ft_heredoc(t_list *arr, t_envlist *head, t_cdata *cdata, char *delimiter);
//Лиза
//int *ft_memset_l(char *s, int c, size_t n);
char    *ft_strcpy(char *src);
char    **ft_split(char *s, char c);
int		ft_count_env_list(t_envlist * head);
char    *ft_osnova(char **s, char c);
char    *ft_search_in_envp_l(t_data *data, char *str, t_cdata *cdata);
char *ft_strdup(char *src);
char *ft_substr(char *s, unsigned int start, size_t len);
char *ft_parsing_cmd(char **line, t_data *data, t_cdata *cdata);
void ft_parsing_redirect(char **line, t_data *data, t_cdata *cdata);
char *lsh_read_line(void);
int	ft_strcmp(char *s1, char *s2);
int ft_strcmp_plus(const char *s1, const char *s2);
int lsh_execute();
int numc(char *s, char c);
size_t ft_func(char *s, unsigned int start, size_t len);
size_t ft_strlen(char *s);
t_arg	*ft_lstlast(t_arg *lst);
t_arg *ft_arg_next(t_arg *first, t_arg *next);
t_arg *ft_argnew(char *content, t_arg *prev);
t_data	*ft_datanew(char **e, t_envlist * head);
t_list *ft_lst_next(t_list *first, t_list *next);
t_list	*ft_lstnew(t_list *prev, t_cdata *cdata);
void	ft_lstadd_back(t_arg **lst, t_arg *new);
void	ft_lstadd_front(t_arg **lst, t_arg *new1);
void	ft_strcat(char **dest, char **src);
void *ft_clean(char **arr, size_t n);
void ft_line_parsing(char *line, t_cdata *cdata, char **envp, t_envlist ** head);
void ft_split_free(char **str);


#endif
