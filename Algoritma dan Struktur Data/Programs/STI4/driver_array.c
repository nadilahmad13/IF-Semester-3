#include <stdio.h>
#include "array.c"

int main(){
    TabInt T;
    MakeEmpty(&T);
    int i;
    for (i = 0; i <= 80; i++){
        SetEl(&T, i, i);
    }

    // print first and last index
    printf("First index: %d\n", GetFirstIdx(T));
    printf("Last index: %d\n", GetLastIdx(T));

    // tulisis
    TulisIsi(T);

    return 0;
}