/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferre-m <eferre-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:44:34 by eferre-m          #+#    #+#             */
/*   Updated: 2024/11/12 18:44:37 by eferre-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "assets.h"
#include "raycast.h"
#include <math.h>

//STEP 5 :  Calculate the Wall Height
static void	calcul_wall_height(t_raycast *r, t_cub *c)
{
	r->line_height = c->mlx->height / r->wall_dist;
	r->line_start = (-r->line_height / 2) + (c->mlx->height / 2);
	if (r->line_start < 0)
		r->line_start = 0;
	r->line_end = (r->line_height / 2) + (c->mlx->height / 2);
	if (r->line_end >= c->mlx->height)
		r->line_end = c->mlx->height - 1;
}

//STEP 4 : Performing Digital Differential Analysis
static void	calcul_wall_distance(t_raycast *r, char **map)
{
	r->hit = 0;
	while (r->hit == 0)
	{
		if (r->side_dist.x < r->side_dist.y)
		{
			r->side_dist.x += r->delta_dist.x;
			r->map_pos.x += r->step.x;
			r->side = 0;
		}
		else
		{
			r->side_dist.y += r->delta_dist.y;
			r->map_pos.y += r->step.y;
			r->side = 1;
		}
		if (map[r->map_pos.y][r->map_pos.x] == '1')
			r->hit = 1;
	}
	if (r->side == 0)
		r->wall_dist = r->side_dist.x - r->delta_dist.x;
	else
		r->wall_dist = r->side_dist.y - r->delta_dist.y;
}

/* This function handles the raycasting by initializing the
ray, calculating the step, calculating the wall distance, 
calculating the wall height and finally, updating the pixel map. */
void	raycast_position(t_cub *c)
{
	int			x;
	double		cam;
	t_raycast	r;

	x = 0;
	while (x < c->mlx->width)
	{
		cam = 2.0 * x / (double)c->mlx->width - 1.0;
		init_ray(c, &r, cam);
		calcul_wall_distance(&r, c->map);
		calcul_wall_height(&r, c);
		draw_cub(x, &r, c);
		x++;
	}
}
