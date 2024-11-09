#include "cub3d.h"
#include "assets.h"
#include "raycast.h"
#include <math.h>

//STEP 5 : Step 5: Calculating the Wall Height
/* This function calculates the height of the wall
and the draw start and draw end of the wall.*/
static void  calcul_wall_height(t_raycast *r, t_cub *c)
{
    r->line_height = c->mlx->height / r->wall_dist;
    r->line_start = (-r->line_height / 2) + (c->mlx->height / 2);
    if (r->line_start < 0)
        r->line_start = 0;
    r->line_end = (r->line_height / 2) + (c->mlx->height / 2);
    if (r->line_end >= c->mlx->height)
        r->line_end = c->mlx->height - 1;
    if (r->side == 0)
        r->wall_dist = r->side_dist.x - r->delta_dist.x;
    else
        r->wall_dist = r->side_dist.y - r->delta_dist.y;
}

//STEP 4 : Performing Digital Differential Analysis
/* This function calculates the distance to the
wall by calculating the distance to the next x or y side of the map.*/
static void    calcul_wall_distance(t_raycast *r, char **map)
{
    while (r->hit == 0)
    {
        if (r->side_dist.x < r->side_dist.y)
        {
            r->side_dist.x += r->delta_dist.x;
            r->map_pos.x += r->step.x;
            r->side = 0;
        }
        else
        {
            r->side_dist.y += r->delta_dist.y;
            r->map_pos.y += r->step.y;
            r->side = 1;
        }
        if (map[r->map_pos.y][r->map_pos.x] == '1')
        {
            r->hit = 1;
            break ;
        }    
    }
    if (r->side == 0)
    	r->wall_dist = r->side_dist.x - r->delta_dist.x;
	else
		r->wall_dist = r->side_dist.y - r->delta_dist.y;
}


//STEP 3 : Calculating the Step and Initial Side Distances
/* This function calculates the step of the ray which is
then used to calculate the distance to the wall.*/
static void    calcul_sidedist(t_raycast *r, t_cub  *c)
{   
    if (r->raydir.x < 0.0)
    {
        r->step.x = -1;
        r->side_dist.x = (c->player.pos.x - r->map_pos.x) * r->delta_dist.x;
    }
    else
    {
        r->step.x = 1;
        r->side_dist.x = (r->map_pos.x + 1.0 - c->player.pos.x) * r->delta_dist.x;    
    }
    if (r->raydir.y < 0.0)
    {
        r->step.y = -1;
        r->side_dist.y = (c->player.pos.y - r->map_pos.y) * r->delta_dist.y;
    }
    else
    {
        r->step.y = 1;
        r->side_dist.y = (r->map_pos.y + 1.0 - c->player.pos.y) * r->delta_dist.y;
    }
}


//STEP 2 : Calculating the Delta Distance
/*The next step in the raycasting algorithm is to calculate the delta distance 
between two consecutive x or y intersections with a grid line.
This is done by determining the distance the ray must travel to reach 
the next grid line in the x or y direction.*/
static void    init_delta_dist(t_vec2_d *raydir, t_vec2_d *delta_dist)
{
    if (raydir->x == 0.0)
        delta_dist->x = 1e30;
    else
        delta_dist->x = fabs(1 / raydir->x);
    if (raydir->y == 0.0)
        delta_dist->y = 1e30;
    else
        delta_dist->y = fabs(1 / raydir->y);
}


//STEP 1 : Calculate ray position and direction
/*The first step in the raycasting algorithm is to calculate 
the direction of the ray based on the player’s position and orientation. */
void    ray_direction(t_raycast *r, t_player  *player, double cam)
{
    r->raydir.x = player->dir.x + player->plane.x * cam;
    r->raydir.y = player->dir.y + player->plane.y * cam;
    r->map_pos.x = (int)player->pos.x;
    r->map_pos.y = (int)player->pos.y;
}

/*This function initializes the ray structure with the
necessary values to calculate the ray.*/
static void    init_ray(t_cub *c, t_raycast *r, double cam)
{
    ray_direction(r, &c->player, cam);
    init_delta_dist(&r->raydir, &r->delta_dist);
    r->hit = 0;
}

/* This function handles the raycasting by initializing the
ray, calculating the step, calculating the wall distance, 
calculating the wall height and finally, updating the pixel map. */
void    raycast_position(t_cub *c)
{
    int		    x;
    double	    cam;
    t_raycast   r;

    x = 0;
    while(x < c->mlx->width)
    {
        cam = 2.0 * x / (double)c->mlx->width - 1.0;
        init_ray(c, &r, cam);
        calcul_sidedist(&r, c);
        calcul_wall_distance(&r, c->map);
        calcul_wall_height(&r, c);
        draw_cub(x, &r, c);
        x++;
    }
}