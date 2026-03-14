CC = gcc
CFLAGS = -Wall -g

all: 
	$(CC) hello_world.c $(CFLAGS) -o hello_world
	$(CC) basic.c $(CFLAGS) -o basic -lm
	$(CC) prompt.c $(CFLAGS) -o prompt -ledit
	$(CC) doge.c mpc.c $(CFLAGS) -o doge

hello_world: hello_world.c
	$(CC) hello_world.c $(CFLAGS) -o hello_world

basic: basic.c
	$(CC) basic.c $(CFLAGS) -o basic -lm

prompt: prompt.c
	$(CC) prompt.c $(CFLAGS) -o prompt -ledit

doge: doge.c
	$(CC) doge.c mpc.c $(CFLAGS) -o doge
clean:
	rm hello_world basic prompt
