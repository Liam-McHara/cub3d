#include <stdbool.h>

// Returns true if 'c' is a number. Otherwise, returns false.
bool	ft_isnumber(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}
