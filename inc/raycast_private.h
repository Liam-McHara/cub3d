#ifndef RAYCAST_PRIVATE_H
# define RAYCAST_PRIVATE_H

# include "vec2.h"

typedef struct s_raycast
{
	int			hit;
	int			side;
	t_vec2_d	raydir;
	t_vec2_i	map_pos;
	t_vec2_d	side_dist;
	t_vec2_d	delta_dist;
	double		wall_dist;
	double		wall;
	double		cam;
	t_vec2_i	step;
	int			line_height;
	int			line_start;
	int			line_end;
}	t_raycast;

void	draw_line(int x, t_raycast *r, t_cub *c);

#endif