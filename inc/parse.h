/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:17:20 by glajara-          #+#    #+#             */
/*   Updated: 2024/11/12 19:17:21 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "cub3d.h"			// t_cub

# ifndef MAX_WIDTH
#  define MAX_WIDTH 1024
# endif
# ifndef MAX_HEIGHT
#  define MAX_HEIGHT 1024
# endif

void	parse(const char *cubfile, t_cub *cub);

#endif
