// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 27 Oktober 2022
// Topik praktikum  : ADT Linked List
// Deskripsi        : File "cache.c"

#include <stdio.h>
#include "listlinier.h"

void displayCache(List l)
{
    printf("[");
    Address p = FIRST(l);
    while (p != NULL && INFO(p) != IDX_UNDEF) {
        printf("%d", INFO(p));
        p = NEXT(p);
        if (p != NULL && INFO(p) != IDX_UNDEF) {
            printf(",");
        }
    }
    printf("]");
}

int main(){
    int n;
    scanf("%d", &n);
    int i, temp, idx, val;
    List l;
    CreateList(&l);
    for(i = 0; i < n; i++){
        insertLast(&l, IDX_UNDEF);
    }
    int q;
    double hit_counter = 0;
    scanf("%d", &q);
    if (q > 0){
        for(i=1; i <= q; i++){
            boolean hit = false;
            scanf("%d", &temp);
            idx = indexOf(l,temp);
            if(idx != IDX_UNDEF){
                hit = true;
            }
            if(hit){
                hit_counter ++;
                deleteAt(&l, idx, &val);
                insertFirst(&l, val);
                printf("hit ");
                displayCache(l);
            }
            else{
                deleteLast(&l, &val);
                insertFirst(&l, temp);
                printf("miss ");
                displayCache(l);
            }
            printf("\n");
        }
        double ratio = hit_counter / q;
        printf("hit ratio: %.2f\n",ratio);
    }
    else{
        printf("hit ratio: %.2f\n",0.00);
    }
}