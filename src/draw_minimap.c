#include "cub3d.h"
#include "minimap.h"		// MAP_*_COLOR

void	mini_draw(t_cub *c, int x, int y, int color)
{
	int	x_max;
	int	y_max;

	x_max = x + 5;
	y_max = y + 5;
	while (y < y_max && (uint32_t)y < c->img->width)
	{
		while (x < x_max && (uint32_t)x < c->img->height)
			mlx_put_pixel(c->img, x++, y, color);
		x -= 5;
		y++;
	}
}

void	draw_mmap(t_cub *c)
{
	int	x;
	int	y;

	y = 0;
	while (c->map[y])
	{
		x = 0;
		while (c->map[y][x])
		{
			if (c->map[y][x] == WALL)
				mini_draw(c, x * 5, y * 5, MAP_WALL_COLOR);
			else if (c->map[y][x] == FLOOR)
				mini_draw(c, x * 5, y * 5, MAP_FLOOR_COLOR);
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
