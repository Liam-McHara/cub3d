#include "assets.h"				// t_assets
#include "parse_private.h"		// parse_color, parse_texture, NORTH_T ... 
#include "utils.h"				// ft_strtrim, ft_strlen, get_next_line ...
#include "stdlib.h"				// free
#include "stdbool.h"			// true, false

// Checks if there are some assets missing, returning true in that case.
// Returns false otherwise.
static bool	missing_assets(t_assets *a)
{
	if (!(a->n) || !(a->s) || !(a->e) || !(a->w) || !(a->c_set) || !(a->f_set))
		return (true);
	else
		return (false);
}

// Reads the line and sets the appropiate asset.
// If the line is empty, does nothing.
// If the line is bad formatted, prints an error and exits gracefully.
static void	parse_asset_line(t_assets *a, const char *asset_line)
{
	char	*line;

	line = ft_strtrim(asset_line, BLANK_CHARS);
	if (ft_strlen(line) == 0)
		return (free(line));
	if (ft_strnstr(line, "NO ", 3))
		parse_texture(a, line + 3, NORTH_T);
	else if (ft_strnstr(line, "SO ", 3))
		parse_texture(a, line + 3, NORTH_T);
	else if (ft_strnstr(line, "WE ", 3))
		parse_texture(a, line + 3, WEST_T);
	else if (ft_strnstr(line, "EA ", 3))
		parse_texture(a, line + 3, EAST_T);
	else if (ft_strnstr(line, "F ", 2))
		parse_color(a, line + 2, FLOOR_C);
	else if (ft_strnstr(line, "C ", 2))
		parse_color(a, line + 2, CEILING_C);
	else
		exit(put_err(ERRMSG_MAP_BAD));
	free(line);
}

// Reads from the given file descriptor, line to line, parsing and setting the
// assets until all all of them have been set.
// If any error is found, prints a message and exits gracefully.
void	parse_assets(t_assets *a, int fd)
{
	char	*line;

	while (missing_assets(a))
	{
		line = get_next_line(fd);
		if (!line)
			exit(put_err(ERRMSG_MAP_BAD));
		parse_asset_line(a, line);
		free(line);
	}
}
