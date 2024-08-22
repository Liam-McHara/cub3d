#include "utils.h"			// ft_strlen
#include <unistd.h>			// write

// Outputs the 's' string to the given file descriptor followed by an endline.
void	ft_putstr_fd(const char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	write(fd, s, len);
}
