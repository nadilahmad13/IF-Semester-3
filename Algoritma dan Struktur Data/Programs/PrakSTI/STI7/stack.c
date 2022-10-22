//NIM: 18221168
//Nama: Rania Sasi Kirana
//Tanggal: 22 Oktober 2022
//Topik Praktikum: ADT Stack
//Desrkripsi: Pra Prak No. 1
//Implementasi stack.h

#include <stdio.h>
#include "stack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S)
{
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
    (*S).TOP = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S)
{
/* Mengirim true jika Stack kosong: lihat definisi di atas */
    return (S.TOP == Nil);
}

boolean IsFull(Stack S)
{
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
    return (S.TOP == MaxEl-1);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infotype X)
{
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
    (*S).TOP++;
    (*S).T[(*S).TOP] = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infotype* X)
{
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
    *X = (*S).T[(*S).TOP];
    (*S).TOP--;
}