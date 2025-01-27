RED		=	"\x1B[31m"
GRN		=	"\x1B[32m"
YEL		=	"\x1B[33m"
BLU		=	"\x1B[34m"
MAG		=	"\x1B[35m"
CYN		=	"\x1B[36m"
WHT		=	"\x1B[37m"
RST		=	"\x1B[0m"
CLE 	=	\e[1;1H\e[2J

NAME	=	cub3d
LIBFT	=	libft.a
LDIR	=	libft/
SRCS	=	./srcs/


USER = $(shell whoami)


# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -g -O3
RM	=	rm	-f
LIBS = -lpthread -lncurses -lm -lz
MLX_PATH = MLX42/build
GLFW_PATH = $(shell brew --prefix glfw)/lib
PLATFORMFLAGS = -L$(MLX_PATH) -lMLX42 -L$(GLFW_PATH) -lglfw -framework OpenGL -framework AppKit

#-fsanitize=address
# Sources are all .c files
SRCS	=	./srcs/main.c\
			./srcs/checking.c\
			./srcs/cub3d.c\
			./srcs/settings.c\
			./srcs/check_config.c\
			./srcs/check_config_utils.c\
			./srcs/utils.c\
			./srcs/check_map.c\
			./srcs/raycasting.c\
			./srcs/raycasting_utils.c\
			./srcs/rendering.c\
			./srcs/rendering_utils.c\
			./srcs/check_map_utils.c\
			./srcs/keybindings.c\
			./srcs/movements.c\
			./srcs/flood_fill.c\





OBJS	=	$(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -I$(MLX_PATH) -c $< -o $@ 


all: libft mlx $(NAME)
	@echo $(shell reset) $(GRN) $(NAME) $(RST) $(GRN) "compiled" $(RST)
# Generates output file
mlx:
	@if [ ! -d "$(MLX_PATH)" ]; then \
		echo $(GRN)"MLX42 not found, $(RST) cloning and building..."; \
		git clone https://github.com/codam-coding-college/MLX42.git MLX42; \
		cd MLX42; \
		cmake -B build; \
		cmake --build build -j4; \
	else \
		echo $(GRN)"MLX42 found."$(RST); \
		sleep 1; \
	fi

libft:
	@echo $(GRN)"Compiling libft..."$(RST)
	@$(MAKE) -s -C $(LDIR)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDIR)$(LIBFT) -L$(MLX_PATH) $(PLATFORMFLAGS) $(LIBS) -o $(NAME)

# Removes objects
clean:
	$(RM) $(OBJS)
	@make -C $(LDIR) clean
	@echo $(shell clear) clean *.o

# Removes objects and executables
fclean: clean
	$(RM) $(NAME)
	@make -C $(LDIR) fclean
	@echo $(shell clear)  clean all

# Removes objects and executables and remakes
re: fclean all

.PHONY: all libft re clean fclean