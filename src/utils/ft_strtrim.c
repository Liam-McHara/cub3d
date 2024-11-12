/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:58:12 by glajara-          #+#    #+#             */
/*   Updated: 2024/11/12 18:58:13 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"				// ft_strlen, p_malloc, isinset

// Allocates and returns a copy of 's1' with the characters specified in
// 'set' removed from the beginning and the end of the string.
char	*ft_strtrim(char const *s1, const char *set)
{
	char	*s2;
	int		len;

	while (*s1 && isinset(*s1, set))
		++s1;
	len = ft_strlen(s1);
	while (len > 0 && isinset(s1[len - 1], set))
		--len;
	s2 = (char *) p_malloc((len + 1) * sizeof(char));
	ft_memcpy(s2, s1, len + 1);
	s2[len] = '\0';
	return (s2);
}
