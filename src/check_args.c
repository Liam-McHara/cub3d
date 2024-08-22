#include <stdbool.h>
#include <stdlib.h>
#include "utils.h"

// Returns true if the string 'str' ends with ".cub". Returns false otherwise.
static bool	has_extension(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len >= 5
		&& str[len - 4] == '.'
		&& str[len - 3] == 'c'
		&& str[len - 2] == 'u'
		&& str[len - 1] == 'b')
		return (true);
	return (false);
}

// Returns true if 'str' consists only of alphanumeric characters
// (excluding the last 4 characters). Otherwise, returns false.
static bool	name_isalnum(char *str)
{
	size_t	len;
	int		i;

	len = ft_strlen(str);
	i = -1;
	while (++i < (int)len - 4)
	{
		if (!ft_isalnum(str[i]))
			return (false);
	}
	return (true);
}

// Checks if the there's only one argument and it is a filename following the
// format "name.cub". If it is correct, returns the filename.
// Otherwise, prints an error and exits.
char	*check_args(int ac, char **av)
{
	if (ac != 2)
	{
		put_err(ERRMSG_ARGNUM);
		exit(EXIT_FAILURE);
	}
	if (!has_extension(av[1]) || !name_isalnum(av[1]))
	{
		put_err(ERRMSG_ARGS);
		exit(EXIT_FAILURE);
	}
	return (av[1]);
}
