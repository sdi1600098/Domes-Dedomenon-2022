list3Reformed : list3.o DeleteLastNode.o InsertNewFirstNode.o InsertNewLastNode.o InsertNewSecondNode.o PrintList.o ListSearch.o
	gcc list3.o DeleteLastNode.o InsertNewFirstNode.o InsertNewLastNode.o InsertNewSecondNode.o PrintList.o ListSearch.o -o list3Reformed
list3.o : list3.c Prototypes.h Types.h
	gcc -c list3.c
DeleteLastNode.o : DeleteLastNode.c Prototypes.h Types.h
	gcc -c DeleteLastNode.c
InsertNewFirstNode.o : InsertNewFirstNode.c Prototypes.h Types.h
	gcc -c InsertNewFirstNode.c
InsertNewLastNode.o : InsertNewLastNode.c Prototypes.h Types.h
	gcc -c InsertNewLastNode.c
InsertNewSecondNode.o : InsertNewSecondNode.c Prototypes.h Types.h
	gcc -c InsertNewSecondNode.c
PrintList.o : PrintList.c Prototypes.h Types.h
	gcc -c PrintList.c
ListSearch.o : ListSearch.c Prototypes.h Types.h
	gcc -c ListSearch.c
clean :
	rm list3Reformed list3.o DeleteLastNode.o InsertNewFirstNode.o InsertNewLastNode.o InsertNewSecondNode.o PrintList.o