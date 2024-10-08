#include "utils.h"			// isinset, put_err, ft_strtrim, get_next_line ...
#include "cub3d.h"
#include "map.h"
#include <stdbool.h>		// true, false
#include <unistd.h>			// close

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
		player->dir = (t_vec2_d) {.x = 0, .y = -1};
	else if (dir == 'S')
		player->dir = (t_vec2_d) {.x = 0, .y = 1};
	else if (dir == 'E')
		player->dir = (t_vec2_d) {.x = 1, .y = 0};
	else if (dir == 'W')
		player->dir = (t_vec2_d) {.x = -1, .y = 0};
}

// Parses 'line' as if part of the map, handling leading empty lines and
// detecting errors properly.
static void	parse_map_line(t_cub *cub, const char *line)
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
				set_player(&cub->player, j, i, mapline[j]);
		}
		cub->map.data[i] = mapline;
		cub->map.data[++i] = NULL;
	}
	else if (map_flag)
		exit(put_err(ERRMSG_AFTERMAP));
}

// Reads from the given file descriptor, line to line, checking its structure
// and parsing into 'cub' until EOF. At the end, 'fd' is closed.
// If any error is found, prints a message and exits gracefully.
void	parse_map(t_cub *cub, int fd)
{
	char	*line;

	while ((line = get_next_line(fd)))
	{
		parse_map_line(cub, line);
		free(line);
	}
	if (!map_is_closed(&cub->map, &cub->player.pos))
		exit(put_err(ERRMSG_MAP_BAD));
	if (close(fd))
		exit(put_syserr(ERRMSG_MAP_CLOSE));
}
