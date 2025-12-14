# hello:
# 	echo "Hello, World!"
# 	echo "This line will print if the file hello does not exist."

# CC=gcc
# blah: blah.o
# 	$(CC) blah.o -o blah
#
# blah.o: blah.c
# 	$(CC) -c blah.c -o blah.o
#
# blah.c:
# 	echo "int main(){return 0;}" > blah.c
#
# clean:
# 	rm -rf blah blah.o

# a := one two
# b := 'one two'
# all:
# 	printf '$a'
# 	printf $b

# x := dude
#
# all:
# 	echo $(x)
# 	echo ${x}
# 	# Bad practice
# 	echo x

# all: one two three
# one:
# 	touch one
# two:
# 	touch two
# three:
# 	touch three
#
# clean:
# 	rm -rf one two three

# all: f1.o f2.o
# f1.o f2.o:
# 	echo $@
# # Equivalent to:
# # f1.o:
# # 	echo f1.o
# # f2.o:
# # 	echo f2.o

# print: $(wildcard *.c)
# 	ls -la $?


# thing_wrong := *.o
# thing_right := $(wildcard *.o)
#
# all: one two three four
# 	ls -la $@
#
# one: $(thing_wrong)
#
# two: *.o
#
# three: $(thing_right)
#
# four: $(wildcard *.c)


# hey: one two
# 	echo $@
# 	echo $?
# 	echo $^
# 	echo $<
# 	touch hey
#
# one:
# 	touch one
#
# two:
# 	touch two
#
# clean:
# 	rm -rf hey one two

# CC = gcc
# CFLAGS = -g
#
# balah: blah.o
#
# blah.c:
# 	echo "int main(){return 0;}" > blah.c
#
# clean:
# 	rm -f blah*


# objects = foo.o bar.o all.o
# all: $(objects)
# 	$(CC) $^ -o all
#
# foo.o: foo.c
# 	$(CC) -c foo.c -o foo.o
#
# bar.o:bar.c
# 	$(CC) -c bar.c -o bar.o
#
# all.o: all.c
# 	echo "int main(){return 0;}" > all.c
#
# %.c:
# 	touch $@
#
# clean:
# 	rm -f *.c *.o


# objects: foo.o bar.o all.o
#
# all: $(objects)
# 	$(CC) $^ -o all
#
# $(objects): %.o: %.c
# 	$(CC) -c $^ -o $@
#
# all.c:
# 	echo "int main(){return 0;}" > all.c
# %.c:
# 	touch $@
#
# clean:
# 	rm -rf *.c *.o

# # PHONY test
# .PHONY: clean
# clean:
# 	rm *.o temp

# obj_files = foo.result bar.o lose.o
# src_files = foo.raw bar.c lose.c
#
# all: $(obj_files)
#
# .PHONY: all
#
# $(filter %.o, $(obj_files)): %.o: %.c
# 	echo "target: $@ prereq: $<"
#
# $(filter %.result, $(obj_files)): %.result: %.raw
# 	echo "target: $@, prereq: $<"
#
# %.c %.row:
# 	touch $@
#
# clean:
# 	rm -f $(src_files)


# all:
# 	@echo "This make line will not be printed"
# 	echo "But this will"


# all:
# 	cd ..
# 	pwd
#
# 	cd ..; pwd
#
# 	cd ..;\
# 	pwd


# SHELL=/usr/bin/env bash
# cool:
# 	bash --version


# make_var=I am a make variable
# all:
# 	sh_var='I am a shell variable'; echo $$sh_var
# 	echo $(make_var)


# one:
# 	-false
# 	touch one


# new_contents= "hello:\n\ttouch inside_file"
#
# all:
# 	mkdir -p subdir
# 	printf $(new_contents) | sed -e 's/^ //' > subdir/makefile
# 	cd subdir && $(MAKE)
#
# clean:
# 	rm -rf subdir


# shell_env_var=Shell env var, created inside of Make
# export shell_env_var
# all:
# 	echo $$shell_env_var
#
# 	echo $(shell_env_var)


# new_contents="hello:\n\techo \$$(cooly)"
#
# all:
# 	mkdir -p subdir
# 	printf $(new_contents) > subdir/makefile
# 	@echo "----MAKEFILE CONTENTS----"
# 	@cd subdir && cat makefile
# 	@echo "----END MAKEFILE CONTENTS----"
# 	cd subdir && $(MAKE)
#
#
# cooly = "The subdirectory can see me!"
# export cooly
#
# clean:
# 	rm -rf subdir


# one=this will only work locally
# export two=we can run subcommands with this
#
# all:
# 	@echo $(one)
# 	@echo $$one
# 	@echo $(two)
# 	@echo $$two


