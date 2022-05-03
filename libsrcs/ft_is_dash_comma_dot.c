/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_dash_comma_dot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:16:07 by tshimoda          #+#    #+#             */
/*   Updated: 2022/03/21 12:37:30 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_dash_comma_dot(char c)
{
	if (c == '-' || c == ',' || c == '.')
		return (1);
	return (0);
}
