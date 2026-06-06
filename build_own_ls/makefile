ifeq ($(OS), Windows_NT)
	CC := cl.exe
	CFLAGS := -Zi -std:c11 -Fe:own_ls.exe -Fo:own_ls.obj
	# EXECUTABLE :=
	LIBS :=
	TOCLEAN := *.obj *.pdb *.exe *.ilk
else
	CC := gcc
	CFLAGS := -Wall -g -o
	EXECUTABLE := own_ls
	LIBS :=
	TOCLEAN := *.out *.dSYM $(EXECUTABLE)
endif

.PHONY: all clean

all:
	$(CC) $(CFLAGS) $(EXECUTABLE) ls.c

clean:
	rm -rf $(TOCLEAN)
