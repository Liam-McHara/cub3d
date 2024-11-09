#include "textures.h"
#include "assets.h"
#include <math.h>

// Calculate value of wall_x
static void init_wallx(t_raycast *r, t_cub *c, t_texture_d *txt_data)
{
	if(r->side == 0)
		txt_data->wall_x = c->player.pos.y + r->wall_dist * r->raydir.y;
	else
		txt_data->wall_x = c->player.pos.x + r->wall_dist * r->raydir.x;
	txt_data->wall_x -= floor(txt_data->wall_x);
}

// Calculate coord x
static void init_coordx(t_raycast *r, t_texture_d *txt_data)
{
	txt_data->txt_coord.x = txt_data->wall_x * TEXTURE_WIDTH;
	if (r->side == 1 && r->raydir.y > 0)
		txt_data->txt_coord.x = TEXTURE_WIDTH - txt_data->txt_coord.x - 1;
	if (r->side == 0 && r->raydir.x < 0)
		txt_data->txt_coord.x = TEXTURE_WIDTH - txt_data->txt_coord.x - 1;
}

void init_data_txt(t_raycast *r, t_cub *c, t_texture_d *txt_data)
{
	init_wallx(r, c, txt_data);
	txt_data->step = 1.0 * TEXTURE_HEIGHT / r->line_height;
	txt_data->txt_pos = (r->line_start - c->img->height
			/ 2.0 + r->line_height / 2.0) * txt_data->step;
	init_coordx(r, txt_data);
}
