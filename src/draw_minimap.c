#include "minimap.h"

void	mini_draw(t_cub *c, int x, int y, int color)
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

void	draw_mmap(t_cub *c)
{
    int		x;
	int		y;
	int		color;

	y = 0;
	while(c->map.matrix[y])
	{
		x = 0;
		while(c->map.matrix[y][x])
		{
			if (c->map.matrix[y][x] == '1')
				color = 0xFFFFFF;
			else
				color = 0x000000;
			mini_draw(c, x * 5, y * 5, color);
			x++;
		}
		y++;
	}
	
}