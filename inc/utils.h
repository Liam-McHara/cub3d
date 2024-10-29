#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>		// bool
# include <stdlib.h>		// size_t

// BASIC
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 512
# endif
# define BLANK_CHARS " \f\n\r\t\v"

int		ft_atoi(const char *str);
bool	ft_isalnum(char c);
bool	ft_isnumber(char c);
bool	ft_isspace(char c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putstr_fd(const char *s, int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin_free(char **s1, char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, const char *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
bool	isinset(char c, const char *set);
void	*p_malloc(size_t size);

// ERROR
# define ERROR_STR "Error"
# define ERRMSG_ARGS "Usage: cub3D mapfile.cub"
# define ERRMSG_ARGEXT "The map file must end with '.cub'"
# define ERRMSG_MAP_OPEN "Couldn't open map file"
# define ERRMSG_MAP_CLOSE "Couldn't close map file"
# define ERRMSG_MLX_INIT "Couldn't initiate MLX"
# define ERRMSG_MAP_BAD	"Bad formatted map file"
# define ERRMSG_MAP_CHAR "Invalid map character"
# define ERRMSG_MEMORY "Unable to allocate enought memory"
# define ERRMSG_MULTIPLAYER "There's more than one player on the map"
# define ERRMSG_MULTIDEFINE "Some element(s) defined more than once"
# define ERRMSG_AFTERMAP "There should be ABSOLUTELY nothing after the map"

int		put_err(const char *errmsg);
int		put_syserr(const char *errmsg);
int		put_mlxerr(const char *errmsg);

#endif
