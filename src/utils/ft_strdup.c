/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:56:14 by glajara-          #+#    #+#             */
/*   Updated: 2024/11/12 18:56:16 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"			// p_malloc, ft_strlen

// Returns a pointer to a new string which is a duplicate of the string s.
char	*ft_strdup(const char *s)
{
	char	*s2;
	size_t	len;
	int		i;

	len = ft_strlen(s);
	s2 = (char *)p_malloc(sizeof(char) * (len + 1));
	i = 0;
	while (s[i])
	{
		s2[i] = s[i];
		++i;
	}
	s2[i] = '\0';
	return (s2);
}
