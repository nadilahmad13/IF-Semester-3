//NIM: 18221168
//Nama: Rania Sasi Kirana
//Tanggal: 1 November 2022
//Topik Praktikum: ADT Linked List
//Deskripsi: Pra prak no 1
//Implementasi listlinier.h

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
    return (First(L) == Nil);
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L) = Nil;
}
/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address P;
    P = (address) malloc(sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    address P;
    P = First(L);
    while (P != Nil) {
        if (Info(P) == X) {
            return P;
        }
        P = Next(P);
    }
    return Nil;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address P;
    P = Alokasi(X);
    if (P != Nil) {
        Next(P) = First(*L);
        First(*L) = P;
    }
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address P;
    P = Alokasi(X);
    if (P != Nil) {
        if (IsEmpty(*L)) {
            First(*L) = P;
        } else {
            address Q;
            Q = First(*L);
            while (Next(Q) != Nil) {
                Q = Next(Q);
            }
            Next(Q) = P;
        }
    }
}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address P;
    P = First(*L);
    First(*L) = Next(P);
    *X = Info(P);
    Dealokasi(&P);
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address P;
    address Q;
    P = First(*L);
    if (Next(P) == Nil) {
        First(*L) = Nil;
    } else {
        while (Next(Next(P)) != Nil) {
            P = Next(P);
        }
        Q = Next(P);
        Next(P) = Nil;
    }
    *X = Info(Q);
    Dealokasi(&Q);
}
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P;
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if (IsEmpty(*L)) {
        First(*L) = P;
    } else {
        address Q;
        Q = First(*L);
        while (Next(Q) != Nil) {
            Q = Next(Q);
        }
        Next(Q) = P;
    }
}
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    First(*L) = Next(*P);
    Next(*P) = Nil;
}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address P;
    P = Search(*L, X);
    if (P != Nil) {
        if (P == First(*L)) {
            DelFirst(L, &P);
        } else {
            address Q;
            Q = First(*L);
            while (Next(Q) != P) {
                Q = Next(Q);
            }
            Next(Q) = Next(P);
            Next(P) = Nil;
        }
        Dealokasi(&P);
    }
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    address Q;
    *P = First(*L);
    if (Next(*P) == Nil) {
        First(*L) = Nil;
    } else {
        Q = Next(*P);
        while (Next(Q) != Nil) {
            *P = Q;
            Q = Next(Q);
        }
        Next(*P) = Nil;
    }
    Dealokasi(&Q);
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    address P;
    P = First(L);
    printf("[");
    while (P != Nil) {
        printf("%d", Info(P));
        P = Next(P);
        if (P != Nil) {
            printf(",");
        }
    }
    printf("]");
}
int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int count = 0;
    address P;
    P = First(L);
    while (P != Nil) {
        count++;
        P = Next(P);
    }
    return count;
}
/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai info(P) yang maksimum */
{
    address P;
    infotype max;
    P = First(L);
    max = Info(P);
    while (P != Nil) {
        if (Info(P) > max) {
            max = Info(P);
        }
        P = Next(P);
    }
    return max;
}
address AdrMax (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
{
    address P, max;
    P = First(L);
    max = P;
    while (P != Nil) {
        if (Info(P) > Info(max)) {
            max = P;
        }
        P = Next(P);
    }
    return max;
}
infotype Min (List L)
/* Mengirimkan nilai info(P) yang minimum */
{
    address P;
    infotype min;
    P = First(L);
    min = Info(P);
    while (P != Nil) {
        if (Info(P) < min) {
            min = Info(P);
        }
        P = Next(P);
    }
    return min;
}
address AdrMin (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
{
    address P, min;
    P = First(L);
    min = P;
    while (P != Nil) {
        if (Info(P) < Info(min)) {
            min = P;
        }
        P = Next(P);
    }
    return min;
}
float Average (List L)
/* Mengirimkan nilai rata-rata info(P) */
{
    address P;
    float sum = 0;
    P = First(L);
    while (P != Nil) {
        sum += Info(P);
        P = Next(P);
    }
    return sum / NbElmt(L);
}
/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
    address P, Q, R;
    P = First(*L);
    Q = Nil;
    while (P != Nil) {
        R = Next(P);
        Next(P) = Q;
        Q = P;
        P = R;
    }
    First(*L) = Q;
}
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    address P;
    CreateEmpty(L3);
    First(*L3) = First(*L1);
    P = First(*L3);
    while (Next(P) != Nil) {
        P = Next(P);
    }
    Next(P) = First(*L2);
    CreateEmpty(L1);
    CreateEmpty(L2);
}