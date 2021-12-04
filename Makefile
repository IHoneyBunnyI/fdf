NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Imlx -g -fsanitize=address
MLXFLAGS = -framework OpenGL -framework AppKit -Lmlx -lmlx
MLX_D = mlx/
MLX = $(MLX_D)libmlx.a

FILES =	color.c\
		color_gets.c\
		get_next_line.c\
		get_next_line_utils.c\
		utils.c\
		utils_2.c\
		bresenham.c\
		draw.c\
		keyboard_hooks.c\
		mouse_hooks.c\
		main.c\
		mlx.c\
		parse_map.c\
		xiaolin.c\
		parse_points.c\
		utils_parser.c\
		check_keys.c\
		iso_paralell.c\
		set_point.c\
		rotate.c\

#VPATH спецмальная переменная, в которой лежит список каталогов в которых следует выполнять поиск
VPATH = srcs/\
		srcs/colors/\
		srcs/draw/\
		srcs/gnl/\
		srcs/hooks\
		srcs/parser/\
		srcs/utils\

HEADERS = includes/fdf.h\
		  includes/get_next_line.h\

FILES_O = $(addprefix objs/, $(notdir $(FILES)))
SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(FILES_O:.c=.o)
OBJDIR = objs/

objs/%.o : %.c Makefile $(HEADERS) 
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir objs/
$(NAME) : $(MLX) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(MLXFLAGS) $(OBJS) -Lmlx -lmlx
	#@osascript -e 'display dialog "\t\t\t\t\t\tFDF\n\
		Basic instructions\n\n\
		Move:\t\t (\"w a s d\" or arrows)\n\
		Rotate:\t\t (NUM_PAD or \"h j k l\")\n\
		Zoom:\t\t (+ or -)\n\n\
		Additional instructions\n\n\
		Invert color:\t\t (C)\n\
		Ranom color:\t\t (shift + C)\n\
		Raindbow color:\t (ctrl + C)\n\
		Infinity rotate:\t (R)\n\
		Change height:\t (shift and +/-)\n\n\
		" buttons "OK"'

$(MLX):
	$(MAKE) -C $(MLX_D) 2>/dev/null

clean:
	$(MAKE) -C $(MLX_D) clean
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re: fclean all
