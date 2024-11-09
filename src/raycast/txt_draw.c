#include "cub3d.h"
#include "assets.h"
#include "raycast.h"
#include "textures.h"

static mlx_texture_t	*get_texture(t_raycast *r, t_assets *assets)
{
	if (r->side == 1 && r->step.y > 0)
		return (assets->n);
	if (r->side == 1 && r->step.y < 0)
		return (assets->s);
	if (r->side == 0 && r->step.x < 0)
		return (assets->e);
	if (r->side == 0 && r->step.x > 0)
		return (assets->w);
	return (0);
}

static void	draw_texture(int x, t_raycast *r, t_cub *c)
{
	t_texture_d		txt_data;
	int				y;
	mlx_texture_t	*texture;
	uint32_t		*txt;
	t_vec2_i		t;

	init_data_txt(r, c, &txt_data);
	t = txt_data.txt_coord;
	texture = get_texture(r, &c->assets);
	txt = (uint32_t *)texture->pixels;
	y = r->line_start;
	while (y < r->line_end)
	{
		t.y = (int)txt_data.txt_pos & (TEXTURE_HEIGHT - 1);
		txt_data.txt_pos += txt_data.step;
		mlx_put_pixel(c->img, x, y++, txt[t.y * TEXTURE_WIDTH + t.x]);
	}
}

static void	draw_ceil_floor(int x, t_cub *c, t_raycast *r, int max)
{
	int	y;

	if (max == r->line_start)
	{
		y = 0;
		while (y < max)
			mlx_put_pixel(c->img, x, y++, c->assets.c);
	}
	else
	{
		y = r->line_end;
		while (y < max)
			mlx_put_pixel(c->img, x, y++, c->assets.f);
	}
}

void	draw_cub(int x, t_raycast *r, t_cub *c)
{
	if (r->line_start >= SCREEN_HEIGHT || r->line_end < 0)
		return ;
	draw_ceil_floor(x, c, r, r->line_start);
	draw_texture(x, r, c);
	draw_ceil_floor(x, c, r, SCREEN_HEIGHT);
}
