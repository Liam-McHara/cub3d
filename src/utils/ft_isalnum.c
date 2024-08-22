#include <stdbool.h>

// Returns true if the character 'c' is alphanumeric.
bool	ft_isalnum(char c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (true);
	return (false);
}
