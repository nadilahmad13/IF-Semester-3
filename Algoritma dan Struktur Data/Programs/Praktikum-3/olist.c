// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 14 September 2022
// Topik praktikum  : ADT List Statik dan Dinamik
// Deskripsi        : File "olist.c"

#include <stdio.h>
#include <stdlib.h>
#include "liststatik.h"

int main()
{
    // Input List
    ListStatik l;
    readList(&l);

    // Input x
    int x;
    scanf("%d",&x);

    // 2. X Occurence
    int i,xocc;

    // 3. Get Last Index
    int ldx;
    for (i = 0 ; i < listLength(l) ; i++){
        if (x == ELMT(l,i)){
            ldx = i;
            xocc++;
        }
    }

    // 1. Print List
    printList(l);
    printf("\n");

    printf("%d\n",xocc); //X Occurence

    // Last Index
    if (indexOf(l,x) != IDX_UNDEF){
        printf("%d\n",ldx);
    }
    else{
        printf("%d tidak ada\n",x);
    }
    

    // 4. Extreme Values
    int min,max;
    extremeValues(l,&max,&min);
    
    if (x == max){
        printf("maksimum\n");
    }

    if (x == min){
        printf("minimum\n");
    }

    // 5. Median
    sortList(&l,true);

    int len = listLength(l)-2;


    if (listLength(l) % 2 == 0){ //GENAP
        if (x == ELMT(l,(len / 2))){
            printf("median\n");
        }
    }

    if (listLength(l) % 2 != 0){ // GANJIL
        if (x == ELMT(l,(len/2 + 1))){
            printf("median\n");
        }
    }

    return 0;   
}