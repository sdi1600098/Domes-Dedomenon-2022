#include <stdlib.h>
#include <stdio.h>
#include "Actions.h"

void Create(link *last){                                    //Ο δρομέας δείχνει NULL
    (*last) = NULL;
}

void Add(link *last, link *x, int *Count){                  //Οι θέσεις αυξάνονται κατά μία
    *Count += 1;
    (*x) = malloc(sizeof **x);                              //Δεύσμευση νέου κόμβου

    if(*last == NULL){                                      //Αν ο δρομέας δείχνει NULL τότε ο πρώτος κόμβος παίρνει τιμή 1 και δείχνει πίσω στον εαυτό του
    
        (*x)->item = 1;
        (*x)->next = *x;
        (*last) = (*x);
        
    }
    else {                                                  //Αλλιώς ο νέος κόμβος παίρνει τιμή 'Count' και δείχνει πίσω στον πρώτο(επειδή με κάθε Add κουνάω και το δρομέα)
        //(*x) = ((*x)->next = malloc(sizeof **x));
        (*x)->item = *Count;
        (*x)->next = (*last)->next;
        (*last)->next = (*x);                               //Μετακίνηση δρομέα (επεξήγηση στο Σημειώσεις.pdf)
        (*last) = (*x);                                     //Αν δε θέλουμε μετακίνηση δρομέα μετά από κάθε add βάζουμε σε σχόλιο τις γραμμές 24 και 25.
    }
}

link Remove(link *last, link *x){                           //Διαγραφή 
    
    (*x)->next = (*x)->next->next;
    link temp = (*last)->next;
    return temp;
}

void Advance(link *dromeas, link *x){
    (*x) = (*x)->next;
    (*dromeas) = (*x);
}