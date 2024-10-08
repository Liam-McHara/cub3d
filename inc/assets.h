#ifndef ASSETS_H
# define ASSETS_H

# include "MLX42.h"			// mlx_t, mlx_texture_t, mlx_image_t
# include <stdbool.h>		// true, false

typedef struct s_assets
{
	mlx_texture_t	*n;
	mlx_texture_t	*s;
	mlx_texture_t	*e;
	mlx_texture_t	*w;
	int				c;
	int				f;
}	t_assets;

#endif
