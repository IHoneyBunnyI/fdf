#/bin/zsh

touch srcs/main.c
make
./fdf $1 &
