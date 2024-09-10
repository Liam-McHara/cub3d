#include <math.h>
#include "assets.h"

typedef struct s_vec_rot
{
	double	a;
	double	b;
	double	c;
	double	d;
}	t_vec_rot;

void	upd_player_pos(t_player *player, int key, char **map);
void	rot_player(t_player *player, double angle);