NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

FILES = main.c

HEADERS = fdf.h

OBJS = $(SRCS:.cpp=.o)

SRCS = $(addprefix srcs/, $(FILES))
$OBJS = $(addprefix objs/, $(OBJS))

all: $(NAME)

objs/%.o : srcs/%.c Makefile $(HEADERS) $(DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR) :
	mkdir objs
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re: fclean all
