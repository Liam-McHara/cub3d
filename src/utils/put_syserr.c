/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_syserr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:00:43 by glajara-          #+#    #+#             */
/*   Updated: 2024/11/12 19:00:43 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"			// ft_putendl_fd, ERROR_STR
#include <unistd.h>			// STDERR_FILENO
#include <stdlib.h>			// EXIT_FAILURE
#include <stdio.h>			// perror

// Prints "Error\n" followed by 'errmsg', semicolon and a system error message.
// Returns EXIT_FAILURE.
int	put_syserr(const char *errmsg)
{
	ft_putendl_fd(ERROR_STR, STDERR_FILENO);
	perror(errmsg);
	return (EXIT_FAILURE);
}
