#include "cub3d.h"
#include "movements.h"

static void	vector_rotate(t_matrix *rotation, t_vec2_d *vector)
{
	double	vector_x;

	vector_x = vector->x;
	vector->x = vector_x * rotation->a + vector->y * rotation->b;
	vector->y = vector_x * rotation->c + vector->y * rotation->d;
}

void	rot_player(t_cub *c, double angle)
{
	t_player	*p;
	float		dt;
	t_matrix	rotation;

	p = &c->player;
	dt = c->mlx->delta_time;
	rotation.a = cos(ROTATION_SPEED * dt * angle);
	rotation.b = sin(ROTATION_SPEED * dt * angle);
	rotation.c = -sin(ROTATION_SPEED * dt * angle);
	rotation.d = cos(ROTATION_SPEED * dt * angle);
	vector_rotate(&rotation, &p->dir);
	vector_rotate(&rotation, &p->plane);
}

static void	check_collisions(t_player *player, double new_pos_x,
		double new_pos_y, char **map)
{
	if (map[((int)new_pos_y)][(int)player->pos.x] != '1' && map[(int)player->pos.y][((int)new_pos_x)] != '1')
	{
		player->pos.y = new_pos_y;
		player->pos.x = new_pos_x;
	}
	else if (map[((int)new_pos_y)][(int)player->pos.x] != '1' && map[(int)player->pos.y][((int)new_pos_x)] == '1')
		player->pos.y = new_pos_y;
	else if (map[((int)new_pos_y)][(int)player->pos.x] == '1' && map[(int)player->pos.y][((int)new_pos_x)] != '1')
		player->pos.x = new_pos_x;
}

void	upd_player_pos(t_cub *c, int key)
{
	t_player	*p;
	float		dt;		
	
	dt = c->mlx->delta_time;
	p = &c->player;
	if (key == MLX_KEY_W)
		check_collisions(p,
			p->pos.x + p->dir.x * PLAYER_SPEED * dt,
			p->pos.y + p->dir.y * PLAYER_SPEED * dt, c->map);
	if (key == MLX_KEY_S)
		check_collisions(p,
			p->pos.x - p->dir.x * PLAYER_SPEED * dt,
			p->pos.y - p->dir.y * PLAYER_SPEED * dt, c->map);
	if (key == MLX_KEY_A)
		check_collisions(p,
			p->pos.x + p->dir.y * PLAYER_SPEED * dt,
			p->pos.y - p->dir.x * PLAYER_SPEED * dt, c->map);
	if (key == MLX_KEY_D)
		check_collisions(p,
			p->pos.x - p->dir.y * PLAYER_SPEED * dt,
			p->pos.y + p->dir.x * PLAYER_SPEED * dt, c->map);
}
