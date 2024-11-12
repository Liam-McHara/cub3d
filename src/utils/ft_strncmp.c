#include <sys/types.h>			// size_t

// Compares the first 'n' bytes of 's1' and 's2', returning 0, a negative value
// or a positive value if 's1' is equal, less or greater than 's2'.
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (!s1[i] || !s2[i] || s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		++i;
	}
	return (0);
}
