#include "cub3d.h"
#include "movements.h"

#include <stdio.h>

static void	vector_rotate(t_matrix *rotation, t_vec2_d *vector)
{
	double	vector_x;

	vector_x = vector->x;
	vector->x = vector_x * rotation->a + vector->y * rotation->b;
	vector->y = vector_x * rotation->c + vector->y * rotation->d;
}

void	rot_player(t_cub *c, double rot)
{
	t_player	*p;
	float		dt;
	t_matrix	rotation;

	p = &c->player;
	dt = c->mlx->delta_time;
	rotation.a = cos(dt * rot);
	rotation.b = sin(dt * rot);
	rotation.c = -sin(dt * rot);
	rotation.d = cos(dt * rot);
	vector_rotate(&rotation, &p->dir);
	vector_rotate(&rotation, &p->plane);
}

static void	check_collisions(t_player *player, t_vec2_d new_pos, char **map)
{
	if (map[(int)new_pos.y][(int)player->pos.x] == FLOOR && map[(int)player->pos.y][(int)new_pos.x] == FLOOR)
	{
		if (map[(int)(new_pos.y)][(int)(new_pos.x)] == FLOOR)
		{
			player->pos.y = (new_pos.y);
			player->pos.x = (new_pos.x);
		}
	}
	else if (map[(int)new_pos.y][(int)player->pos.x] == FLOOR)
		player->pos.y = new_pos.y;
	else if (map[(int)player->pos.y][(int)new_pos.x] == FLOOR)
		player->pos.x = new_pos.x;
}

void	upd_player_pos(t_cub *c, int key)
{
	t_player	*p;
	float		dt;
	t_vec2_d	new_pos;		
	
	dt = c->mlx->delta_time;
	p = &c->player;
	if (key == MLX_KEY_W)
	{
		new_pos.x = p->pos.x + p->dir.x * PLAYER_SPEED * dt;
		new_pos.y = p->pos.y + p->dir.y * PLAYER_SPEED * dt;
	}
	if (key == MLX_KEY_S)
	{
		new_pos.x = p->pos.x - p->dir.x * PLAYER_SPEED * dt;
		new_pos.y = p->pos.y - p->dir.y * PLAYER_SPEED * dt;
	}
	if (key == MLX_KEY_A)
	{
		new_pos.x = p->pos.x - p->dir.y * PLAYER_SPEED * dt;
		new_pos.y = p->pos.y + p->dir.x * PLAYER_SPEED * dt;
	}
	if (key == MLX_KEY_D)
	{
		new_pos.x = p->pos.x + p->dir.y * PLAYER_SPEED * dt;
		new_pos.y = p->pos.y - p->dir.x * PLAYER_SPEED * dt;
	}
	check_collisions(p, new_pos, c->map);
}
