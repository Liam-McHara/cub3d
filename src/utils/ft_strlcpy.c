#include <stdlib.h>				// size_t
#include "utils.h"				// ft_strlen

// Copies up to dstsize - 1 characters from src to dst, NUL-terminating the
// result if dstsize is not 0.
// If src and dst overlap, the behavior is undefined.
// Returns the total lenght of the string it tried to create.
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	i = 0;
	while (src && src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}
