// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 24 November 2022
// Topik praktikum  : ADT Binary Tree
// Deskripsi        : File "rob1.c"

#include <stdio.h>
#include <stdlib.h>
#include "bintree.c"

int main(){
    BinTree T = NewTree(3,NewTree(2,NULL,NewTree(3,NULL,NULL)),NewTree(3,NewTree(1,NULL,NULL),NULL));
    printTree(T,2);
    printf("%d\n\n",rob2(T));
    BinTree T2 = NewTree(3,NewTree(4,NewTree(1,NULL,NULL),NewTree(3,NULL,NULL)),NewTree(5,NewTree(1,NULL,NULL),NULL));
    printTree(T2,2);
    printf("\n%d\n",rob2(T2));
}