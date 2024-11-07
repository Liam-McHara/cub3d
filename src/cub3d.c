#include "cub3d.h"
#include "raycast.h"
#include "minimap.h"
#include "movements.h"
#include "utils.h"      // put_err
#include <stdlib.h>     // exit
#include <unistd.h>     // exit

    #include <stdio.h>

void	draw_mmap(t_cub *c);
void	mini_draw(t_cub *c, int x, int y, int color);

static void    hook(void *param)
{
    t_cub   *c;

    c = (t_cub *)param;

	if (mlx_is_key_down(c->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(c->mlx);
    if (mlx_is_key_down(c->mlx, MLX_KEY_W))
        upd_player_pos(c, MLX_KEY_W);
    if (mlx_is_key_down(c->mlx, MLX_KEY_S))
        upd_player_pos(c, MLX_KEY_S);
    if (mlx_is_key_down(c->mlx, MLX_KEY_A))
        upd_player_pos(c, MLX_KEY_A);
    if (mlx_is_key_down(c->mlx, MLX_KEY_D))
        upd_player_pos(c, MLX_KEY_D);
    if (mlx_is_key_down(c->mlx, MLX_KEY_LEFT))
        rot_player(c, -0.2);           // constante
    if (mlx_is_key_down(c->mlx, MLX_KEY_RIGHT))
		rot_player(c, 0.2);
	raycast_position(c);		// <-- OJO: hace explotar el ordenador
	draw_mmap(c);
	mini_draw(c, c->player.pos.x * 5, c->player.pos.y * 5, MAP_PLAYER_COLOR);
    //draw_minimap(c);
}

static void	init_mlx(t_cub *c)
{
	//mlx_set_setting(MLX_MAXIMIZED, true);
	c->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, CUBNAME, true);
	if (!c->mlx)
		exit(put_err(ERRMSG_MLX_INIT));
    c->img = mlx_new_image(c->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!c->img)
    {
		mlx_close_window(c->mlx);
		exit(put_err(ERRMSG_MLX_INIT));
	}
	if (mlx_image_to_window(c->mlx, c->img, 0, 0))
	{
		mlx_close_window(c->mlx);
		exit(put_err(ERRMSG_MLX_INIT));
	}
}

void	cub3d(t_cub *c)
{
    init_mlx(c);
	//mlx_set_cursor_mode(c->mlx, MLX_MOUSE_HIDDEN);
    mlx_loop_hook(c->mlx, &hook, c);
	mlx_loop(c->mlx);
    mlx_delete_image(c->mlx, c->img);
	mlx_terminate(c->mlx);
}
