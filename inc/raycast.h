#ifndef RAYCAST_H
# define RAYCAST_H

# include "coord.h"
# include "cub3d.h"
# include "assets.h"

typedef struct s_raycast
{
	int			hit;
	int			side;
	t_coord_d	raydir;
	t_coord_i	map_pos;
	t_coord_d	side_dist;
	t_coord_d	delta_dist;
	double		wall_dist;
	double		wall;
	double		cam_x;
	t_coord_i	step;
	int			line_height;
	int			line_start;
	int			line_end;
}	t_raycast;

//void    raycast_position(t_cub *c);

#endif