# .EXPORT_ALL_VARIABLE:
# new_contents = "hello\n\techo \$$(cooly)"
#
# cooly = "The subdirectory can see me!"
#
# all:
# 	mkdir -p subdir
# 	printf $(new_contents) | sed -e 's/^ //' > subdir/makefile
# 	@echo "-----Makefile contents-----"
# 	@cd subdir && cat makefile
# 	@echo "-----ENd of makefile contents-----"
# 	cd subdir && $(MAKE)
#
# clean:
# 	rm -rf subdir


# one = one ${later_variable}
# two := two ${later_variable}
# later_variable = later
#
# all:
# 	echo $(one)
# 	echo $(two)

# one = hello
# one := $(one) there
#
# all: 
# 	echo $(one)



# one = hello
# one ?= will not be set
# two ?= will be set
#
# all:
# 	@echo $(one)
# 	@echo $(two)


# with_spaces=hello 
# after = $(with_spaces)there
#
# nullstring=      
# space = $(nullstring) 
# all: 
# 	@echo "$(after)"
# 	@echo start"$(space)"end


# all:
# 	echo $(nowhere)


# foo := start
# foo +=more
# all:
# 	echo $(foo)


# override option_one = did_override
#
# option_two = not_override
#
# all:
# 	echo $(option_one)
# 	echo $(option_two)


# one = export blah="I was set!";echo $$blah
#
# define two
# export blah="I was set!"; echo $$blah
# endef
#
# all:
# 	@echo "This prints I was set"
# 	@$(one)
# 	@echo "This does not"
# 	@$(two)


# all: one = cool
#
# all:
# 	echo one is defined: $(one)
#
# other:
# 	echo one is nothing: $(one)


# %.c: one = cool
#
# blah.c:
# 	echo one is defined: $(one)
#
# other:
# 	echo one is nothing: $(one)


# foo = ok
#
# all:
# ifeq ($(foo),ok)
# 	echo "foo equals ok"
# else
# 	echo "nope"
# endif


# nullstring=
# foo = $(nullstring) 
# all:
# ifeq ($(strip $(foo)),)
# 	echo "foo is empty after being stripped"
# endif
# ifeq ($(nullstring),)
# 	echo "nullstring doesn't even have spaces"
# endif


# bar =
# foo = $(bar)
#
# all:
# ifdef foo
# 	echo "foo is defined"
# endif
# ifndef bar
# 	echo "bar is not defined"
# endif


# all:
# ifneq (,$(findstring i, $(MAKEFLAGS)))
# 	echo "i was passed to MAKEFLAGS"
# endif


# bar := ${subst not,totally, "I am not superman"}
# all:
# 	@echo $(bar)


# comma := ,
# empty:=
# space:= $(empty) $(empty)
# zoo:=$(foo)
# foo=a b c
# bar := $(subst $(space),$(comma),$(foo))
#
# all:
# 	@echo $(bar)
# 	@echo $(zoo)


# foo := a.o b.o l.a c.o
# one := $(patsubst %.o,%.c,$(foo))
# two:=$(foo:.o=.c)
# three:=$(foo:%.o=%.c)
#
# all:
# 	@echo $(one)
# 	@echo $(two)
# 	@echo $(three)


# foo:=who are you
# bar:=$(foreach wrd,$(foo),$(wrd)!)
#
# all:
# 	@echo $(bar)


# foo:=$(if this-is-not-empty,then!,else!)
# empty:=
# bar:=$(if $(empty),then!,else!)
#
# all:
# 	@echo $(foo)
# 	@echo $(bar)


# sweet_new_fn = Variable Name: $(0) First: $(1) Second: $(2) Empty Variable: $(3)
#
# all:
# 	@echo $(call sweet_new_fn, go, riger)


# all:
# 	@echo $(shell ls -la)


# obj_files = foo.result bar.o lose.o
# filtered_files=$(filter %.o, $(obj_files))
# all:
# 	@echo $(filtered_files)


# vpath %.h ../headers ../other-directory
#
# some_binary: ../headers blah.h
# 	touch some_binary
#
# ../headers: 
# 	mkdir ../headers
#
# blah.h:
# 	touch ../headers/blah.h
#
# clean:
# 	rm -rf ../headers
# 	rm -f some_binary


# some_file:
# 	echo This line is too long, so \
# 		it is broken up into multiple lines


# some_file:
# 	touch some_file
# 	touch clean
#
# .PHONY: clean
#
# clean:
# 	rm -rf some_file clean


.DELETE_ON_ERROR:
all: one two

one:
	touch one
	false

two:
	touch two
	false

clean:
	rm -rf one two
