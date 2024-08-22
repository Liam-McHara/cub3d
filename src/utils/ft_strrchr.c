#include "utils.h"			// ft_strlen

// Returns a pointer to the last occurrence of 'c' in the string 's'.
char	*strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char) c)
			return ((char *) s + i);
		--i;
	}
	return (NULL);
}
