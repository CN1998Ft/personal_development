CC = gcc
CFLAGS = -Wall -g

all: hello_world.c basic.c
	$(CC) hello_world.c $(CFLAGS) -o hello_world
	$(CC) basic.c $(CFLAGS) -o basic -lm
	$(CC) prompt.c $(CFLAGS) -o prompt -ledit

hello_world: hello_world.c
	$(CC) hello_world.c $(CFLAGS) -o hello_world

basic: basic.c
	$(CC) basic.c $(CFLAGS) -o basic -lm

prompt: prompt.c
	$(CC) prompt.c $(CFLAGS) -o prompt -ledit

clean:
	rm hello_world basic prompt
