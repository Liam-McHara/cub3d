#include <stdlib.h>				// size_t

// Returns the lenght of the string 'str'.
size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
		++len;
	return (len);
}
