#include <stdio.h>
#include "reverse.c"

int main(){
    Queue Q1;
    Q1.HEAD = 0;
    Q1.TAIL = 5;
    Q1.MaxEl = 10;
    int i;
    for (i=0; i<=5; i++){
        Q1.Tab[i] = i;
    }
    printf("[%d,%d,%d,%d,%d,%d]", Q1.Tab[1], Q1.Tab[2], Q1.Tab[3], Q1.Tab[4], Q1.Tab[5]);
    return 0;
}