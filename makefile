all: trab1

trab1: trab1.c trablib.o
	gcc -o trab1 trab1.c trablib.o -lm

trablib.o: trablib.c
	gcc -c trablib.c

clean:
	rm -rf *.o trab1