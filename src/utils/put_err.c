/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:00:29 by glajara-          #+#    #+#             */
/*   Updated: 2024/11/12 19:00:29 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <unistd.h>
#include <stdlib.h>

// Prints "Error\n" followed by the error message 'errmsg'.
// Returns EXIT_FAILURE.
int	put_err(const char *errmsg)
{
	ft_putendl_fd(ERROR_STR, STDERR_FILENO);
	ft_putendl_fd(errmsg, STDERR_FILENO);
	return (EXIT_FAILURE);
}
