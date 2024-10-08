#include "cub3d.h"
#include "raycast.h"
#include "minimap.h"
#include "movements.h"

    #include <stdio.h>

static void    hook(void *param)
{
    t_cub   *c;

    c = param;

	if (mlx_is_key_down(c.mlx, MLX_KEY_ESCAPE))
        mlx_close_window(c.mlx);
    if (mlx_is_key_down(c.mlx, MLX_KEY_W))
        upd_player_pos(&c->player, MLX_KEY_W, c->map.matrix);
    if (mlx_is_key_down(c.mlx, MLX_KEY_S))
        upd_player_pos(&c->player, MLX_KEY_S, c->map.matrix);
    if (mlx_is_key_down(c.mlx, MLX_KEY_A))
        upd_player_pos(&c->player, MLX_KEY_A, c->map.matrix);
    if (mlx_is_key_down(c.mlx, MLX_KEY_D))
        upd_player_pos(&c->player, MLX_KEY_D, c->map.matrix);
    if (mlx_is_key_down(c.mlx, MLX_KEY_LEFT))
        rot_player(&c->player, -0.2);
    if (mlx_is_key_down(c.mlx, MLX_KEY_RIGHT))
        rot_player(&c->player, 0.2);
    raycast_position(c);
	draw_mmap(c);
	mini_draw(c, c->player.pos.x * 5, c->player.pos.y * 5, 0xFF000090);
}

int	cub3d(t_cub *c)
{
    if (!(c->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "CUB3D", false)))
		return (1);
	if (!(c->img = mlx_new_image(c->mlx, SCREEN_WIDTH, SCREEN_HEIGHT)))
	{
		mlx_close_window(c->mlx);
		return (1);
	}
	if (mlx_image_to_window(c->mlx, c->img, 0, 0))
	{
		mlx_close_window(c->mlx);
		return (1);
	}
	//mlx_set_cursor_mode(c->mlx, MLX_MOUSE_HIDDEN);
    mlx_loop_hook(c->mlx, &hook, c);
	mlx_loop(c->mlx);
    mlx_delete_image(c->mlx, c->img);
	mlx_terminate(c->mlx);
	return (0);
}