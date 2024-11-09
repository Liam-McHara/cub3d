#include "cub3d.h"
#include "movements.h"

static void	move_up(t_vec2_d *new_pos, t_cub *c)
{
	t_player	*p;
	float		dt;

	dt = c->mlx->delta_time;
	p = &c->player;
	new_pos->x = p->pos.x + p->dir.x * PLAYER_SPEED * dt;
	new_pos->y = p->pos.y + p->dir.y * PLAYER_SPEED * dt;
}

static void	move_down(t_vec2_d *new_pos, t_cub *c)
{
	t_player	*p;
	float		dt;

	dt = c->mlx->delta_time;
	p = &c->player;
	new_pos->x = p->pos.x - p->dir.x * PLAYER_SPEED * dt;
	new_pos->y = p->pos.y - p->dir.y * PLAYER_SPEED * dt;
}

static void	move_left(t_vec2_d *new_pos, t_cub *c)
{
	t_player	*p;
	float		dt;

	dt = c->mlx->delta_time;
	p = &c->player;
	new_pos->x = p->pos.x + p->dir.y * PLAYER_SPEED * dt;
	new_pos->y = p->pos.y - p->dir.x * PLAYER_SPEED * dt;
}

static void	move_right(t_vec2_d *new_pos, t_cub *c)
{
	t_player	*p;
	float		dt;

	dt = c->mlx->delta_time;
	p = &c->player;
	new_pos->x = p->pos.x - p->dir.y * PLAYER_SPEED * dt;
	new_pos->y = p->pos.y + p->dir.x * PLAYER_SPEED * dt;
}

void	player_move_pos(t_cub *c, int key, t_vec2_d *new_pos)
{
	if (key == MLX_KEY_W)
		move_up(new_pos, c);
	if (key == MLX_KEY_S)
		move_down(new_pos, c);
	if (key == MLX_KEY_A)
		move_left(new_pos, c);
	if (key == MLX_KEY_D)
		move_right(new_pos, c);
}
