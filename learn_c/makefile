# Choose compiler based on the OS
ifeq ($(OS),Windows_NT)
	CC = cl.exe
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Darwin)
		CC = clang
	endif
	ifeq ($(UNAME_S),Linux)
		CC = gcc
	endif
endif

.PHONY: help basic

# Help command
help:
	@echo "\n===================================HELP================================\n"
	@echo "To compile the program, Run: "
	@echo "make filename (without extension)"
	@echo "For example, to compile basic.c."
	@echo "Run: "
	@echo "make basic"
	@echo "\n===================================HELP================================\n"


basic: basic/ basic/basic.c
	$(CC) basic/basic.c -o basic/basic
	@./basic/basic
