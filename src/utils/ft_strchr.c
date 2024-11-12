/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:56:03 by glajara-          #+#    #+#             */
/*   Updated: 2024/11/12 18:56:04 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>				// NULL

// Returns a pointer to the first occurrence of 'c' in the string 's'.
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		++s;
	}
	if (c == '\0')
		return ((char *) s);
	return (NULL);
}
