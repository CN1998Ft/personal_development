ifeq ($(OS), Windows_NT)
	CC := cl
	CFLAGS:= -Zi -std:c11
	EXECUTABLE := algo.exe
	# TOCLEAN := $(wildcard *.obj) $(wildcard *.pdb) $(wildcard *.ilk) \
	# 		   $(wildcard *.exe)
	TOCLEAN := *.obj *.pdb *.ilk *.exe
else
	CC := gcc
	CFLAGS := -Wall -g
	EXECUTABLE := a.out
	TOCLEAN := $(wildcard *.dSYM) $(wildcard *.out)
endif

.PHONY: clean all

all:
	$(CC) $(CFLAGS) algo.c
	./$(EXECUTABLE)

clean:
	rm -rf $(TOCLEAN)
