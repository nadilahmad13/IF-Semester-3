// Nama : Rania Sasi Kirana
// NIM : 18221168
// Tanggal : 17 Oktober 2022
// Topik Praktikum : Queue
// Pasca Praktikum 6 No. 6
// Deskripsi:
// Spesifikasi Program:
// Input berupa angka, yaitu 0, 1, dan 2. 0 berarti program berhenti menerima masukan. 
// 1 berarti menerima permintaan (dengan tambahan parameter adalah waktu yang dibutuhkan 
// dan waktu yang tidak valid akan diabaikan). 2 berarti menyajikan masakan.
// Output berupa jumlah masakan yang disaji, waktu minimal yang dibutuhkan, dan waktu 
// maksimal yang dibutuhkan (diikuti dengan newline). Default value adalah 0.

// contoh Input
// 1 2
// 1 5
// 2
// 0

// output
// 1
// 2
// 2

// penjelasan : Karena hanya menyajikan 1 masakan, maka total adalah 1, 
// waktu minimal dan waktu maksimal yang dibuutuhkan adalah 2

// contoh input
// 1 2
// 2
// 1 5
// 2
// 0

// contoh output
// 2
// 2
// 5

// penjelasan : Karena menyajikan 2 masakan, maka total adalah 2, dan waktu 
// minimal yang dibutuhkan adalah 2 (pada pesanan pertama) dan waktu maksimal 
// yang dibutuhkan adalh 5 (pada pesanan kedua).

#include <stdio.h>
#include "queue.c"

int main(){
    // INISIASI VARIABEL
    Queue q;
    CreateQueue(&q);
    int menu, time, val;
    int total_saji = 0;
    int max = 0;
    int min = 0;
    int flag = 1;

    // LOOPING INPUT
    while (flag)
    {
        scanf("%d",&menu);
        if (menu == 1)
        {
            scanf("%d",&time);
            // TIDAK ADA ERROR HANDLING JIKA QUEUE PENUH
            enqueue(&q,time);
        }

        else if (menu == 2)
        {
            // TIDAK ADA PESAN JIKA QUEUE KOSONG

            // MENENTUKAN NILAI MAX DAN MIN TIME
            if (HEAD(q) > max)
            {
                max = HEAD(q);
            }
            if (HEAD(q) < min || min == 0)
            {
                min = HEAD(q);
            }

            total_saji++;
            dequeue(&q,&val);
        }

        else if(menu == 0)
        {
            flag = 0;
        }
    }

    printf("%d\n", total_saji);
    printf("%d\n", min);
    printf("%d\n", max);
    return 0;
}