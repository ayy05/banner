CC = gcc

all: banner.x opposite.x

banner.x: banner.c
	$(CC) -g banner.c -o banner.x

opposite.x: opposite.c
	$(CC) -g opposite.c -o opposite.x

