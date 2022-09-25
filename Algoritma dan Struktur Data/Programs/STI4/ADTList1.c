#include <stdio.h>
#include "ADTList1.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */
List MakeList()
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */
{
    List L;
    int i;
    for (i = 0; i < MaxEl; i++)
        L.A[i] = Mark;
    return L;
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsEmpty(List L)
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */
{
    return (L.A[0] == Mark);
}
/* *** Menghasilkan sebuah elemen *** */
ElType Get(List L, IdxType i)
/* Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen list yang ke-i */
{
    return L.A[i];
}
/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
void Set(List *L, IdxType i, ElType v)
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
{
    List L1 = *L;
    L1.A[i] = v;
    *L = L1;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Length(List L)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
{
    int i = 0;
    while (L.A[i] != Mark)
        i++;
    return i;
}

/* *** Selektor INDEKS *** */
IdxType FirstIdx(List L)
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */
{
    return 0;
}

IdxType LastIdx(List L)
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */
{
    return Length(L) - 1;
}
/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (List L, IdxType i)
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/
{
    return (i >= 0 && i < MaxEl);
}
boolean IsIdxEff (List L, IdxType i)
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */
{
    return (i >= FirstIdx(L) && i <= LastIdx(L));
}
/* ********** Operasi-operasi ********** */
boolean Search(List L, ElType X)
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */
{
    int i = 0;
    while (L.A[i] != Mark && L.A[i] != X)
        i++;
    return (L.A[i] == X);
}
void InsertFirst(List *L, ElType X)
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */
{
    List L1 = *L;
    int i;
    for (i = Length(L1); i > 0; i--)
        L1.A[i] = L1.A[i - 1];
    L1.A[0] = X;
    *L = L1;
}
void InsertAt(List *L, ElType X, IdxType i)
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */
{
    List L1 = *L;
    int j;
    for (j = Length(L1); j > i; j--)
        L1.A[j] = L1.A[j - 1];
    L1.A[i] = X;
    *L = L1;
}
void InsertLast(List *L, ElType X)
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */
{
    List L1 = *L;
    L1.A[Length(L1)] = X;
    *L = L1;
}

void DeleteFirst(List *L)
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */
{
    List L1 = *L;
    int i;
    for (i = 0; i < Length(L1); i++)
        L1.A[i] = L1.A[i + 1];
    *L = L1;
}

void DeleteAt(List *L, IdxType i)
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */
{
    List L1 = *L;
    int j;
    for (j = i; j < Length(L1); j++)
        L1.A[j] = L1.A[j + 1];
    *L = L1;
}
void DeleteLast(List *L)
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */
{
    List L1 = *L;
    L1.A[Length(L1) - 1] = Mark;
    *L = L1;
}
List Concat(List L1, List L2)
/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah List yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */
/* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */
{
    List L3;
    int i, j;
    for (i = 0; i < Length(L1); i++)
        L3.A[i] = L1.A[i];
    for (j = 0; j < Length(L2); j++)
        L3.A[i + j] = L2.A[j];
    return L3;
}