CC = gcc
CFLAGS = -ansi -pedantic-errors -Wall -fstack-protector-all -Werror

banner.x: banner.c
	$(CC) $(CFLAGS) -g banner.c -o banner.x
