#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"

void displayLinear(List l);
List inputList (List l, int length);
List elementsBeforeX(List l, ElType x);
List inverseList (List l);

List inverseList (List l)
/* Mengirimkan list baru, hasil invers dari l dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */
{
    if (isEmpty(l)){
        return l;
    }
    else if(isOneElmt(l)){
        return l;
    }
    else{
        return konsb(inverseList(tail(l)),head(l));
    }
}

void displayLinear(List l){
    if (isEmpty(l)){
        printf("\n");
    }
    else{
        printf("%d ",head(l));
        displayLinear(tail(l));
    }
}

List inputList (List l, int length){
    if (length != 0){
        int temp;
        scanf("%d",&temp);
        l = konso(inputList(l,length-1),temp);
    }
}

List elementsBeforeX(List l, ElType x){
    if(isEmpty(l)){
        return NULL;
    }
    if(x == 0){
        return NULL;
    }
    else{
        return konso(elementsBeforeX(tail(l), x-1), head(l));
    }
}

int main(){
    List l1 = NULL;
    List l2 = NULL;
    List l3 = NULL;

    int n,i,temp,index;
    scanf("%d",&n);
    scanf("%d",&index);
    l1 = inputList(l1,n);
    l2 = elementsBeforeX(l1,index);
    l2 = inverseList(l2);
    l1 = inverseList(l1);
    l1 = elementsBeforeX(l1,n-index);

    l3 = concat(l2,l1);

    displayLinear(l3);
}