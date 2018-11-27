all: trab1

trab1: trab1.c trablib.h trablib.o
	gcc -o trab1 trab1.c trablib.o -lm -O2

trablib.o: trablib.c
	gcc -c -O2 trablib.c

clean:
	rm -rf *.o trab1