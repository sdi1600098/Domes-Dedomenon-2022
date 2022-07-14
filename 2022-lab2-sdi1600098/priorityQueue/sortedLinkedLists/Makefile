pqsort : sorting.o PQImplementation.o
	gcc sorting.o PQImplementation.o -o pqsort
sorting.o :sorting.c PQInterface.h PQTypes.h
	gcc -c sorting.c
PQImplementation.o :PQImplementation.c PQInterface.h PQTypes.h
	gcc -c PQImplementation.c
clean:
	rm pqsort sorting.o PQImplementation.o