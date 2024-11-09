#include <math.h>
#include "assets.h"

# define PLAYER_SPEED 4.0
# define ROTATION_SPEED 3.0
# define MOUSE_ROT_SPEED 0.2
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

// private
void	player_move_pos(t_cub *c, int key, t_vec2_d *new_pos);
