#include <stdlib.h>
#include "Actions.h"
#include <stdio.h>

int main(void){ 

    link last;
    link x;
    int Count = 0;
    Create(&last);                                      //Ενδεικτική εκτέλεση :
    Add(&last, &x, &Count);                             //
    //printf("%d\n",last->item);                        //Δημιουργία μιας κενής κυκλικής λίστας. Η λίστα αυτή αποκτά 3 στοιχεία.

    Add(&last, &x, &Count);                             //Τα : 1, 2, 3 αντίστοιχα.
    //printf("%d\n",last->item);

    Add(&last, &x, &Count);                             //Έπειτα αφαιρείται το επόμενο στοιχείο από εκείνο που δείχνει ο δρομέας(last), δηλαδή τον κόμβο 1
    //printf("%d\n",last->item);

    link removed = Remove(&last, &x);
    //printf("%d\n",last->item);

    Add(&last, &x, &Count);                             //Πρόσθεση ενός ακόμα κόμβου με νούμερο 4. Αρα η λίστα περιέχει τους κόμβους 2, 3, 4.
    //printf("%d\n",last->item);

    //printf("kounima dromea\n");

    Advance(&last);                                     //Ο δρομέας προχωράει μία θέση.
    //printf("%d\n",last->item);
}