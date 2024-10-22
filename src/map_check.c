#include "map.h"	// TODO: change to vec2.h ?  OR REMOVE ?

// Returns the type of the map tile at 'pos'.
char	map_check(char **map, t_vec2_d *pos)
{
	char	*line;

	line = map[(int)pos->y];
	return (line[(int)pos->x]);
}
