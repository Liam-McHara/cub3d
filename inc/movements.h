#include <math.h>
#include "assets.h"

# define PLAYER_SPEED 6.0
# define ROTATION_SPEED 3.0
# define RADIUS 0.25

typedef struct s_matrix
{
	double	a;
	double	b;
	double	c;
	double	d;
}	t_matrix;

void	upd_player_pos(t_cub *c, int key);
void 	mouse_rotation(t_cub *c);
void	rot_player(t_cub *c, double angle);
