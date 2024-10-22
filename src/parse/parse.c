#include <cub3d.h>				// t_cub, t_map, t_assets, t_player
#include "MLX42.h"				// mlx_init 
#include "parse_private.h"		// parse_settings, parse_map
#include "utils.h"				// put_err, put_syserr
#include <fcntl.h>				// open

	#include <stdio.h>

// Opens the .cub file 'cubfile' and returns its file descriptor.
// If it can't open the file, prints an error message and exits gracefully.
static int	open_cubfile(const char *cubfile)
{
	int	fd;

	fd = open(cubfile, O_RDONLY);
	if (fd == -1)
		exit(put_syserr("Couldn't open map file"));
	return (fd);
}

static void	init_mlx(mlx_t *mlx)
{
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(WIDTH, HEIGHT, CUBNAME, true);
	if (!mlx)
		exit(put_err(ERRMSG_MLX_INIT));
}

// Loads the .cub file and parses its content, leaving the t_cub object
// ready-to-use.
// If any error is found, prints an error message and exits gracefully.
void	parse(const char *cubfile, t_cub *cub)
{
	int		fd;

	printf("fd old = %d\n", fd);
	fd = open_cubfile(cubfile);
	printf("fd new = %d\n", fd);

	parse_assets(&cub->assets, fd);
	printf("fd 3 = %d\n", fd);
	parse_map(&cub->map, &cub->player, fd);
	init_mlx(&cub->mlx);
}
