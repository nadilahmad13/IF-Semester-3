#include <stdio.h>
#include <stdlib.h>
#include "listrec.c"

void displayLinear(List l){
    if (isEmpty(l)){
        printf("\n");
    }
    else{
        printf("%d ",head(l));
        displayLinear(tail(l));
    }
}

int main(){
    List l1 = NULL;
    List l2 = NULL;

    int n,i,temp,index;
    scanf("%d",&n);
    scanf("%d",&index);
    for (i = 0 ; i < n ; i++){
        scanf("%d",&temp);
        l1 = konsb(l1,temp);
    }
    
    for (i = 0 ; i < index ; i ++){
        l2 = konsb(l2,head(l1));
        l1 = tail(l1);
    }
    
    l2 = inverseList(l2);
    l1 = inverseList(l1);

    l1 = concat(l2,l1);

    displayLinear(l1);
}