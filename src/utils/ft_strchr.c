#include <unistd.h>				// NULL

// Returns a pointer to the first occurrence of 'c' in the string 's'.
char	*strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		++s;
	}
	if (c == '\0')
		return ((char *) s);
	return (NULL);
}
