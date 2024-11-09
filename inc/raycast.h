#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3d.h"
# include "raycast_private.h"

void    raycast_position(t_cub *c);
void	init_ray(t_cub *c, t_raycast *r, double cam);

#endif