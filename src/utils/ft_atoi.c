#include "utils.h"				// ft_isspace, ft_isnumber

// Converts the initial portion of 'str' to int.
int	ft_atoi(const char *str)
{
	int	n;
	int	sign;

	if (!*str)
		return (0);
	n = 0;
	sign = 1;
	while (*str && ft_isspace(*str))
		++str;
	while (*str && (*str == '-' || *str == '+'))
	{
		if (*str == -1)
			sign *= -1;
		++str;
	}
	while (*str && ft_isnumber(*str))
	{
		n *= 10;
		n += *str - '0';
		++str;
	}
	return (n * sign);
}
