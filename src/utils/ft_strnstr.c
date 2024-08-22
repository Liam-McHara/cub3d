#include "utils.h"				// ft_strlen, ft_strncmp
#include <sys/types.h>			// size_t

// If 'little' is empty, 'big' is returned. If 'little' is not found in 'big',
// returns NULL. Otherwise, returns a pointer to the first character of the
// first occurrence of 'little' in 'big'.
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	if (!little || !big)
		return (NULL);
	little_len = ft_strlen(little);
	i = 0;
	while (big[i] && i + little_len <= len)
	{
		if (!ft_strncmp(big + i, little, little_len))
			return ((char *) big + i);
		++i;
	}
	return (NULL);
}
