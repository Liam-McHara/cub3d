#include "cub3d.h"			// check_args, cub3d, t_cub
#include "parse.h"			// parse
#include <stdlib.h>			// EXIT_SUCCESS

int	main(int ac, char **av)
{
	t_cub	c;
	char	*cubfile;

	cubfile = check_args(ac, av);
	int n = ft_atoi("43", "patata");
	parse(cubfile, &c);
	//cub3d(&c);
	return (EXIT_SUCCESS);
}
