/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isinset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:59:34 by glajara-          #+#    #+#             */
/*   Updated: 2024/11/12 18:59:35 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>			// bool: true, false

// Returns true if 'c' is included in 'set'. Returns false otherwise.
bool	isinset(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (true);
		++set;
	}
	return (false);
}
