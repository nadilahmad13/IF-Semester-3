#include <stdio.h>
#include <stdlib.h>
#include "listlinier2.c"

int main(){
    // create list
    List L;
    CreateEmpty(&L);
    // insert 1 to 5 to the list
    int i;
    for (i = 1; i <= 5; i++){
        InsVLast(&L, i);
    }
    PrintInfo(L);

    //DelLast
    address P;
    DelLast(&L, &P);

    PrintInfo(L);
    return 0;
}