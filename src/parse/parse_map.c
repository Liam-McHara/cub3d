/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:53:00 by glajara-          #+#    #+#             */
/*   Updated: 2024/11/12 18:53:01 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_private.h"	// set_player	
#include "utils.h"			// isinset, put_err, ft_strtrim, get_next_line ...
#include <stdbool.h>		// true, false
#include <unistd.h>			// close

// Processes 'mapline' assuming it is the y-th row of the map.
// It should make sure the are no invalid characters.
static void	process_map_line(char **map, t_player *player, char *mapline, int y)
{
	int	x;

	x = -1;
	while (mapline[++x])
	{
		if (!isinset(mapline[x], " 10NSWE"))
			exit(put_err(ERRMSG_MAP_CHAR));
		if (isinset(mapline[x], "NSWE"))
		{
			set_player(player, x, y, mapline[x]);
			mapline[x] = '0';
		}
	}
	map[y] = mapline;
}

// Parses 'line' as if part of the map, handling leading empty lines and
// detecting errors properly.
static void	parse_map_line(char **map, t_player *player, const char *line)
{
	static int	map_flag = false;
	static int	i = 0;
	char		*mapline;

	mapline = ft_strtrim(line, "\n");
	if (*mapline)
	{
		if (!map_flag)
			map_flag = true;
		process_map_line(map, player, mapline, i);
		++i;
	}
	else
	{
		free(mapline);
		if (map_flag)
			exit(put_err(ERRMSG_AFTERMAP));
	}
}

// Reads from the given file descriptor, line to line, checking its structure
// and parsing into 'cub' until EOF. At the end, 'fd' is closed.
// If any error is found, prints a message and exits gracefully.
void	parse_map(char **map, t_player *player, int fd)
{
	char	*line;

	line = get_next_line(fd);
	player->pos.x = -1;
	while (line)
	{
		parse_map_line(map, player, line);
		free(line);
		line = get_next_line(fd);
	}
	if (player->pos.x == -1)
		exit(put_err(ERRMSG_NO_PLAYER));
	map_check_closed(map, &player->pos);
	if (close(fd) == -1)
		exit(put_syserr(ERRMSG_MAP_CLOSE));
}
