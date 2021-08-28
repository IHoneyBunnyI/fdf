NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Imlx#-g
MLX = mlx/libmlx.a
MLX_D = mlx/

FILES = main.c\
		utils.c

HEADERS = includes/fdf.h\

FILES_O = $(addprefix objs/, $(FILES))
SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(FILES_O:.c=.o)

objs/%.o : srcs/%.c 
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(MLX) $(OBJS) Makefile $(HEADERS) 
	$(CC) $(CFLAGS) -o $(NAME) -framework OpenGL -framework AppKit -Lmlx -lmlx $(OBJS) 

$(MLX):
	$(MAKE) -C $(MLX_D) 2>/dev/null

clean:
	$(MAKE) -C $(MLX_D) clean
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re: fclean all
