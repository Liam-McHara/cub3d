#include <math.h>
#include "assets.h"

# define PLAYER_SPEED 5.0
# define ROTATION_SPEED 14.0

typedef struct s_matrix
{
	double	a;
	double	b;
	double	c;
	double	d;
}	t_matrix;

void	upd_player_pos(t_cub *c, int key);
void	rot_player(t_cub *c, double angle);
