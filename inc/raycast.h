/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferre-m <eferre-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:57:13 by eferre-m          #+#    #+#             */
/*   Updated: 2024/11/12 18:57:21 by eferre-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3d.h"
# include "raycast_private.h"

void	raycast_position(t_cub *c);
void	init_ray(t_cub *c, t_raycast *r, double cam);

#endif
