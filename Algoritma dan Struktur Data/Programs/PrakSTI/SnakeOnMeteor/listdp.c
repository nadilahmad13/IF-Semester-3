// NIM: 18221168
// Nama: Rania Sasi Kirana
// Tanggal: 13 November 2022
// Topik Praktikum: ADT List dengan Double Pointer
// Deskripsi: Pra prak No.1
// Implementasi listdp.h

#include <stdio.h>
#include <stdlib.h>
#include "listdp.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return (First(L) == Nil && Last(L) == Nil);
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    First(*L) = Nil;
    Last(*L) = Nil;
}
/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
    address P = (address) malloc (sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
        Prev(P) = Nil;
        Point point;
        createPoint(&point, 0, 0);
        Loc(P) = point;
    }
    return P;
}
void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    address P = First(L);
    while (P != Nil && Info(P) != X) {
        P = Next(P);
    }
    return P;
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if (IsEmpty(*L)) {
        First(*L) = P;
        Last(*L) = P;
    } else {
        Next(Last(*L)) = P;
        Prev(P) = Last(*L);
        Last(*L) = P;
    }
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
    *P = Last(*L);
    if (First(*L) == Last(*L)) {
        First(*L) = Nil;
        Last(*L) = Nil;
    } else {
        Last(*L) = Prev(Last(*L));
        Next(Last(*L)) = Nil;
    }
}
void DelAt (List *L, address *P, int pos)
/*I.S. List Tidak Kosong
F.S. Delete di suatu index lalu dealloc sampai tail*/
{
    address Pdel = First(*L);
    int i = 1;
    while (i < pos) {
        Pdel = Next(Pdel);
        i++;
    }
    *P = Pdel;
    Last(*L) = Prev(Pdel);
    Next(Last(*L)) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    address P = First(L);
    printf("[");
    while (P != Nil) {
        printf("%d", Info(P));
        if (Next(P) != Nil) {
            printf(",");
        }
        P = Next(P);
    }
    printf("]");
}

int Length (List L){
    int count = 0;
    address P = First(L);
    while (P != Nil) {
        count++;
        P = Next(P);
    }
    return count;
}

void printLoc(List L){
    address P = First(L);
    while (P != Nil) {
        printf("%d %d\n", P->loc.x, P->loc.y);
        P = Next(P);
    }
}
// int main()
// {
//     List L;
//     CreateEmpty(&L);
//     address P = Alokasi(5);
//     InsertLast(&L, P);
//     P = Alokasi(6);
//     InsertLast(&L, P);
//     P = Alokasi(7);
//     InsertLast(&L, P);
//     PrintForward(L);

//     DelAt(&L, &P, 2);
//     PrintForward(L);

//     return 0;
// }