// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 24 November 2022
// Topik praktikum  : ADT Binary Tree
// Deskripsi        : File "rob1.c"

#include <stdio.h>
#include <stdlib.h>
#include "bintree.c"

// int rampok_path(BinTree t)
// {
//     if (t == NULL) {
//         return 0;
//     }
//     int left  = rampok_path(LEFT(t));
//     int right = rampok_path(RIGHT(t));
//     return (left > right ? left : right) + ROOT(t); 
// }

// BinTree findVal(BinTree T, int val)
// {
//     if (ROOT(T) == val){
//         return T;
//     }
//     else if(ROOT(LEFT(T)) == val){
//         return LEFT(T);
//     }
//     else if(ROOT(RIGHT(T)) == val){
//         return RIGHT(T);
//     }
//     else{
//         findVal(LEFT(T),val);
//         findVal(RIGHT(T),val);
//     }

// }

// int rob1(BinTree root){
//     int ruang;
//     scanf("%d",&ruang);
//     return rampok_path(findVal(root,ruang));
// }

int main(){
    BinTree T = NewTree(3,NewTree(4,NewTree(6,NULL,NULL),NewTree(8,NULL,NULL)),NewTree(6,NewTree(5,NULL,NULL),NewTree(4,NULL,NULL)));
    printf("%d\n",rob1(T));
}