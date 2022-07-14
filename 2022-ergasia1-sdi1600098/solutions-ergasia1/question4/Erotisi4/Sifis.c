#include <stdio.h>
#include <stdlib.h>
#include "Actions.h"

int main (int argv, char *argc[]){
    int N = atoi(argc[1]);                      //Οι αριθμοί στη γραμμή ορισμάτων μπαίνουν στις μεταβλητές N, M, P
    int M = atoi(argc[2]);
    int P = atoi(argc[3]);
    int i;
    //printf("PAME\n");
    int count = 0;
    link x;
    link dromeas;
    Create(&dromeas);                                       //Δημιουργία κενής λίστας κι έπειτα γέμισμα αυτής με 'Ν' κόμβους
    for(i = 1 ; i <= N ; i++){
        Add(&dromeas, &x, &count);
        
        //printf("Added : %d\n", x->item);
    }
    //printf("\n");
    while(x->item != P){                                    //Προσπέλαση της λίστας μέχρι την εύρεση του κόμβου με αριθμό ίσο με 'P'
        Advance(&dromeas, &x);
        //printf("noumero : %d\n", x->item);
    }
                                                            
    //printf("\n");                                         
    while (N > 1) {                                         //ΕΚΚΙΝΗΣΗ ΕΞΟΝΤΩΣΗΣ
        for (i = 1; i < M; i++){                            //Προσπέλαση 'Μ-1' κόμβων
            Advance(&dromeas, &x);
        
        }
        //printf("dromeas : %d\n", dromeas->item);
        //printf("x = %d\n",x->item);
        printf("Θα εξοντωθεί ο Σφακιανός στη θέση : %d\n",dromeas->next->item);
        link removed = Remove(&dromeas, &x);                                        //Αφαίρεση του Μ-οστού κόμβου
        //printf("removed : %d\n",removed->item);
        N--;
    }
    printf("Σήφη, άραξε στη θέση %d για να μη σε τουφεκίσουν\n", x->item);          //Last Man Standing
    
}