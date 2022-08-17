#include "../include/minishell.h"

// void	print_list(t_envlist * head);
// void	print_back_list( t_envlist * head);
// void	print_dbg(t_envlist * head);
// void	insert_node(t_envlist * head, t_envlist * ins_node);
// void	insert_before(t_envlist * node, t_envlist * ins_node);
// void	insert_before_2(t_envlist * node, t_envlist * ins_node);
// void	remove_node(t_envlist *node);
// int		is_empty(t_envlist *head);
// t_envlist	*push_front(t_envlist *head, int data);
// int		del_node(t_envlist *node);
// int		pop_front(t_envlist *head);
// int		pop_back(t_envlist *head);
// void	init_list(t_envlist *head)


void	print_list(t_envlist * head)
{
	t_envlist *ptr;
	ptr = head->next;
	while(ptr != head)//печатаем до тех пор пока птр не станет указывать на head, это значит мы дощли до последнго элемента перед LOCK (HEAD), где next указывает на head
	{
		printf("%s ", ptr->name);
		printf("=%s\n", ptr->value);
		ptr = ptr->next;
	}
	printf("\n");
}

void	print_back_list(t_envlist * head)
{
	t_envlist *ptr;
	ptr = head->prev;
	while(ptr != head)//печатаем до тех пор пока птр не станет указывать на head, это значит мы дощли до последнго элемента перед\после LOCK (HEAD), где next указывает на head
	{
		printf("%s ", ptr->name);
		printf("=%s ", ptr->value);
		ptr = ptr->prev;
	}
	printf("\n");
}

void	insert_node(t_envlist * node, t_envlist * ins_node) //функция вставки узла, после произвольного узла
{
	t_envlist * p1;//a -первый узел
	t_envlist * p2;//x - узел который надо вставить
	t_envlist * p3;//b - следующий узел
	p1 = node;
	p2 = ins_node;
	p3 = node->next;
	p2->next = p3;
	p2->prev = p1;
	p1->next = p2;
	p3->prev = p2;
}

void	insert_before(t_envlist * node, t_envlist * ins_node)
{
	t_envlist *p1;//b то что раньше было перед c
	t_envlist *p2;//z
	t_envlist *p3;//c  (перед чем вставить)

	p2 = ins_node;
	p3 = node;
	p1 = p3->prev;//разница только в этой строчке

	p2->next = p3;
	p2->prev = p1;
	p3->prev = p2;
	p1->next = p2;
}

void	insert_before_2(t_envlist * node, t_envlist * ins_node)//вставить узел до произвольного узла
{
	insert_node(node->prev, ins_node); //вставить до,по сути это вставить ПОСЛЕ предыдущего узла, от необходимого
}

t_envlist	*push_front(t_envlist *head, char * name, char * value)//добавить узел после головы (впереди)
{
	t_envlist *p;
	p = malloc(sizeof(t_envlist)); //маллочим память для 1 узла
	if(name != NULL)
        p->name = ft_strdup(name); //помещаем туда данные
	else
        p->name = NULL;
    if(value != NULL)    
        p->value = ft_strdup(value);
	else
        p->value = NULL;
    insert_node(head, p);
	return(p);
}

t_envlist	*push_back(t_envlist *head, char * name, char * value)//добавить узел сзади головы
{
	return (push_front(head->prev, name, value)); //отправляем предоследний элемент как тот, перед которым надо вставить узел
}

int		pop_front(t_envlist *head)//удалить следующий узел
{
	return(del_node(head->next));
}

int		pop_back(t_envlist *head)//удалить предыдузщий узел
{
	return(del_node(head->prev));
}


void	remove_node(t_envlist *node) //удалить узел из списка без возврата содержимого и без очистки памяти
{
		node->prev->next = node->next;
		node->next->prev = node->prev;

}

int		del_node(t_envlist *node)// удаление узла с возвратом значения пока не надо
{
	if (node->name != NULL)
        free(node->name);
    if (node->value != NULL)
        free(node->value);
	remove_node(node); // удаляем узел из списка,
	        //ret = node->data; //берем значение
	free(node); //чистим память от узла
	return (0);
}

int		is_empty(t_envlist *head)//проверка что лист пустой
{
		return (head->next == head && head->prev == head); //если ничего нет в функции то вернется 0, иначе 1
}

void	init_list(t_envlist *head)//для инициализации списка, в 1 элементе (замке),next prev указывают на самого себя
{
	head->next = head;
	head->prev = head;
	head->name = NULL;
	head->value = NULL;
}

void	list_clear(t_envlist *head)//очистка списка
{
	while(!(is_empty(head)))
		pop_front(head);
}