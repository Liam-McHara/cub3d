NAME		:= cub3D
CFLAGS		:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g
DFLAGS		= -MT $@ -MMD -MP

# Includes
INCDIR		= inc
INCFLAG		:= -I $(INCDIR)

# Libraries
MLX_DIR		:= MLX42
MLX_URL 	:= https://github.com/42-Madrid-Fundacion-Telefonica/MLX42.git 
MLX_FLAG	:= .mlx_flag
INCFLAG		+= -I $(MLX_DIR)/include/MLX42
LIBS		:= $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm

# Sources
SRC			:= main.c \
			check_args.c \
			cub3d.c \
			map/map_check_closed.c \
			map/map_free.c \
			minimap.c \
			movements/move.c \
			movements/move_dir.c \
			movements/move_rot.c \
			parse/parse.c \
			parse/parse_assets.c \
			parse/parse_color.c \
			parse/parse_map.c \
			parse/parse_texture.c \
			parse/set_player.c \
			raycast/init_ray.c \
			raycast/txt_draw.c \
			raycast/txt_init.c \
			raycast/raycasting.c \
			utils/color_tweak.c \
			utils/ft_atoi.c \
			utils/ft_isalnum.c \
			utils/ft_isnumber.c \
			utils/ft_isspace.c \
			utils/ft_memcpy.c \
			utils/ft_putendl_fd.c \
			utils/ft_putstr_fd.c \
			utils/ft_strchr.c \
			utils/ft_strdup.c \
			utils/ft_strjoin_free.c \
			utils/ft_strlcat.c \
			utils/ft_strlcpy.c \
			utils/ft_strlen.c \
			utils/ft_strncmp.c \
			utils/ft_strnstr.c \
			utils/ft_strrchr.c \
			utils/ft_strtrim.c \
			utils/ft_substr.c \
			utils/get_next_line.c \
			utils/isinset.c \
			utils/p_malloc.c \
			utils/put_err.c \
			utils/put_mlxerr.c \
			utils/put_syserr.c
SRCDIR		= src
SRCS		= $(addprefix $(SRCDIR)/, $(SRC))

# Objects
OBJDIR		= .obj
OBJS		= $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

# Dependencies
DEPDIR		= .dep/
DEPS		= $(addprefix $(DEPDIR), $(SRC:.c=.d))
DEPDIRS		= $(DEPDIR)map/ \
			$(DEPDIR)movements/ \
			$(DEPDIR)parse/ \
			$(DEPDIR)raycast/ \
			$(DEPDIR)utils/ \
			$(DEPDIR)debug/ \

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


all: $(MLX_FLAG) $(NAME)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c Makefile
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) $(DFLAGS) $(INCFLAG) -c $< -o $@
			@printf "\t$(YELLOW)$< $(GREEN)compiled$(DEFAULT)\n"
			@mkdir -p $(DEPDIR) $(DEPDIRS)
			@mv $(patsubst %.o,%.d,$@) $(subst $(OBJDIR),$(DEPDIR),$(@D))/

$(NAME)::	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(INCFLAGS) -o $(NAME)
			@echo "$(GREEN)[ $(BGREEN)$(NAME) $(GREEN)created! ]$(DEFAULT)"

$(NAME)::
			@echo "$(BLUE)[ All done already ]$(DEFAULT)"

clean:
	@rm -fr $(OBJDIR) $(DEPDIR) 
	@printf "$(RED)Object files removed\n$(DEFAULT)"

fclean:
	@rm -fr $(NAME) $(OBJDIR) $(DEPDIR)
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

bonus:	all

-include $(DEPS)

.PHONY: all, clean, fclean, re, mlx, mlxclean, norm, bonus
