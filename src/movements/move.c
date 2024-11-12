#include "cub3d.h"
#include "movements.h"
#include <math.h>

static void	check_collisions(t_player *player, t_vec2_d new_pos, char **map)
{
	if (map[(int)new_pos.y][(int)new_pos.x] == FLOOR)
	{
		player->pos.y = new_pos.y;
		player->pos.x = new_pos.x;
	}
	else if (map[(int)new_pos.y][(int)player->pos.x] == FLOOR)
		player->pos.y = new_pos.y;
	else if (map[(int)player->pos.y][(int)new_pos.x] == FLOOR)
		player->pos.x = new_pos.x;
}

void	upd_player_pos(t_cub *c, int key)
{
	t_player	*p;
	t_vec2_d	new_pos;

	p = &c->player;
	player_move_pos(c, key, &new_pos);
	check_collisions(p, new_pos, c->map);
}
