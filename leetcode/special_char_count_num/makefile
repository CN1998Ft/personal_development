ifeq ($(OS), Windows_NT)
	CC := cl
	CFLAGS := -Zi -Fe:
	RM := rm
	TARGET := complied
	TOCLEAN := $(wildcard *.obj) $(wildcard *.ilk) $(wildcard *.pdb) \
			   $(wildcard *.exe)
else
	CC := gcc
	CFLAGS := -Wall -g -o
	RM := rm -rf
	TARGET := complied
	TOCLEAN := $(wildcard *.dSYM)
endif

.PHONY: clean all

all:
	$(CC) $(CFLAGS) $(TARGET) count_number_special_characters.c

clean:
	$(RM) $(TARGET) $(TOCLEAN)
