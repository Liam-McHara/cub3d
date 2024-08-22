NAME	:= cub3D
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast

MLX_DIR	:= ./MLX42
MLX_URL := https://github.com/42-Madrid-Fundacion-Telefonica/MLX42.git 
MLX_FLAG:= .mlx_flag

HEADERS	:= -I ./inc -I $(MLX_DIR)/include/MLX42
LIBS	:= $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= ./src/main.c \
			./src/check_args.c \
			./src/map_check.c \
			./src/cub3d.c \
			./src/draw_minimap.c \
			./src/movements.c \
			./src/parse/parse.c \
			./src/parse/parse_assets.c \
			./src/parse/parse_color.c \
			./src/parse/parse_map.c \
			./src/parse/parse_texture.c \
			./src/utils/ft_atoi.c \
			./src/utils/ft_isalnum.c \
			./src/utils/ft_isnumber.c \
			./src/utils/ft_isspace.c \
			./src/utils/ft_memcpy.c \
			./src/utils/ft_putendl_fd.c \
			./src/utils/ft_strchr.c \
			./src/utils/ft_strjoin_free.c \
			./src/utils/ft_strlcat.c \
			./src/utils/ft_strlcpy.c \
			./src/utils/ft_strlen.c \
			./src/utils/ft_strncmp.c \
			./src/utils/ft_strnstr.c \
			./src/utils/ft_strrchr.c \
			./src/utils/ft_strtrim.c \
			./src/utils/ft_substr.c \
			./src/utils/get_next_line.c \
			./src/utils/p_malloc.c \
			./src/utils/put_err.c \
			./src/utils/put_mlxerr.c \
			./src/utils/put_syserr.c \
			./src/raycast/draw.c \
			./src/raycast/raycasting.c
OBJS	:= ${SRCS:%.c=%.o}

# Colors
WHITE		= \033[0;37m
GREEN		= \033[0;32m
RED			= \033[0;31m
BLUE		= \033[0;34m
YELLOW		= \033[0;33m
DEFAULT		= \033[0m
BGREEN		= \033[1;32m
BRED		= \033[1;31m
BBLUE		= \033[1;34m
BYELLOW		= \033[1;33m

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(MLX_FLAG)  $(OBJS) Makefile
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@printf "$(BGREEN)$(NAME) built ✅\n$(DEFAULT)"

clean:
	@rm -fr $(OBJS)
	@printf "$(RED)Object files removed\n$(DEFAULT)"

fclean:
	@rm -fr $(NAME) $(OBJS)
	@printf "$(BRED)$(NAME) and object files removed\n$(DEFAULT)"

$(MLX_FLAG):
	@if [ ! -f $(MLX_FLAG) ] ; then \
		printf "$(BLUE)Cloning MLX...\n$(DEFAULT)" && \
		git clone --quiet $(MLX_URL) && \
		printf "$(BLUE)Building MLX...\n$(DEFAULT)" && \
		cmake -DCMAKE_RULE_MESSAGES=OFF $(MLX_DIR) -B $(MLX_DIR)/build && \
		make -s -C $(MLX_DIR)/build -j4 && \
		touch $(MLX_FLAG) && \
		printf "$(GREEN)MLX installed ✅\n$(DEFAULT)"; \
	else \
		printf "$(GREEN)MLX already installed\n$(DEFAULT)"; \
	fi

mlxclean:
	@rm -fr $(MLX_DIR) $(MLX_FLAG)
	@printf "$(RED)MLX removed\n$(DEFAULT)"

re: clean all

norm:
	@norminette $(SRCS) inc

.PHONY: all, clean, fclean, re, mlx, mlxclean, norm
