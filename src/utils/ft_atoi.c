/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:54:28 by glajara-          #+#    #+#             */
/*   Updated: 2024/11/12 18:54:45 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"				// ft_isspace, ft_isnumber

// Converts the initial portion of 'str' to int.
int	ft_atoi(const char *str)
{
	int	n;
	int	sign;

	if (!*str)
		return (0);
	n = 0;
	sign = 1;
	while (*str && ft_isspace(*str))
		++str;
	while (*str && (*str == '-' || *str == '+'))
	{
		if (*str == -1)
			sign *= -1;
		++str;
	}
	while (*str && ft_isnumber(*str))
	{
		n *= 10;
		n += *str - '0';
		++str;
	}
	return (n * sign);
}
