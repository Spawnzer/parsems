/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getvar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:42:54 by adubeau           #+#    #+#             */
/*   Updated: 2022/05/21 13:08:58 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ms_expand(char *str, t_node *current, int i)
{
	int		j;
	char	*tmp;
	char	*var;
	char	*tmp1;

	j = 0;
	while (str[i + j] && str[i + j] != ' ' && str[i + j] != '$' \
			&& str[i + j] != '\'' && str[i + j] != '"')
		j++;
	tmp = ft_substr(str, 0, i - 1);
	if (str[i] == '?')
		var = ft_itoa(get_minishell()->exit_nb);
	else
	{
		tmp1 = ft_substr(str, i, j);
		var = env_var_get_value(tmp1, j);
		free(tmp1);
	}
	if (var == NULL) {
		free(current->value);
		current->value = ft_strjoin(tmp, &str[i + j]);
	}
	else
	{
		free(current->value);
		current->value = ft_strjoin(tmp, var);
		free(tmp);
		tmp = ft_strdup(current->value);
		free(current->value);
		current->value = ft_strjoin(tmp, &str[i + j]);
	}
	free(tmp);
}

void	get_var(char *str, t_node *current, int quote, int i)
{
	int	j;
	//char *tmp;

	j = 0;
	current->value = ft_strdup(str);
	/*if (ft_strlen(str) == 0)
		return (NULL);*/
	while (str[++i])
	{
		if (str[i] == '\'')
		{
			quote *= -1;
			i++;
		}
		else if (current->value[i] == '$' && current->value[i++] && quote > 0)
		{
			free(current->value);
			ms_expand(current->value, current, i);
			printf("current->value = %s\n", current->value);
			get_var(current->value, current, quote, i - 1);
			//free(tmp);
		}
	}
}
