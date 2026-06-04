ifeq ($(OS), Windows_NT)
	CC := cl
	CFLAGS := -Zi
	EXECUTABLE := pointer.exe
	# TOCLEAN := $(wildcard *.obj) $(wildcard *.pdb) $(wildcard *.ilk)\
	# 		   $(EXECUTABLE)
			   # $(wildcard *.exe)
	TOCLEAN := *.obj *.pdb *.ilk *.exe

else
	CC := gcc
	CFLAGS := -Wall -g
	EXECUTABLE := a.out
	TOCLEAN := $(wildcard *.out) $(wildcard *.dSYM)
endif

.PHONY: all clean

all:
	$(CC) $(CFLAGS) pointer.c
	./$(EXECUTABLE)


clean:
	rm -rf $(TOCLEAN)
