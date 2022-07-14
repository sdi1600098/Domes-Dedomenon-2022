OBJS	= main.o Implementation.o
SOURCE	= main.c Implementation.c
HEADER	= 
OUT	= test
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.c
	$(CC) $(FLAGS) main.c 

Implementation.o: Implementation.c
	$(CC) $(FLAGS) Implementation.c 


clean:
	rm -f $(OBJS) $(OUT)