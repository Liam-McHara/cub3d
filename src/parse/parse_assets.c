#include "assets.h"				// t_assets
#include "parse_private.h"		// parse_color, parse_texture, NORTH_T ... 
#include "utils.h"				// ft_strtrim, ft_strlen, get_next_line ...
#include "stdlib.h"				// free
#include <stdbool.h>			// bool: true, false

// Reads the line, sets the appropiate asset and returns true.
// If the line is empty, returns false.
// If the line is bad formatted, prints an error and exits gracefully.
static bool	parse_asset_line(t_assets *a, const char *asset_line)
{
	char	*line;

	line = ft_strtrim(asset_line, BLANK_CHARS);
	if (ft_strlen(line) == 0)
		return (free(line), false);
	if (ft_strnstr(line, "NO ", 3))
		parse_texture(a, line + 3, NORTH);
	else if (ft_strnstr(line, "SO ", 3))
		parse_texture(a, line + 3, SOUTH);
	else if (ft_strnstr(line, "WE ", 3))
		parse_texture(a, line + 3, WEST);
	else if (ft_strnstr(line, "EA ", 3))
		parse_texture(a, line + 3, EAST);
	else if (ft_strnstr(line, "F ", 2))
		parse_color(a, line + 2, C_FLOOR);
	else if (ft_strnstr(line, "C ", 2))
		parse_color(a, line + 2, C_CEILING);
	else
		exit(put_err(ERRMSG_MAP_BAD));
	free(line);
	return (true);
}

// Reads from the given file descriptor, line to line, parsing and setting the
// assets (6 in total).
// If any error is found, prints a message and exits gracefully.
void	parse_assets(t_assets *a, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (i < 6)
	{
		line = get_next_line(fd);
		if (!line)
			exit(put_err(ERRMSG_MAP_BAD));
		if (parse_asset_line(a, line))
			++i;
		free(line);
	}
}
