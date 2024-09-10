#include "cub3d.h"
#include "movements.h"

static void	vector_rotate(t_matrix *rotation, t_vec2_d *vector)
{
	double	vector_x;

	vector_x = vector->x;
	vector->x = vector_x * rotation->a + vector->y * rotation->b;
	vector->y = vector_x * rotation->c + vector->y * rotation->d;
}

void	rot_player(t_player *player, double angle)
{
	t_matrix	rotation;

	rotation.a = cos(ROTATION_SPEED * angle);
	rotation.b = sin(ROTATION_SPEED * angle);
	rotation.c = -sin(ROTATION_SPEED * angle);
	rotation.d = cos(ROTATION_SPEED * angle);
	vector_rotate(&rotation, &player->dir);
	vector_rotate(&rotation, &player->plane);
}

static void	check_collisions(t_player *player, double new_pos_x,
		double new_pos_y, char **map)
{
	if (map[(int)new_pos_y][(int)player->pos.x] != '1')
		player->pos.x = new_pos_x;
	if (map[(int)player->pos.y][(int)new_pos_x] != '1')
		player->pos.y = new_pos_y;
	if (map[(int)new_pos_y][(int)player->pos.x] == '1')
		player->pos.x = player->pos.x;
	if (map[(int)player->pos.y][(int)new_pos_x] == '1')
		player->pos.y = player->pos.y;
}

void	upd_player_pos(t_player *player, int key, char **map)
{
	if (key == MLX_KEY_W)
		check_collisions(player,
			player->pos.x + player->dir.x * PLAYER_SPEED,
			player->pos.y + player->dir.y * PLAYER_SPEED, map);
	if (key == MLX_KEY_S)
		check_collisions(player,
			player->pos.x - player->dir.x * PLAYER_SPEED,
			player->pos.y - player->dir.y * PLAYER_SPEED, map);
	if (key == MLX_KEY_A)
		check_collisions(player,
			player->pos.x - player->dir.y * PLAYER_SPEED,
			player->pos.y + player->dir.x * PLAYER_SPEED, map);
	if (key == MLX_KEY_D)
		check_collisions(player,
			player->pos.x + player->dir.y * PLAYER_SPEED,
			player->pos.y - player->dir.x * PLAYER_SPEED, map);
}