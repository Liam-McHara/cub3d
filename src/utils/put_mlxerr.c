/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_mlxerr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:00:37 by glajara-          #+#    #+#             */
/*   Updated: 2024/11/12 19:00:38 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"			// ft_putendl_fd, ERROR_STR
#include <unistd.h>			// STDERR_FILENO
#include <stdlib.h>			// EXIT_FAILURE
#include "MLX42.h"			// mlx_strerror, mlx_errno 

// Prints "Error\n" followed by 'errmsg', semicolon and a MLX error message.
// Returns EXIT_FAILURE.
int	put_mlxerr(const char *errmsg)
{
	ft_putendl_fd(ERROR_STR, STDERR_FILENO);
	ft_putstr_fd(errmsg, STDERR_FILENO);
	ft_putstr_fd(" : ", STDERR_FILENO);
	ft_putendl_fd(mlx_strerror(mlx_errno), STDERR_FILENO);
	return (EXIT_FAILURE);
}
