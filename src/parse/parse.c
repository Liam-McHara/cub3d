#include <cub3d.h>				// t_cub, t_map, t_assets, t_player, HEIGHT...
#include "MLX42.h"				// mlx_init 
#include "parse_private.h"		// parse_settings, parse_map
#include "utils.h"				// put_err, put_syserr
#include <fcntl.h>				// open
#include <unistd.h>				// close
#include <stdbool.h>			// bool: true, false

// Returns true if 'path' is a directory. Otherwise, returns false.
static bool	is_directory(const char *path)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

// Opens the .cub file 'cubfile' and returns its file descriptor.
// If it can't open the file, prints an error message and exits gracefully.
static int	open_cubfile(const char *cubfile)
{
	int	fd;

	if (is_directory(cubfile))
		exit(put_err("The provided path is a directory"));
	fd = open(cubfile, O_RDONLY);
	if (fd == -1)
		exit(put_syserr("Couldn't open map file"));
	return (fd);
}

// Allocates memory needed to store the map.
static void	init_map(t_cub *cub)
{
	int	i;

	cub->map = (char **)p_malloc(sizeof(char *) * (HEIGHT + 1));
	i = -1;
	while (++i <= HEIGHT)
		cub->map[i] = NULL;
}

#include <stdio.h>

// Loads the .cub file and parses its content, leaving the t_cub object
// ready-to-use.
// If any error is found, prints an error message and exits gracefully.
void	parse(const char *cubfile, t_cub *cub)
{
	int		fd;

	fd = open_cubfile(cubfile);
	printf("parsing assets...\n");
	parse_assets(&cub->assets, fd);
	printf("done!\nparsing map...\n");
	init_map(cub);
	parse_map(cub->map, &cub->player, fd);
	printf("done!\n");
}
