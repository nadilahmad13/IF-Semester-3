//NIM: 18221168
//Nama: Rania Sasi Kirana
//Tanggal: 1 November 2022
//Topik Praktikum: Set dan Map
//Deskripsi: Pra prak no 1
//Implementasi listlinier.h

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
{
    return (First(L) == Nil);
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
{
    First(*L) = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
{
    address P = (address) malloc (sizeof(ElmtList));
    if (P != Nil){  // alokasi berhasil
        Info(P) = X;
        Next(P) = Nil;
    } 

    return P;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P)
{
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan free/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
{
    address p = First(L);
    while (p != Nil){
        if (Info(p) == X){
            return p;
        }
        p = Next(p);
    }
    return Nil;
}
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
{
    address p = Alokasi(X);
    if (p != Nil){          // Alokasi berhasil
        Next(p) = First(*L);
        First(*L) = p;
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X)
{
    if (IsEmpty(*L)){
        InsVFirst(L,X);
    } else {
        address p = Alokasi(X);
        if (p != Nil){          // Alokasi berhasil
            address last = First(*L);
            while (Next(last) != Nil){
                last = Next(last);
            }
            Next(last) = p;
        }
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
{
    address p = First(*L);
    *X = Info(p);
    First(*L) = Next(p);
    free(p);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-free */
void DelVLast (List *L, infotype *X)
{
    address last = First(*L);
    address loc = Nil;
    while (Next(last) != Nil){
        loc = last;
        last = Next(last);
    }
    if (loc == Nil){
        First(*L) = Nil;
    } else {
        Next(loc) = Nil; 
    }
    *X = Info(last);
    free(last);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-free */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
{
    Next(P) = First(*L);
    First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (List *L, address P, address Prec)
{
    address x = First(*L);
    boolean found = false;
    while (Next(x) != Nil && !found){
        if (x == Prec){
            found = true;
        }
        x = Next(x);
    }
    Next(P) = Next(x);
    Next(x) = P;   
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, address P)
{
    if (IsEmpty(*L)){
        InsertFirst(L, P);
    } else {
        address last = First(*L);
        while (Next(last) != Nil){
            last = Next(last);
        }
        Next(last) = P;
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
{
    address p = First(*L);
    *P = p;
    First(*L) = Next(p);
    free(p);
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List *L, infotype X)
{
    address p = First(*L);
    address loc = Nil;
    boolean found = false;
    while (Next(p) != Nil && !found){
        if (Info(p) == X){
            found = true;
        }
        loc = p;
        p = Next(p);
    }

    if (found){
        if (loc == Nil && Next(p) == Nil){  // List jadi kosong
            First(*L) = Nil;
            free(p);
        } else {
            Next(loc) = Next(p);
            free(p);
        }
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-free */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, address *P)
{
    address last = First(*L);
    address loc = Nil;
    while (Next(last) != Nil){
        loc = last;
        last = Next(last);
    }

    if (loc == Nil){
        First(*L) = Nil;
    } else {
        Next(loc) = Nil;
    }

    *P = last;
    free(last);
}

/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec)
{
    address loc = First(*L);
    address x = Nil;
    boolean found = false;
    while (Next(loc) != Nil && !found){
        if (x == Prec){
            found = true;
        }
        x = loc;
        loc = Next(loc);
    }

    if (found){
        Next(x) = Next(loc);
        free(loc);
    }
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
{
    printf ("[");
    address p = First(L);
    while (p != Nil){
        printf("%d", Info(p));
        p = Next(p);
        if (p != Nil){
            printf(",");
        }
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmt (List L)
{
    int count = 0;
    if (!(IsEmpty(L))){
        address p = First(L);
        while (p != Nil){
            count++;
            p = Next(p);
        }
    }
    return count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
{
    address p = First(L);
    infotype max = Info(p);
    while (p != Nil){
        if (max<Info(p)){
            max = Info(p);
        }
        p = Next(p);
    }
    return max;
}
/* Mengirimkan nilai info(P) yang maksimum */
address AdrMax (List L)
{
    infotype max = Max(L);
    address p = First(L);
    while (p != Nil && Info(p) != max){
        p = Next(p);
    }
    return p;
}
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
infotype Min (List L)
{
    address p = First(L);
    infotype min = Info(p);
    while (p != Nil){
        if (min>Info(p)){
            min = Info(p);
        }
        p = Next(p);
    }
    return min;   
}
/* Mengirimkan nilai info(P) yang minimum */
address AdrMin (List L)
{
    infotype min = Min(L);
    address p = First(L);
    while (p != Nil && Info(p) != min){
        p = Next(p);
    }
    return p;
}
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
float Average (List L)
{
    int sum = 0;
    address p = First(L);
    while (p != Nil){
        sum += Info(p);
        p = Next(p);
    }
    return (sum/NbElmt(L));
}
/* Mengirimkan nilai rata-rata info(P) */

/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L)
{
    if (!(IsEmpty(*L))){
        address p = First(*L);
        address last;
        while (Next(p) != Nil){
            p = Next(p);
        }
        last = p;
        address prev;
        while (p != First(*L)){
            prev = First(*L);
            while (Next(prev) != p){
                prev = Next(prev);
            }
            Next(p) = prev;
            p = prev;
        }
        Next(p) = Nil;
        First(*L) = last;
    }
}
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/free. */

void Konkat1 (List *L1, List *L2, List *L3)
{
    First(*L3) = First(*L1);
    First(*L1) = Nil;
    address last = First(*L3);
    while (Next(last) != Nil){
        last = Next(last);
    }

    Next(last) = First(*L2);
    First(*L2) = Nil;
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/free pada prosedur ini */