ifeq ($(OS), Windows_NT)
	CC := cl.exe
	CFLAGS := -Zi -std:c11
	EXECUTABLE := chap3.exe
	TOCLEAN := *.obj *.ilk *.pdb *.exe
else
	CC := gcc
	CFLAGS := -Wall -g
	EXECUTABLE := a.out
	TOCLEAN := $(wildcard *.dSYM) $(wildcard *.out)
endif

.PHONY: clean all

all:
	$(CC) $(CFLAGS) chap3.c
	./$(EXECUTABLE)

clean:
	rm -rf $(TOCLEAN)
