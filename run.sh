#/bin/zsh

touch srcs/main.c
make
if [[ "$1" == '' ]]
then
	./fdf maps/42.fdf &
else
	./fdf $1 &
fi
