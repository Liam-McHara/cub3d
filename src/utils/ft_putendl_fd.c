#include "utils.h"			// ft_putstr_fd
#include <unistd.h>			// write

// Outputs the 's' string to the given file descriptor followed by a newline.
void	ft_putendl_fd(const char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putstr_fd("\n", fd);
}
