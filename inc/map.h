/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:18:38 by glajara-          #+#    #+#             */
/*   Updated: 2024/11/12 19:18:39 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "vec2.h"				// t_vec2_d
# include <stdbool.h>			// bool

typedef enum e_direction
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}	t_direction;

enum
{
	WALL = '1',
	FLOOR = '0',
	VOID = ' '
};

void	map_check_closed(char **map, t_vec2_d *pos);
void	map_free(char **map);

#endif
