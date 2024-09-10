#include <math.h>
#include "assets.h"

# define ROTATION_SPEED 0.045
# define PLAYER_SPEED 4 

typedef struct s_matrix
{
	double	a;
	double	b;
	double	c;
	double	d;
}	t_matrix;

void	upd_player_pos(t_player *player, int key, char **map);
void	rot_player(t_player *player, double angle);