/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:01:25 by glajara-          #+#    #+#             */
/*   Updated: 2024/11/12 19:01:27 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"			// check_args, cub3d, t_cub
#include "parse.h"			// parse
#include <stdlib.h>			// EXIT_SUCCESS

int	main(int ac, char **av)
{
	t_cub	c;
	char	*cubfile;

	cubfile = check_args(ac, av);
	parse(cubfile, &c);
	cub3d(&c);
	map_free(c.map);
	return (EXIT_SUCCESS);
}
