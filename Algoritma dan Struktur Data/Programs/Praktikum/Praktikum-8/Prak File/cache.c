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
    long long int n;
    scanf("%lld", &n);
    int i, temp, idx, val;
    long long int q;
    scanf("%lld", &q);
    if (q > 0){
        List l;
        CreateList(&l);
        int val = IDX_UNDEF;
        if (n < q){
            val = n;
        }
        else{
            val = q;
        }
        for(i = 0; i < val; i++){
            insertLast(&l, IDX_UNDEF);
        }
        long long int hit_counter = 0;
        for(i=1; i <= q; i++){
            boolean hit = false;
            scanf("%d", &temp);
            idx = indexOf(l,temp);
            if(idx != IDX_UNDEF){
                hit = true;
            }
            if(hit){
                hit_counter += 1.00;
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
        printf("hit ratio: %.2f\n",(double) hit_counter / q);
    }
    else{
        printf("hit ratio: %.2f\n",0.00);
    }
}