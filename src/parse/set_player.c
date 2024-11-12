/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:53:17 by glajara-          #+#    #+#             */
/*   Updated: 2024/11/12 18:53:18 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "utils.h"

// Sets the player's direction.
static void	set_player_dir(t_player *player, char dir)
{
	if (dir == 'N')
	{
		player->dir = (t_vec2_d){.x = 0, .y = -1};
		player->plane = (t_vec2_d){.x = 0.66, .y = 0};
	}
	else if (dir == 'S')
	{
		player->dir = (t_vec2_d){.x = 0, .y = 1};
		player->plane = (t_vec2_d){.x = -0.66, .y = 0};
	}
	else if (dir == 'E')
	{
		player->dir = (t_vec2_d){.x = 1, .y = 0};
		player->plane = (t_vec2_d){.x = 0, .y = 0.66};
	}
	else if (dir == 'W')
	{
		player->dir = (t_vec2_d){.x = -1, .y = 0};
		player->plane = (t_vec2_d){.x = 0, .y = -0.66};
	}
}

// Sets the player's direction.
static void	set_player_pos(t_player *player, int x, int y)
{
	player->pos = (t_vec2_d){.x = x + 0.5, .y = y + 0.5};
}

// Sets the player's position and direction.
// If the player is already set, prints an error message and exits gracefully.
void	set_player(t_player *player, int x, int y, char dir)
{
	static bool	set_flag = false;

	if (set_flag)
		exit(put_err(ERRMSG_MULTIPLAYER));
	set_flag = true;
	set_player_pos(player, x, y);
	set_player_dir(player, dir);
}
