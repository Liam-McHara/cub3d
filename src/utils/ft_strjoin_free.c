#include "utils.h"				// ft_strlen, ft_strlcat, ft_strlcpy
#include <stdlib.h>				// malloc, free
#include <sys/types.h>			// size_t

// Allocates (with malloc(3)) and returns a new string, which is the result of
// the concatenation of ’s1’ and ’s2’.
// Finally, 's1' is freed and the new returned string is pointed by 's1'.
char	*ft_strjoin_free(char **s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	strsize;
	char	*str;

	s1_len = ft_strlen(*s1);
	s2_len = ft_strlen(s2);
	strsize = s1_len + s2_len + 1;
	str = malloc(strsize * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, *s1, strsize);
	ft_strlcat(str, s2, strsize);
	free(*s1);
	*s1 = str;
	return (str);
}
