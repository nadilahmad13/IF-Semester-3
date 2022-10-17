#include <stdio.h>
#include "queue.c" // knp gabisa incl header?

// driver queue.c
int main(){
    Queue Q;
    CreateQueue(&Q);
    printf("%d\n", isEmpty(Q));
    printf("%d\n", isFull(Q));
    printf("%d\n", length(Q));
    displayQueue(Q);
    int i;
    for (i=0; i<=5; i++){
        enqueue(&Q, i);
    }
    printf("%d\n", length(Q));
    displayQueue(Q);
    int val;
    dequeue(&Q, &val);
    printf("%d\n", length(Q));
    displayQueue(Q);
    return 0;
}