#include <stdio.h>
#include "queue.c"

int main(){
    Queue Q;
    CreateQueue(&Q);
    // int i;
    // for(i=1;i<=5;i++){
    //     enqueue(&Q,i);
    // }
    // displayQueue(Q);
    // ElType x = 5;
    // dequeue(&Q,&x);
    displayQueue(Q);
}