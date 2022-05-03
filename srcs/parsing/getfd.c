/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:42:54 by adubeau           #+#    #+#             */
/*   Updated: 2022/04/30 16:34:26 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include <string.h>

int		get_fdI(t_node *current, int i, int j)
{

	int fd;
	char *file;

	fd = 0;
	while (current->value[i])
	{
		if (current->value[i] == ('<'))
			if (current->value[i + 1] != '<')
			{
				while (!(ft_isalnum(current->value[i])))
					i++;
				while (ft_isalnum(current->value[i++]))
					j++;
				file = ft_substr(current->value, i-j, j);
				fd = open(file, O_RDONLY);
			}
		i++;
	}
	return (fd);
}
int	get_fdO(t_node *current, int i, int j)
{
	int k;
	int fd;
	char *file;

	write(1, current->value, ft_strlen(current->value));
	while (current->value[i])
	{
		if (current->value[i] == '>')
		{
			k = i - 1;
			while (current->value[i] == ' ' || current->value[i] == '>')
				i++;
			while (current->value[i] && current->value[i++] != ' ')
				j++;
			file = ft_substr(current->value, i - j - 1, j);
			if (ft_is_present('/', file))
			{
				current->value = "";
				printf("%s: No such file or directory\n", file);
				return (1);
			}
			printf("\nfile:%s\n", file);
			current->value = ft_strjoin(ft_substr(current->value, 0, k), (current->value + i - 1));
			printf("current value:%s\n", current->value);
			if (current->type == 'c')
				fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0777);
			else
				fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0777);
		}
		i++;
	}
	return (fd);
}