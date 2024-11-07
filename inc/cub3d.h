#ifndef CUB3D_H
# define CUB3D_H

# include "player.h"
# include "map.h"
# include "assets.h"

# define CUBNAME "cub3D"
# define WIDTH 1024
# define HEIGHT 680
# define MAX_MAP_SIZE 20
# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 680

typedef struct s_cub
{
	t_player	player;
	char		**map;
	t_assets	assets;
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_cub;

char	*check_args(int ac, char **av);
void	cub3d(t_cub *c);

#endif
