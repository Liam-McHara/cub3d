#include "parse_private.h"		// T_NORTH, T_SOUTH, T_EAST, T_WEST
#include "assets.h"				// t_assets
#include "MLX42.h"				// mlx_texture_t, mlx_load_png
#include "utils.h"				// ft_strtrim, put_err ...
#include <stdlib.h>				// free
#include <stdbool.h>			// true, false
#include "textures.h"			// TEXTURE_HEIGHT, TEXTURE_WIDTH

// Sets the north texture.
// If it has already been set, prints a message and exits gracefully.
static void	set_north_texture(t_assets *a, mlx_texture_t *texture)
{
	static bool	north_set = false;

	if (north_set)
		exit(put_err(ERRMSG_MULTIDEFINE));
	a->n = texture;
	north_set = true;
}

// Sets the south texture.
// If it has already been set, prints a message and exits gracefully.
static void	set_south_texture(t_assets *a, mlx_texture_t *texture)
{
	static bool	south_set = false;

	if (south_set)
		exit(put_err(ERRMSG_MULTIDEFINE));
	a->s = texture;
	south_set = true;
}

// Sets the east texture.
// If it has already been set, prints a message and exits gracefully.
static void	set_east_texture(t_assets *a, mlx_texture_t *texture)
{
	static bool	east_set = false;

	if (east_set)
		exit(put_err(ERRMSG_MULTIDEFINE));
	a->e = texture;
	east_set = true;
}

// Sets the west texture.
// If it has already been set, prints a message and exits gracefully.
static void	set_west_texture(t_assets *a, mlx_texture_t *texture)
{
	static bool	west_set = false;

	if (west_set)
		exit(put_err(ERRMSG_MULTIDEFINE));
	a->w = texture;
	west_set = true;
}

// Parses 'str' and sets the texture specified by 'texture_type'.
// In case of error, prints a message and exits gracefully.
void	parse_texture(t_assets *a, const char *str, t_direction dir)
{
	char			*texture_path;
	mlx_texture_t	*texture;

	texture_path = ft_strtrim(str, BLANK_CHARS);
	texture = mlx_load_png(texture_path);
	if (!texture)
		exit(put_mlxerr(texture_path));
	if (texture->height != TEXTURE_HEIGHT || texture->width != TEXTURE_WIDTH)
		exit(put_err(ERRMSG_PNG_SIZE));
	free(texture_path);
	if (dir == NORTH)
		set_north_texture(a, texture);
	else if (dir == SOUTH)
		set_south_texture(a, texture);
	else if (dir == EAST)
		set_east_texture(a, texture);
	else if (dir == WEST)
		set_west_texture(a, texture);
}
