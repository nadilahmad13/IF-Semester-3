// Nama : Rania Sasi Kirana
// NIM : 18221168
// Tanggal : 15 Oktober 2022
// Topik Praktikum : Queue
// Pra Praktikum 6 No. 3
// Deskripsi: Implementasi reverse.h

#include <stdio.h>
#include <stdlib.h>
#include "circular_queue.c"
#include "reverse.h"

void transferReverse(Queue* q1, Queue* q2)
{
    int i, temp;
    for (i = 0; i < Length(*q1); i++){
        temp = Pop(q1);
        Push(q2, temp);
    }
}

int main(){
    Queue Q1, Q2;
    int i, temp;
    Q1 = CreateQueue(5);
    Q2 = CreateQueue(5);
    Q1.Tab[0] = 1;
    Q1.Tab[1] = 2;
    Q1.Tab[2] = 3;
    Q1.Tab[3] = 4;
    Q1.Tab[4] = 5;
    Q1.HEAD = 0;
    Q1.TAIL = 4;

    // print Q1
    printf("Q1: ");
    for (i = 0; i < Length(Q1); i++){
        printf("%d ", Q1.Tab[i]);
    }

    transferReverse(&Q1, &Q2);
    return 0;
}