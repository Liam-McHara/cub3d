/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferre-m <eferre-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:56:09 by eferre-m          #+#    #+#             */
/*   Updated: 2024/11/12 18:56:50 by eferre-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "vec2.h"		// t_vec2_d

typedef struct s_player
{
	t_vec2_d	pos;
	t_vec2_d	dir;
	t_vec2_d	plane;
}	t_player;

#endif
