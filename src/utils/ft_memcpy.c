#include <sys/types.h>			// size_t

// Copies 'n' bytes from 'src' to 'dest'. The memory areas must not overlap.
// Returns a pointer to 'dest'.
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char *) dest;
	s = (char *) src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		++i;
	}
	return (dest);
}
