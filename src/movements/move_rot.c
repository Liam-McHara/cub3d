/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferre-m <eferre-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:46:15 by eferre-m          #+#    #+#             */
/*   Updated: 2024/11/12 18:46:19 by eferre-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "movements.h"

static void	vector_rotate(t_matrix *rotation, t_vec2_d *vector)
{
	double	vector_x;

	vector_x = vector->x;
	vector->x = vector_x * rotation->a + vector->y * rotation->b;
	vector->y = vector_x * rotation->c + vector->y * rotation->d;
}

void	rot_player(t_cub *c, double angle)
{
	t_player	*p;
	float		dt;
	t_matrix	rotation;

	p = &c->player;
	dt = c->mlx->delta_time;
	rotation.a = cos(dt * angle);
	rotation.b = sin(dt * angle);
	rotation.c = -sin(dt * angle);
	rotation.d = cos(dt * angle);
	vector_rotate(&rotation, &p->dir);
	vector_rotate(&rotation, &p->plane);
}

void	mouse_rotation(t_cub *c)
{
	t_vec2_i	mouse_pos;

	mlx_get_mouse_pos(c->mlx, &mouse_pos.x, &mouse_pos.y);
	rot_player(c, -(mouse_pos.x - SCREEN_HEIGHT / 2) * MOUSE_ROT_SPEED);
	mlx_set_mouse_pos(c->mlx, SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2);
}
