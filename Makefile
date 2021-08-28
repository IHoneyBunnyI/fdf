NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

FILES = main.c

SRCS = $(FILES)

HEADERS = fdf.h

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o : %.cpp Makefile $(HEADERS)
	$(CXX) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re: fclean all
