/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:18:47 by glajara-          #+#    #+#             */
/*   Updated: 2024/11/12 19:26:14 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_PRIVATE_H
# define PARSE_PRIVATE_H

# include "assets.h"
# include "player.h"
# include "map.h"		// t_direction

typedef enum e_color_type
{
	C_CEILING,
	C_FLOOR
}	t_color_type;

void	parse_texture(t_assets *a, const char *str, t_direction dir);
void	parse_color(t_assets *a, const char *str, t_color_type type);
void	parse_assets(t_assets *a, int fd);
void	parse_map(char **map, t_player *p, int fd);
void	set_player(t_player *p, int x, int y, char dir);

#endif
