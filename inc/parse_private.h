#ifndef PARSE_PRIVATE_H
# define PARSE_PRIVATE_H

# include "assets.h"			// t_assets
# include "player.h"			// t_player
# include "map.h"				// t_map

typedef enum e_texture_type
{
	T_NORTH,
	T_SOUTH,
	T_WEST,
	T_EAST
}	t_texture_type;

typedef enum e_color_type
{
	C_CEILING,
	C_FLOOR
}	t_color_type;

void	parse_texture(t_assets *a, const char *str, t_texture_type type);
void	parse_color(t_assets *a, const char *str, t_color_type type);
void	parse_assets(t_assets *a, int fd);
void	parse_map(t_map *map, t_player *p, int fd);

#endif
