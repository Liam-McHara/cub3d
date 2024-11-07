#include "cub3d.h"
#include "movements.h"

#include <stdio.h>

void mouse_rotation(t_cub *c)
{
    t_vec2_i    mouse_pos;
    
    mlx_get_mouse_pos(c->mlx, &mouse_pos.x, &mouse_pos.y);
    printf("mouse.x : %i mouse.y : %i\n", mouse_pos.x, mouse_pos.y);
    //rot_player();
    //mlx_set_mouse_pos();
}