#include <stdio.h>
#include <stdlib.h>
#include "listlinier.c"
#include "OddEvenList.h"

void sortList(List *L){
    address P, Q, R;
    P = First(*L);
    while (P != Nil){
        Q = Next(P);
        while (Q != Nil){
            if (Info(P) > Info(Q)){
                R = Alokasi(Info(P));
                Info(P) = Info(Q);
                Info(Q) = Info(R);
                Dealokasi(&R);
            }
            Q = Next(Q);
        }
        P = Next(P);
    }
}

void OddEvenList(List L, List *Odd, List *Even)
    /* Memisahkan elemen ganjil dan genap dari list L kedalam dua list baru secara mengurut membesar*/
    /* I.S: List L TIDAK mungkin kosong dan memiliki nilai lebih dari sama dengan 0(value>=0), List Odd dan Even kosong*/
    /* F.S: List Odd memiliki elemen bernilai ganjil mengurut membesar, List Even memiliki elemen bernilai genap mengurut membesar
            List L TIDAK PERLU DIDEALOKASI*/
    /*Contoh:
        Input:
            L: [0,3,1,4,5]
            Odd: []
            Even: []
        Output:
            L: [0,3,1,4,5]
            Odd: [1,3,5]
            Even: [0,4] */
    /*Note: 
        1. Bilangan 0 merupakan bilangan genap
        2. Buatlah List Odd dan Even terlebih dahulu*/
{
    address P;
    CreateEmpty(Odd);
    CreateEmpty(Even);
    P = First(L);
    while (P != Nil)
    {
        if (Info(P) % 2 == 0)
        {
            InsVLast(Even, Info(P));
        }
        else
        {
            InsVLast(Odd, Info(P));
        }
        P = Next(P);
    }
    sortList(Odd);
    sortList(Even);
}

int main(){
    List L;
    List Odd;
    List Even;
    CreateEmpty(&L);
    CreateEmpty(&Odd);
    CreateEmpty(&Even);
    InsVLast(&L, 0);
    InsVLast(&L, 3);
    InsVLast(&L, 1);
    InsVLast(&L, 4);
    InsVLast(&L, 5);
    PrintInfo(L);
    OddEvenList(L, &Odd, &Even);
    PrintInfo(Odd);
    PrintInfo(Even);
}