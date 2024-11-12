/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferre-m <eferre-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:55:29 by eferre-m          #+#    #+#             */
/*   Updated: 2024/11/12 18:55:32 by eferre-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "cub3d.h"

# define MAP_PLAYER_COLOR 0x00FF00FF
# define MAP_F_COLOR 0x000000FF
# define MAP_W_COLOR 0xFFFFFFFF
# define MAP_PXL_SIZE 6

void	minimap(t_cub *c);

#endif
