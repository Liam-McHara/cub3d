#include <stdbool.h>			// bool: true, false

// Returns true if 'c' is a white-space character. Ohterwise, returns false.
bool	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (true);
	return (false);
}
