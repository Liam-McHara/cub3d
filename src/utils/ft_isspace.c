/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:55:11 by glajara-          #+#    #+#             */
/*   Updated: 2024/11/12 18:55:13 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>			// bool: true, false

// Returns true if 'c' is a white-space character. Ohterwise, returns false.
bool	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (true);
	return (false);
}
