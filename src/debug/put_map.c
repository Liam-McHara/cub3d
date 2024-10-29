#include <utils.h>
#include <unistd.h>				// STDOUT_FILENO

void	put_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		ft_putendl_fd(map[i], STDOUT_FILENO);
	}
}
