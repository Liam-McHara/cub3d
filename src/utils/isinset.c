#include <stdbool.h>			// bool: true, false

// Returns true if 'c' is included in 'set'. Returns false otherwise.
bool	isinset(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (true);
		++set;
	}
	return (false);
}
