#include <stdio.h>
#include <stdlib.h>
#include "queuelinked.c"
#include "charmachine.c"

int main(){
    Queue S;
    Queue M;
    Queue IDX;
    CreateQueue(&S);
    CreateQueue(&M);
    CreateQueue(&IDX);
    boolean koma = false;
    int temp;
    int i;
    START();
    while(!EOP){
        if(currentChar == 'B' && !koma){
            enqueue(&M,0);
        }
        else if (currentChar == 'K' && !koma){
            enqueue(&M,1);
        }
        else if (currentChar == ','){
            koma = true;
        }
        else if(currentChar == 'B'){
            enqueue(&S,0);
        }
        else if (currentChar == 'K'){
            enqueue(&S,1);
        }
        ADV();
    }
    for (i = 0 ; i < length(M) ; i++){
        enqueue(&IDX,i+1);
    }

    boolean headIDXChecked = false;
    boolean stop = false;

    while(!isEmpty(S) && !isEmpty(M) && !stop){
        if (HEAD(S) == HEAD(M)){
            dequeue(&S,&temp);
            dequeue(&M,&temp);
            printf("%d -> ",HEAD(IDX));
            if(temp == 0){
                printf("bulat\n");
            }
            else if (temp == 1){
                printf("kotak\n");
            }
            dequeue(&IDX,&temp);
        }
        else if (HEAD(S) != HEAD(M)){
            if (headIDXChecked && HEAD(IDX) == 1){
                stop = true;
            }
            else if (HEAD(IDX) == 1){
                headIDXChecked = true;
            }
            dequeue(&M,&temp);
            enqueue(&M,temp);
            enqueue(&IDX,HEAD(IDX));
            dequeue(&IDX,&temp);
        }
    }
    printf("%d\n",length(M));
}