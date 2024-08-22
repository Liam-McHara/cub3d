#include "utils.h"				// ft_strlen, p_malloc, isinset

// Allocates and returns a copy of 's1' with the characters specified in
// 'set' removed from the beginning and the end of the string.
char	*ft_strtrim(char const *s1, const char *set)
{
	char	*s2;
	int		i;

	while (*s1 && isinset(*s1, set))
		++s1;
	i = ft_strlen(s1) - 1;
	while (s1[i] && isinset(s1[i], set))
		--i;
	s2 = (char *) p_malloc((i + 2) * sizeof(char));
	ft_memcpy(s2, s1, i + 1);
	s2[i + 1] = '\0';
	return (s2);
}
