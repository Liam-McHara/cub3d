#ifndef PLAYER_H
# define PLAYER_H

# include "coord.h"

typedef struct s_player
{
	t_coord_d	pos;	// REMEMBER: add 0.5f to x & y
	t_coord_d	dir;
	t_coord_d	plane;	// TODO: Make constant ?? 
}	t_player;

#endif
