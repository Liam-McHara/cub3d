// Tweaks the color to fix the endian-related bug in Linux systems. 
int	color_tweak(int	color)
{
	int	r;
	int	g;
	int	b;
	int	new_color;

	r = color & 0xFF;
	g = (color >> 8) & 0xFF;
	b = (color >> 16) & 0xFF;
	new_color = r << 24 | g << 16 | b << 8 | 0xFF;
	return (new_color);
}
