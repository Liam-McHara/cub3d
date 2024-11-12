/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferre-m <eferre-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:40:38 by eferre-m          #+#    #+#             */
/*   Updated: 2024/11/12 18:40:47 by eferre-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minimap.h"		// MAP_*

void	mini_draw(t_cub *c, int x, int y, int color)
{
	int	x_max;
	int	y_max;

	x_max = x + MAP_PXL_SIZE;
	y_max = y + MAP_PXL_SIZE;
	while (y < y_max && (uint32_t)y < c->img->width)
	{
		while (x < x_max && (uint32_t)x < c->img->height)
			mlx_put_pixel(c->img, x++, y, color);
		x -= MAP_PXL_SIZE;
		y++;
	}
}

void	draw_minimap(t_cub *c)
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
				mini_draw(c, x * MAP_PXL_SIZE, y * MAP_PXL_SIZE, MAP_W_COLOR);
			else if (c->map[y][x] == FLOOR)
				mini_draw(c, x * MAP_PXL_SIZE, y * MAP_PXL_SIZE, MAP_F_COLOR);
			x++;
		}
		y++;
	}
}

void	minimap(t_cub *c)
{
	int	x;
	int	y;

	x = c->player.pos.x * MAP_PXL_SIZE - (MAP_PXL_SIZE / 2);
	y = c->player.pos.y * MAP_PXL_SIZE - (MAP_PXL_SIZE / 2);
	draw_minimap(c);
	mini_draw(c, x, y, MAP_PLAYER_COLOR);
}
