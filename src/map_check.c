#include "map.h"

// Returns the type of the map tile at 'pos'.
char	map_check(t_map *m, t_vec2_d *pos)
{
	char	*line;

	line = m->data[(int)pos->y];
	return (line[(int)pos->x]);
}
