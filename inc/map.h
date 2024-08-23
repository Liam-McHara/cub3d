#ifndef MAP_H
# define MAP_H

# include "vec2.h"				// t_vec2_d
# include <stdbool.h>			// bool

typedef enum e_direction
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}	t_direction;

enum
{
	WALL = '1',
	FLOOR = '0',
	VOID = ' '
};

typedef struct s_map
{
	int		h;
	int		w;
	char	**data;
}	t_map;

char	map_check(t_map *m, t_vec2_d *pos);
bool	map_is_closed(t_map *m, t_vec2_d *pos);

#endif
