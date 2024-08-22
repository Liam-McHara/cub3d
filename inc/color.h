#ifndef COLOR_H
# define COLOR_H

typedef union u_color
{
	struct
	{
		unsigned char	a;
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
	};
	unsigned int	rgba;
}	t_color;

#endif
