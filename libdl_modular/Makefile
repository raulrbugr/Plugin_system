CC = gcc
CFLAGS=-Wall -ggdb -Idira -fPIC
LDFLAGS=-Ldira  -rdynamic
#LDLIBS = -la -ldl
LDLIBS =  -ldl

all: libs main 

main: main.o plugin.o

plugin.o: plugin.c plugin.h
	gcc -c plugin.c -o plugin.o

libs:
	$(MAKE) -C dira
	$(MAKE) -C dirb #The shared library

clean:
	$(RM) main *.o *~
	$(MAKE) -C dira clean
	$(MAKE) -C dirb clean
