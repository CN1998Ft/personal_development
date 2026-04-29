CC = gcc
CFLAGS = -Wall -g

.PHONY: clean all

all:
	$(CC) hello_world.c $(CFLAGS) -o hello_world
	$(CC) basic.c $(CFLAGS) -o basic -lm
	$(CC) parsing.c mpc.c $(CFLAGS) -o parsing -ledit -lm
	$(CC) doge.c mpc.c $(CFLAGS) -o doge

hello_world: hello_world.c
	$(CC) hello_world.c $(CFLAGS) -o hello_world

basic: basic.c
	$(CC) basic.c $(CFLAGS) -o basic -lm

parsing: parsing.c
	$(CC) parsing.c mpc.c $(CFLAGS) -o parsing -ledit -lm

doge: doge.c
	$(CC) doge.c mpc.c $(CFLAGS) -o doge
clean:
	rm hello_world basic parsing vgcore* core* *.dSYM
