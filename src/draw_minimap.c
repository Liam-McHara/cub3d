#include "cub3d.h"
#include "minimap.h"		// MAP_*_COLOR

static void	mini_draw(t_cub *c, int x, int y, int color)
{
	int	x_max;
	int	y_max;

	x_max = x + 5;
	y_max = y + 5;
	while(x < x_max && (uint32_t)x < c->img->width)
	{
		while(y < y_max && (uint32_t)y < c->img->height)
			mlx_put_pixel(c->img, x, y++, color);
		y -= 5;
		x++;
	}
}

static void	draw_mmap(t_cub *c)
{
    int		x;
	int		y;
	int		color;

	y = 0;
	while(c->map[y])
	{
		x = 0;
		while(c->map[y][x])
		{
			if (c->map[y][x] == '1')
				color = MAP_WALL_COLOR;
			else
				color = MAP_FLOOR_COLOR;
			mini_draw(c, x * 5, y * 5, color);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_cub *c)
{
	draw_mmap(c);
	mini_draw(c, c->player.pos.x * 5, c->player.pos.y * 5, MAP_PLAYER_COLOR);
}