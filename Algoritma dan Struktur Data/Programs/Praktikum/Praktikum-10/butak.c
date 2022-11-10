#include <stdio.h>
#include <stdlib.h>
#include "queuelinked.c"
#include "wordmachine.c"

int main(){
    Queue S;
    Queue M;
    Queue IDX;
    CreateQueue(&S);
    CreateQueue(&M);
    CreateQueue(&IDX);
    boolean koma = false;
    STARTWORD();
    int temp;
    int i;
    for (i = 0 ; i < currentWord.Length ; i++){
        if(currentWord.TabWord[i] == 'B' && !koma){
            enqueue(&M,0);
        }
        else if (currentWord.TabWord[i] == 'K' && !koma){
            enqueue(&M,1);
        }
        else if (currentWord.TabWord[i] == ','){
            koma = true;
        }
        else if(currentWord.TabWord[i] == 'B'){
            enqueue(&S,0);
        }
        else if (currentWord.TabWord[i] == 'K'){
            enqueue(&S,1);
        }
    }

    for (i = 0 ; i < length(M) ; i++){
        enqueue(&IDX,i+1);
    }

    int count = length(S);
    boolean headChecked = false;
    boolean stop;
    while(!isEmpty(S) && !isEmpty(M) && !stop){
        if (HEAD(S) == HEAD(M)){
            dequeue(&S,&temp);
            dequeue(&M,&temp);
            printf("%d -> ",HEAD(IDX));
            if(temp == 0){
                printf("bulat\n");
            }
            else if(temp == 1){
                printf("kotak\n");
            }
            dequeue(&IDX,&temp);
        }
        else if (HEAD(S) != HEAD(M)){
            if (headChecked && HEAD(IDX) == 1){
                stop = true;
            }
            else{
                dequeue(&M,&temp);
                enqueue(&M,temp);
                dequeue(&IDX,&temp);
                enqueue(&IDX,temp);
            }
            headChecked = true;
        }
    }
    printf("%d\n",length(M));
}