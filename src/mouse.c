#include "cub3d.h"
#include "movements.h"

void mouse_rotation(t_cub *c)
{
    t_vec2_i    mouse_pos;
    
    mlx_get_mouse_pos(c->mlx, &mouse_pos.x, &mouse_pos.y);
    rot_player(c, -(mouse_pos.x - SCREEN_HEIGHT / 2) * MOUSE_ROT_SPEED);
    mlx_set_mouse_pos(c->mlx, SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2);
}
