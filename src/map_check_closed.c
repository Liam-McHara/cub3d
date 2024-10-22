#include "map.h"			// t_vec2_d, FLOOR
#include "utils.h"			// p_malloc

// Checks a map tile. If the position is outside the map, or it's a floor
// at the border, prints an error and exits gracefully.
static void check_tile(char **map, int x, int y)
{
	int i;

	if (x < 0 || y < 0 || !map[x])
		exit(puterr(ERRMSG_MAP_BAD));
	i = 0;
	while (map[y][i] && i < x)
		++i;
	if (i != x)
		exit(puterr(ERRMSG_MAP_BAD));
	if (map[y][x] == FLOOR)
		if (x == 1 || map[y + 1] == NULL || y == 0 || !map[y][x + 1] == NULL)
			exit(puterr(ERRMSG_MAP_BAD));
}

static void flood(char **map, int x, int y)
{
	// recursive flood fill with the duplicate, turning FLOORs into WALLs to
	// prevent re-visiting tiles.
	check_tile(map, x, y);
	if (map[x][y] == WALL)
		return ;
	map[x][y] = WALL;
	flood(map, x + 1, y);
	flood(map, x - 1, y);
	flood(map, x, y + 1);
	flood(map, x, y - 1);
}

// Given a starting position, returns true if the 'map' is closed using the
// flood-field algorithmn. If the map is not closed, returns false.
void	map_check_closed(char **map, t_vec2_d *pos)
{
	char	**dup_map;
	int		i;

	i = 0;
	while (map[i])
		++i;
	dup_map = (char **)p_malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (map[i])
	{
		dup_map[i] = ft_strdup(map[i]);
		++i;
	}
	dup_map[i] = NULL;
	// duplicate map	
	flood(dup_map, (int)pos.x, (int) pos.y);
	// free duplicate
}
