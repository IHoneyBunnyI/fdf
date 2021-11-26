NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Imlx -g -fsanitize=address
MLXFLAGS = -framework OpenGL -framework AppKit -Lmlx -lmlx
MLX = mlx/libmlx.a
MLX_D = mlx/

FILES = main.c\
		utils.c\
		utils_2.c\
		get_next_line.c\
		get_next_line_utils.c\
		hooks.c\
		draw.c\
		mlx.c\
		bresenham.c\
		xiaolin.c\
		color.c\

HEADERS = includes/fdf.h\
		  includes/get_next_line.h\

FILES_O = $(addprefix objs/, $(FILES))
SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(FILES_O:.c=.o)
OBJDIR = objs/

objs/%.o : srcs/%.c Makefile $(HEADERS) 
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir objs/
$(NAME) : $(MLX) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(MLXFLAGS) $(OBJS) -Lmlx -lmlx

$(MLX):
	$(MAKE) -C $(MLX_D) 2>/dev/null

clean:
	$(MAKE) -C $(MLX_D) clean
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re: fclean all
