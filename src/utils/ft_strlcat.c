#include <stdlib.h>			// size_t
#include "utils.h"			// ft_strlen

// Appends src to the end of dst. It will append at most dstsize - 
// strlen(dst) - 1 characters. It will then NUL-terminate, unless dstsize is 0
// or the original dst string was longer than dstsize.
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (dst[i] && i < dstsize)
		++i;
	if (dst[i] != '\0')
		return (i + ft_strlen(src));
	while (*src && i < dstsize)
	{
		dst[i] = *src;
		++i;
		++src;
	}
	return (i);
}
