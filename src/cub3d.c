#include "cub3d.h"
#include "raycast.h"
#include "minimap.h"
#include "movements.h"
#include "utils.h"      // put_err

static void	hook(void *param)
{
	t_cub	*c;

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
		rot_player(c, ROTATION_SPEED);
	if (mlx_is_key_down(c->mlx, MLX_KEY_RIGHT))
		rot_player(c, -ROTATION_SPEED);
	mouse_rotation(c);
	raycast_position(c);
	minimap(c);
}

static void	init_mlx(t_cub *c)
{
	//mlx_set_setting(MLX_MAXIMIZED, true);  // <-- OJO: hace explotar el ordenador 
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

static void	delete_textures(t_cub *c)
{
	mlx_delete_texture(c->assets.n);
	mlx_delete_texture(c->assets.s);
	mlx_delete_texture(c->assets.e);
	mlx_delete_texture(c->assets.w);
}

void	cub3d(t_cub *c)
{
	init_mlx(c);
	mlx_set_cursor_mode(c->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(c->mlx, SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2);
	mlx_loop_hook(c->mlx, &hook, c);
	mlx_loop(c->mlx);
	mlx_delete_image(c->mlx, c->img);
	delete_textures(c);
	mlx_terminate(c->mlx);
}
