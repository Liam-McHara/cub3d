#ifndef TEXTURES_H
# define TEXTURES_H

# define TEXTURE_WIDTH 256
# define TEXTURE_HEIGHT 256

# include "vec2.h"

typedef struct s_texture_d
{
	double		wall_x;
	double		step;
	t_vec2_i	txt_coord;
	double		txt_pos;
}	t_texture_d;

typedef enum e_txt_side
{
	NO,
	SO,
	WE,
	EA
}	t_txt_side;

#endif
