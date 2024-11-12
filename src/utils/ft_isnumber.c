/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:55:06 by glajara-          #+#    #+#             */
/*   Updated: 2024/11/12 18:55:07 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

// Returns true if 'c' is a number. Otherwise, returns false.
bool	ft_isnumber(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}
