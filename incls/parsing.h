/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:50:49 by adubeau           #+#    #+#             */
/*   Updated: 2022/05/18 17:32:27 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "builtins.h"

#ifndef PARSING_H
# define PARSING_H

struct node 
{
	char		*value;
	char		*eof;
	char		type;
	int			fd_i;
	int			fd_o;
	pid_t		id;
	int			pipe_end[2];
	struct node	*next;
	struct node	*prev;
};

typedef struct node	t_node;

void		ms_free_list(struct node *head);
int			ms_sanitize(char *input);
char		check_qm(char *str, int i, int s, int d);
int			get_fd_i(t_node *current, char *value, int i, int j, int fd);
int			get_fd_o(t_node *current, char *value, int i, int j, int fd);
char		*get_var(char *str, int quote, int i);
t_node		*add_at_head(t_node **head, t_node *new);
void		*add_at_end(t_node **head, t_node *new);
char		get_type(char *str);
t_node		*new_node(char *str);
void		printlist(t_node *head);
int			ms_parsing(void);
int			ft_is_present(char c, char *sym);
char		**ms_split(char const *s, char sym);

#endif
