ifeq ($(OS), Windows_NT)
	CC := cl
	CFLAGS := -Zi
	RM := rm
	TARGET :=
	TOCLEAN := $(wildcard *.obj) $(wildcard *.pdb) $(wildcard *.ilk) \
			   $(wildcard *.exe)
else
	CC := gcc
	CFLAGS := -Wall -g -o
	RM := rm -f
	TARGET := hello
endif

.PHONY: clean all

all:
	$(CC) hello.c $(CFLAGS) $(TARGET)
	$(CC) count_number_special_characters.c $(CFLAGS) $(TARGET)


clean:
	$(RM) $(TARGET) $(TOCLEAN)
