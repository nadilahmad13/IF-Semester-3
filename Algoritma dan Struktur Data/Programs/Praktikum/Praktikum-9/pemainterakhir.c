#include <stdio.h>
#include "list_circular.c"

int main(){
    // variable initialization
    int i,N,K;
    scanf("%d",&N);
    scanf("%d",&K);

    List l;
    CreateList(&l);

    for (i = 1 ; i <= N ; i++){
        insertLast(&l,i);
    }
    
    boolean endGame = false;
    Address loc;
    Address temp;
    int val;
    int pop;
    int tempo = 0;
    while(!endGame){
        tempo++;        int val = K;
        loc = FIRST(l);
        while (val > 1){
            loc = NEXT(loc);
            val--;
        }
        pop = INFO(loc);
        FIRST(l) = loc;
        deleteFirst(&l,&val);
        if (tempo != N){
            printf("%d\n",pop);
        }
        else{
            printf("Pemenang %d\n",pop);
        }
        if (NEXT(loc) == NULL || isEmpty(l)){
            endGame = true;
        }
    }

    return 0;
}