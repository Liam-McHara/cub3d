/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:58:53 by glajara-          #+#    #+#             */
/*   Updated: 2024/11/12 18:58:55 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"				// ft_strlen, p_malloc

// Allocates (with malloc(3)) and returns a substring from the string ’s’.
// The substring begins at index ’start’ and is of maximum size ’len’.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	slen;
	size_t	strlen;

	if (!s)
		return (NULL);
	i = 0;
	slen = ft_strlen(s);
	while (start + i <= slen && s[start + i] && i < len)
		++i;
	strlen = i;
	str = (char *) p_malloc(sizeof(char) * (strlen + 1));
	i = 0;
	while (i < strlen)
	{
		str[i] = s[start + i];
		++i;
	}
	str[i] = '\0';
	return (str);
}
