//NIM: 18221168
//Nama: Rania Sasi Kirana
//Tanggal: 29 Oktober 2022
//Topik Praktikum: Set dan Map
//Deskripsi: Pra prak no. 1
//Implementasi set.h

#include <stdio.h>
#include "set.h"

/* Definisi Set S kosong : S.Count = Nil */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S)
{
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */
    (*S).Count = Nil;
}
/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S)
{
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */
    return (S.Count == Nil);
}

boolean IsFull(Set S)
{
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */
    return (S.Count == MaxEl);
}

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt)
{
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
    if (!(IsMember(*S, Elmt))){
        (*S).Count++;
        (*S).Elements[(*S).Count-1] = Elmt;
    }
}

void Delete(Set *S, infotype Elmt)
{
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
    if (IsMember(*S, Elmt)){
        int found = 0, length = (*S).Count;
        while (length != 0 && found == 0){
            if ((*S).Elements[length-1] == Elmt){
                found = 1;
            }
            length--;
        }
        int i;
        for (i=length-1; i<(*S).Count; i++){
            (*S).Elements[i] = (*S).Elements[i+1];
        }
        (*S).Count--;
    }
}

boolean IsMember(Set S, infotype Elmt)
{
/* Mengembalikan true jika Elmt adalah member dari S */
    boolean found = false;
    int length = S.Count;
    while (length != 0 && !(found)){
        if (S.Elements[length-1] == Elmt){
            found = true;
        }
        length--;
    }
    return found;
}