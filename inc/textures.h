/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferre-m <eferre-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:57:54 by eferre-m          #+#    #+#             */
/*   Updated: 2024/11/12 18:57:56 by eferre-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# define TEXTURE_WIDTH 256
# define TEXTURE_HEIGHT 256

# include "vec2.h"
# include "cub3d.h"
# include "raycast.h"

typedef struct s_texture_d
{
	double		wall_x;
	double		step;
	t_vec2_i	txt_coord;
	double		txt_pos;
}	t_texture_d;

void	init_data_txt(t_raycast *r, t_cub *c, t_texture_d *txt_data);

#endif
