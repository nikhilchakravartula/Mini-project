# Makefile
# CS 2200 PRJ6

src=scheduler.c simulator.c process.c
obj=scheduler.o simulator.o process.o
inc=simulator.h process.h
misc=Makefile
target=simulator
cflags=-Wall -g -O0 -Werror -pedantic -ansi
lflags=-lpthread

all: $(target)

$(target) : $(obj) $(misc)
	gcc $(cflags) -o $(target) $(obj) $(lflags)

%.o : %.c $(misc) $(inc)
	gcc $(cflags) -c -o $@ $<

clean:
	rm -f $(obj) $(target)
