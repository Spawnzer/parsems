/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:50:49 by adubeau           #+#    #+#             */
/*   Updated: 2022/05/19 11:52:23 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PARSING_H
# define PARSING_H

typedef struct s_node 
{
	char		*value;
	char		*eof;
	char		type;
	int			fd_i;
	int			fd_o;
	pid_t		id;
	int			pipe_end[2];
	struct s_node	*next;
	struct s_node	*prev;
}t_node;

void		ms_free_list(t_node *head);
int			ms_sanitize(char *input);
int			get_fd_i(t_node *current, char *value, int i, int j, int fd);
int			get_fd_o(t_node *current, char *value, int i, int j, int fd);
char		*get_var(char *str, int quote, int i);
void		*add_at_end(t_node **head, t_node *new);
char		get_type(char *str);
t_node		*new_node(char *str);
int			ms_parsing(int i);
int			ft_is_present(char c, char *sym);
char		**ms_split(char const *s, char sym, unsigned int i, unsigned int len);

#endif
