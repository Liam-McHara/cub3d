/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_malloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:00:16 by glajara-          #+#    #+#             */
/*   Updated: 2024/11/12 19:00:19 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>		// malloc
#include "utils.h"		// put_syserr

void	*p_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exit(put_syserr(ERRMSG_MEMORY));
	return (ptr);
}
