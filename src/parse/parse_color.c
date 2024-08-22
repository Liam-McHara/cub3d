#include "parse_private.h"		// CEILING_C, FLOOR_C
#include "assets.h"				// t_assets
#include "utils.h"				// ft_strtrim, ft_strchr, ft_atoi, put_err ...
#include <stdlib.h>				// free
#include "color.h"				// t_color

// Sets the color of the given color type.
// If it has already been set, prints an error message and exits gracefully.
static void	set_color(t_assets *a, t_color *color, t_color_type type)
{
	static bool ceiling_set = false;
	static bool floor_set = false;
	
	if (type == C_CEILING)
	{
		if (ceiling_set)
			exit(put_err(ERRMSG_MULTIDEFINE));
		a->c = (int) color->rgba;
		ceiling_set = true;
	}
	if (type == C_FLOOR)
	{
		if (floor_set)
			exit(put_err(ERRMSG_MULTIDEFINE));
		a->f = (int) color->rgba;
		floor_set = true;
	}

}

// Checks if 'str' follows the color setting syntax ("number,number,number").
// If the check fails, prints an error message and exits gracefully.
static void	check_color_syntax(const char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (ft_isnumber(str[i]))
		++i;
	if (str[i] != ',' || i > 3 || i < 1)
		exit(put_err(ERRMSG_MAP_BAD));
	while (ft_isnumber(str[i + j + 1]))
		++j;
	if (str[i + j + 1] != ',' || j > 3 || j < 1)
		exit(put_err(ERRMSG_MAP_BAD));
	while (ft_isnumber(str[i + j + k + 2]))
		++k;
	if (str[i + j + k + 2] != '\0' || k > 3 || k < 1)
		exit(put_err(ERRMSG_MAP_BAD));
}

// Returns the numeric value of 'str' as an unsigned char.
// If's not between 0 and 255, prints an error message and exits gracefully.
static unsigned char	get_color_value(const char *str)
{
	int	value;

	value = ft_atoi(str);
	if (value < 0 || value > 255)
		exit(put_err(ERRMSG_MAP_BAD));
	return ((unsigned char) value);
}

// Parses 'str' and sets the color asset specified by 'color_type'.
void	parse_color(t_assets *a, const char *str, t_color_type type)
{
	char	*color_str;
	t_color	color;

	color_str = ft_strtrim(str, BLANK_CHARS);
	check_color_syntax(color_str);
	color.r = get_color_value(color_str);
	color.g = get_color_value(ft_strchr(color_str, ',') + 1);
	color.b = get_color_value(ft_strrchr(color_str, ',') + 1);
	free(color_str);
	set_color(a, &color, type);
}
