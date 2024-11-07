#include "cub3d.h"
#include "color.h"
#include <stdlib.h>
#include "assets.h"
#include "raycast.h"
#include "textures.h"
#include <stdio.h>
#include <math.h>

static mlx_texture_t *get_texture(int side, t_assets *assets)
{
	if (side == NO)
		return (assets->n);
	if (side == SO)
		return (assets->s);
	if (side == EA)
		return (assets->e);
	if (side == WE)
		return (assets->w);
	return (0);
} 

static t_txt_side	get_texture_side(t_vec2_i *step, int *side)
{
	if (*side == 0 && step->x < 0)
		return (NO);
	if (*side == 0 && step->x > 0)
		return (SO);
	if (*side == 1 && step->y < 0)
		return (EA);
	if (*side == 1 && step->y > 0)
		return (WE);
	return (0);
}

static void	draw_texture(int x, t_raycast *r, t_cub *c, t_assets *assets, int side)
{
	t_texture_d		txt_data;
	int				y;
	mlx_texture_t	*texture;
	uint32_t		*arr;

	if (r->side == 0)
		txt_data.wall_x = c->player.pos.y + r->wall_dist * r->raydir.y;
	else
		txt_data.wall_x = c->player.pos.x + r->wall_dist * r->raydir.x;
	txt_data.wall_x -= floor(txt_data.wall_x);
	txt_data.txt_coord.x = txt_data.wall_x * TEXTURE_WIDTH;
	if (r->side == 0 && r->raydir.x > 0)
		txt_data.txt_coord.x = TEXTURE_WIDTH - txt_data.txt_coord.x - 1;
	if (r->side == 1 && r->raydir.y < 0)
		txt_data.txt_coord.x = TEXTURE_WIDTH - txt_data.txt_coord.x - 1;
	txt_data.step = 1.0 * TEXTURE_HEIGHT / r->line_height;
	txt_data.txt_pos = (r->line_start - c->img->height
			/ 2.0 + r->line_height / 2.0) * txt_data.step;
	texture = get_texture(side, assets);
	arr = (uint32_t *)texture->pixels;
	y = r->line_start;
	while (y < r->line_end)
	{
		txt_data.txt_coord.y = (int)txt_data.txt_pos & (TEXTURE_HEIGHT - 1);
		txt_data.txt_pos += txt_data.step;
		mlx_put_pixel(c->img, x, y++, arr[txt_data.txt_coord.y * TEXTURE_WIDTH + txt_data.txt_coord.x]);
	}
}

void	draw_line(int x, t_raycast *r, t_cub *c)
{
	int	y;
	int	txt_side;

	y = 0;
	if (r->line_start >= SCREEN_HEIGHT || r->line_end < 0)
		return ;
	txt_side = get_texture_side(&r->step, &r->side);
	while (y < r->line_start)
	{
		//mlx_put_pixel(c->img, x, y, 0x89CFF3FF);
		mlx_put_pixel(c->img, x, y, c->assets.c);
		y++;
	}
	draw_texture(x, r, c, &c->assets, txt_side);
	y = r->line_end;
	while ((uint32_t)y < SCREEN_HEIGHT)
	{
		//mlx_put_pixel(c->img, x, y, 0xB99470FF);
		mlx_put_pixel(c->img, x, y, c->assets.f);
		y++;
	}
}
