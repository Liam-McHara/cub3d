/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferre-m <eferre-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:44:08 by eferre-m          #+#    #+#             */
/*   Updated: 2024/11/12 18:44:21 by eferre-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "assets.h"
#include "raycast.h"
#include <math.h>

//STEP 4 : Calculates the distance to the wall
static void	calcul_sidedist(t_raycast *r, t_cub *c)
{
	t_player	*p;

	p = &c->player;
	if (r->raydir.x < 0.0)
		r->side_dist.x = (p->pos.x - r->map_pos.x) * r->delta_dist.x;
	else
		r->side_dist.x = (r->map_pos.x + 1.0 - p->pos.x) * r->delta_dist.x;
	if (r->raydir.y < 0.0)
		r->side_dist.y = (p->pos.y - r->map_pos.y) * r->delta_dist.y;
	else
		r->side_dist.y = (r->map_pos.y + 1.0 - p->pos.y) * r->delta_dist.y;
}

//STEP 3: Calculate the step of the ray 
static void	calcul_step(t_raycast *r)
{
	if (r->raydir.x < 0.0)
		r->step.x = -1;
	else
		r->step.x = 1;
	if (r->raydir.y < 0.0)
		r->step.y = -1;
	else
		r->step.y = 1;
}

//STEP 2 : Calculating the Delta Distance
static void	init_delta_dist(t_vec2_d *raydir, t_vec2_d *delta_dist)
{
	if (raydir->x == 0.0)
		delta_dist->x = 1e30;
	else
		delta_dist->x = fabs(1 / raydir->x);
	if (raydir->y == 0.0)
		delta_dist->y = 1e30;
	else
		delta_dist->y = fabs(1 / raydir->y);
}

//STEP 1 : Calculate ray position and direction
void	ray_direction(t_raycast *r, t_player *player, double cam)
{
	r->raydir.x = player->dir.x + player->plane.x * cam;
	r->raydir.y = player->dir.y + player->plane.y * cam;
	r->map_pos.x = (int)player->pos.x;
	r->map_pos.y = (int)player->pos.y;
}

/*This function initializes the ray structure with the
necessary values to calculate the ray.*/
void	init_ray(t_cub *c, t_raycast *r, double cam)
{
	ray_direction(r, &c->player, cam);
	init_delta_dist(&r->raydir, &r->delta_dist);
	calcul_step(r);
	calcul_sidedist(r, c);
}
