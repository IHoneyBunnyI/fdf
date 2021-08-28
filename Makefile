NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes #-g

FILES = main.c\
		utils.c

HEADERS = includes/fdf.h\

FILES_O = $(addprefix objs/, $(FILES))
SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(FILES_O:.c=.o)

objs/%.o : srcs/%.c 
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJS) Makefile $(HEADERS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re: fclean all
