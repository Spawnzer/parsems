#include "stdlib.h"
#include "unistd.h"
#include "stdio.h"

char    **ft_split(char const *s, char *sym);
int	ft_is_present(char c, char *sym);

struct node
{
	char 		*value;
	char		type;
	struct node	*next;
};

typedef struct node t_list;

t_list	*add_at_head(t_list **head, t_list *new)
{
	new->next = *head;
	*head = new;
	return new;
}

void	*add_at_end(t_list **head, t_list *new)
{
	t_list *tmp = *head;

	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;		
}
char	get_type(char *str, char *sym)
{
	if (ft_is_present('$', str))
		return 'v';
	
	if (str[0] == '|')
		return 'p';
	else if (str[0] == '"' || str[0] == '\'')
		return 'l';
	else if (str[0] == '<')
		if (str[1] == '<')
			return 'h';
		else
			return 'r';
	else
		return 'c';
}
t_list	*new_node(char *str, char *sym)
{
	t_list	*new = malloc(sizeof(t_list));
	new->value = str;
	new->type = get_type(str, sym);
	new->next = NULL;
}

void	printlist(t_list *head)
{
	t_list *tmp = head;

	while (tmp != NULL)
	{
		printf("Value:%s\n", tmp->value);
		printf("Type:%c\n", tmp->type);
		tmp = tmp->next;
	}
}

void	ft_to_do(t_list *head)
{
	t_list *tmp = head;

	while (tmp != NULL)
	{
		if(tmp->type == 'v')
			if (ft_is_present('=', tmp->value))
				printf("set variable %s to %s\n", tmp->value, tmp->next->value);
			else
				printf("expand variable with env_var_get_value %s\n", tmp->value);
		else if (tmp->type == '"')
			printf("Look inside %s to see if need to expand", tmp->value);
		tmp = tmp->next;
	}
	t_list *tmp1 = head;
	while (tmp1 != NULL)
	{
		if (tmp1->type == 'c')
			printf("execution of command %s\n", tmp1->value);
		else if (tmp1->type == 'p')
				printf("and pipe it into\n");
		else if (tmp1->type == 'r')
			printf("and redirect it into\n");
		else if (tmp1->type == 'h')
		{
			printf("do heredoc bs with %s\n", tmp1->next->value);
			tmp1 = tmp1->next;
		}
		tmp1 = tmp1->next;
	}
}

int main(int ac, char **av)
{
	t_list *list;
	t_list *tmp;
	char sym[4] = {'|', '<', '"', '\''}; 
	char **arg = ft_split(av[1], sym);
	int len = sizeof(arg)/sizeof(arg[0]);
	int i = 1;
	t_list *head = new_node(arg[0], sym);
	
	while(arg[i] != NULL)
	{
		list = new_node(arg[i], sym);
		add_at_end(&head, list);
		i++;
	}
	tmp = head;
	printlist(tmp);
	ft_to_do(head);
	printf ("%s\n", av[1]);	
}
