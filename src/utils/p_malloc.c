#include <stdlib.h>		// malloc
#include "utils.h"		// put_syserr

void	*p_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exit(put_syserr(ERRMSG_MEMORY));
	return (ptr);
}
