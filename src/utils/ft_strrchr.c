/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:57:55 by glajara-          #+#    #+#             */
/*   Updated: 2024/11/12 18:58:00 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"			// ft_strlen

// Returns a pointer to the last occurrence of 'c' in the string 's'.
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char) c)
			return ((char *) s + i);
		--i;
	}
	return (NULL);
}
