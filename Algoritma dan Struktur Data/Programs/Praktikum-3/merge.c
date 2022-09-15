// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 14 September 2022
// Topik praktikum  : ADT List Statik dan Dinamik
// Deskripsi        : File ".c"

#include <stdio.h>
#include <stdlib.h>
#include "listdin.c"

int main(){
    ListDin l1,l2,l3;
    CreateListDin(&l1,200);
    CreateListDin(&l2,200);
    CreateListDin(&l3,400);

    readList(&l1);
    readList(&l2);

    sort(&l1,true);
    sort(&l2,true);

    if (isEmpty(l1)){
        int len = listLength(l2);
        printf("%d\n",len);
        printList(l2);
    }

    else if (isEmpty(l2)){
        int len = listLength(l1);
        printf("%d\n",len);
        printList(l1);
    }
    else if (isListEqual(l1,l2)){
        int len = listLength(l2);
        printList(l2);
    }

    else{
    int i,j;
    boolean flag;
    for (i = 0 ; i < listLength(l1) ; i++){
        flag = true;
        for (j = 0 ; j < listLength(l2) ; j++){
            if(ELMT(l1,i) == ELMT(l2,j)){
                flag = false;
                }
            if (j == listLength(l2)-1 && flag){
                insertLast(&l3,ELMT(l1,i));
                }
            } 
        }
        printList(l3);
    }

    printf("\n");

    return 0;
}