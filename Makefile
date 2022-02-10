NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Imlx -g -Ofast -fsanitize=address
MLXFLAGS = -framework OpenGL -framework AppKit -Lmlx -lmlx
MLX_D = mlx/
MLX = $(MLX_D)libmlx.a

FILES =	color.c\
		color_gets.c\
		bresenham.c\
		draw.c\
		draw_util.c\
		iso_paralell.c\
		mlx.c\
		rotate.c\
		set_point.c\
		xiaolin.c\
		xiaolin_util.c\
		xiaolin_util2.c\
		xiaolin_util3.c\
		get_next_line.c\
		get_next_line_utils.c\
		check_keys.c\
		colors_actions.c\
		key_down_up_util.c\
		keyboard_hooks.c\
		mouse_hooks.c\
		rotate_R.c\
		translate.c\
		z_coordinate.c\
		zoom.c\
		parse_map.c\
		parse_map_util.c\
		parse_points.c\
		utils_parser.c\
		init.c\
		utils.c\
		utils_2.c\
		main.c\

#VPATH спецмальная переменная, в которой лежит список каталогов в которых следует выполнять поиск
VPATH = srcs/\
		srcs/colors/\
		srcs/draw/\
		srcs/draw/xiaolin/\
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

NB = $(words $(FILES))
INDEX = 0

objs/%.o : %.c Makefile $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval PERCENT=$(shell expr $(INDEX) '*' 100 / $(NB)))
	@$(eval PROGRESS=$(shell expr $(INDEX) '*' 30 / $(NB)))
	@printf "\r\033[38;5;87mMAKE FDF %2d%%\033[0m \033[48;5;32m%*s\033[0m %s\033[K" $(PERCENT) $(PROGRESS) "" $(notdir $@)
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir objs/
$(NAME) : $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(MLXFLAGS) $(OBJS) -Lmlx -lmlx
	@printf "\r\033[38;5;82mFDF DONE\033[0m\033[K\n"
	@osascript -e 'display dialog "\t\t\t\t\t\tFDF\n\
		Basic instructions\n\n\
		Move:\t\t (\"w a s d\" or arrows)\n\
		Rotate:\t\t (NUM_PAD or \"h j k l\")\n\
		Zoom:\t\t (+ or -)\n\n\
		Mouse controls\n\n\
		Rotate:\t\t(left click and wheel)\n\
		Move:\t\t(right click)\n\
		Zoom:\t\t(spin the wheel)\n\n\
		Additional instructions\n\n\
		Parallel projection: (P)\n\
		Invert color:\t\t (C)\n\
		Ranom color:\t\t (shift + C)\n\
		Reset color:\t\t (option + C)\n\
		Raindbow color:\t (ctrl + C)\n\
		Infinity rotate:\t (R)\n\
		Around an axis\t (Shift + G)\n\
		Change height:\t (shift and +/-)\n\
		Starting position:\t (i)\n\
		" buttons "OK"' > /dev/null &

$(MLX):
	@$(MAKE) -C $(MLX_D) 2>/dev/null

clean:
	@$(MAKE) -C $(MLX_D) clean
	@rm -rf $(OBJS)
	@printf "\033[38;5;85mCLEAN\033[0m\n"

fclean : clean
	@rm -rf $(NAME)
	@printf "\033[38;5;84mFULL CLEAN\033[0m\n"

re: fclean all
