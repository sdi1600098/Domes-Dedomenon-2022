test : Implementation.o main.o
	gcc Implementation.o main.o -o test
Implementation.o : Implementation.c GraphT.h Actions.h
	gcc -c Implementation.c
main.o : main.c GraphT.h Actions.h
	gcc -c main.c
clean :
	rm test main.o Implementation.o