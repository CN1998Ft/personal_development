ifeq ($(OS), Windows_NT)
	CC := cl
	CFLAGS:= -Zi
	EXECUTABLE := algo.exe
	TOCLEAN := $(wildcard *.obj) $(wildcard *.pdb) $(wildcard *.ilk) \
			   $(wildcard *.exe)
else
	CC := gcc
	CFLAGS := -Wall -g -o
	EXECUTABLE := a.out
	TOCLEAN := $(wildcard *.dSYM) $(wildcard *.out)
endif

.PHONY: clean all

all:
	$(CC) $(CFLAGS) $(EXECUTABLE) algo.c
	./$(EXECUTABLE)

clean:
	rm -rf $(TOCLEAN)
