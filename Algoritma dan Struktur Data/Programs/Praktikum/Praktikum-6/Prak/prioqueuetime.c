// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 6 Oktober 2022
// Topik praktikum  : ADT Queue
// Deskripsi        : File "prioqueuetime.c"

#include <stdio.h>
#include "prioqueuetime.h"


/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueTime Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */{
    return (Head(Q) == Nil && Tail(Q) == Nil);
}
boolean IsFull (PrioQueueTime Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return (Head(Q) == 0 && Tail(Q) == MaxEl(Q));
}

int NBElmt (PrioQueueTime Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if (IsEmpty(Q)){
        return 0;
    }
    else if (Tail(Q) >= Head(Q)){
        return Tail(Q) - Head(Q) + 1;
    }
    else{
        return MaxEl(Q) - Head(Q) + Tail(Q) + 1;
    }
}

/* *** Kreator *** */
void MakeEmpty (PrioQueueTime * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    MaxEl(*Q) = Max+1;
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueueTime * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    MaxEl(*Q) = 0;
}

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueTime * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
{
    int i;
    int count = 0;
    if(isEmpty(*Q)){
        Head(*Q)= 0;
        Tail(*Q) = 0;
    }
    else{
        // Penggeseran
        if(Tail(*Q) == MaxEl(Q)-1){
            int i;
            for(i = Head(*Q); i <= Tail(*Q); i++){
                (*Q).buffer[i-Head(*Q)] = (*Q).buffer[i];
            }
            Tail(*Q) -= Head(*Q);
            Head(*Q) = 0;
        }
        Tail(*Q)++;

    }
    TAIL(*Q) = val;
    i = Tail(*Q);

    while((i > 0) && (((*Q).buffer[i-1].score <= (*Q).buffer[i].score) || ((*Q).buffer[i-1].score == (*Q).buffer[i].score)) && ((*Q).buffer[i-1].tArrival > (*Q).buffer[i].tArrival)){
        temp = (*Q).buffer[i-1];
        pq->buffer[i - 1] = pq->buffer[i];
        (*Q).buffer[i] = temp;
        i--;
    }


}

void Dequeue (PrioQueueTime * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    *X = InfoHead(*Q);
    if (NBElmt(*Q) == 1){
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else{
        if (Head(*Q) == MaxEl(*Q)-1){
            Head(*Q) = 0;
        }
        else{
            Head(*Q)++;
        }
    }
}
/* Operasi Tambahan */
void PrintPrioQueueTime (PrioQueueTime Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<time-1> <elemen-1>
...
<time-n> <elemen-n>
#
*/
{   
    int i;
    if (!IsEmpty(Q)){
        if (Head(Q) < Tail(Q)){
            for (i = Head(Q) ; i <= Tail(Q) ; i++){
                printf("%d ",Q.T[i].time);
                printf("%s\n",Q.T[i].info);
            }
        }
    }
    printf("#\n");
}