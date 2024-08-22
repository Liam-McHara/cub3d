#include "cub3d.h"
#include "color.h"
#include <stdlib.h>
#include "assets.h"
#include "raycast.h"
#include "MLX42/MLX42.h"
#include <stdio.h>
#include <math.h>

static t_txt_side	get_texture_side(t_coord_i *step, int *side)
{
	if (*side == 0 && step->x < 0) //white
		return (NO);
	if (*side == 0 && step->x > 0) //white
		return (SO);
	if (*side == 1 && step->y < 0) //grey
		return (EA);
	if (*side == 1 && step->y > 0) //grey
		return (WE);
	return (0);
}

static void	draw_texture(int x, t_raycast *r, t_cub *c, int side)
{
	t_texture_draw	txt_data;
	int				y;
	int				color;
	(void)	side;

	color = 0xF5F5F5FF; //white
	if (r->side == 0)
		txt_data.wall_x = c->player.pos.y + r->wall_dist * r->raydir.y;
	else
		txt_data.wall_x = c->player.pos.x + r->wall_dist * r->raydir.x;
	txt_data.wall_x -= floor(txt_data.wall_x);
	y = r->line_start;
	while (y < r->line_end)
	{
		if (r->side == 1)
			color = 0xB5B5B5FF; //gray
		mlx_put_pixel(c->img, x, y++, color);
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
		mlx_put_pixel(c->img, x, y, 0x89CFF3FF);
		y++;
	}
	draw_texture(x, r, c, txt_side);
	y = r->line_end;
	while ((uint32_t)y < SCREEN_HEIGHT)
	{
		mlx_put_pixel(c->img, x, y, 0xB99470FF);
		y++;
	}
}
