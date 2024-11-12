#include <stdlib.h>

// Frees the map's data.
void	map_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}
