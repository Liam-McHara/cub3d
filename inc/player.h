#ifndef PLAYER_H
# define PLAYER_H

# include "vec2.h"		// t_vec2_d

typedef struct s_player
{
	t_vec2_d	pos;	// REMEMBER: add 0.5f to x & y
	t_vec2_d	dir;
	t_vec2_d	plane;	// TODO: Make constant ??
	double		time;
	double		oldtime;
	double		frametime;
	int			angle;
}	t_player;

#endif
