#include "map.h"

// Returns the type of the map tile at 'coord'.
char	map_check(t_map *m, t_coord_d *coord)
{
	char	*line;

	line = m->data[(int)coord->y];
	return (line[(int)coord->x]);
}
