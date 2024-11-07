#include "utils.h"			// isinset, put_err, ft_strtrim, get_next_line ...
#include "cub3d.h"
#include "map.h"
#include <stdbool.h>		// true, false
#include <unistd.h>			// close

#include <stdio.h>
#include <debug.h>

// Sets the 'player's position and direction.
// If the player is already set, prints an error message and exits gracefully.
static void	set_player(t_player *player, int x, int y, char dir)
{
	static bool	set_flag = false;

	if (set_flag)
		exit(put_err(ERRMSG_MULTIPLAYER));
	set_flag = true;
	player->pos.x = x + 0.5f;
	player->pos.y = y + 0.5f;
	if (dir == 'N')
	{
		player->dir = (t_vec2_d) {.x = 0, .y = -1};
		player->plane.x = 0.66;
		player->plane.y = 0;
	}
	else if (dir == 'S')
	{
		player->dir = (t_vec2_d) {.x = 0, .y = 1};
		player->plane.x = -0.66;
		player->plane.y = 0;
	}
	else if (dir == 'E')
	{
		player->dir = (t_vec2_d) {.x = 1, .y = 0};
		player->plane.x = 0;
		player->plane.y = -0.66;
	}
	else if (dir == 'W')
	{
		player->dir = (t_vec2_d) {.x = -1, .y = 0};
		player->plane.x = 0;
		player->plane.y = 0.66;
	}
}

// Parses 'line' as if part of the map, handling leading empty lines and
// detecting errors properly.
static void	parse_map_line(char **map, t_player *player, const char *line)
{
	static int	map_flag = false;
	static 		int	i = 0;
	int			j;
	char		*mapline;

	mapline = ft_strtrim(line, "\n");
	if (*mapline)
	{
		if (!map_flag)
			map_flag = true;
		j = 0;
		while (mapline[j])
		{
			if (!isinset(mapline[j], " 10NSWE"))
				exit(put_err(ERRMSG_MAP_CHAR));
			if (isinset(mapline[j], "NSWE"))
			{
				set_player(player, j, i, mapline[j]);
				mapline[j] = '0';
			}
			++j;
		}
		map[i] = mapline;
		++i;
	}
	else if (map_flag)
		exit(put_err(ERRMSG_AFTERMAP));
}

// Reads from the given file descriptor, line to line, checking its structure
// and parsing into 'cub' until EOF. At the end, 'fd' is closed.
// If any error is found, prints a message and exits gracefully.
void	parse_map(char **map, t_player *player, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		parse_map_line(map, player, line);
		free(line);
		line = get_next_line(fd);
	}
	//printf("PARSED MAP:\n");
	//put_map(map);
	map_check_closed(map, &player->pos);
	if (close(fd) == -1)
		exit(put_syserr(ERRMSG_MAP_CLOSE));
}
