//NIM: 18221168
//Nama: Rania Sasi Kirana
//Tanggal: 1 November 2022
//Topik Praktikum: Set dan Map
//Deskripsi: Pasca prak no. 4
//Implementasi duplicate.h

#include <stdio.h>
#include "duplicate.h"

Set arrToSet(int* arr, int arrSize)
/*
    Masukkan semua elemen array arr ke suatu Set, kemudian kembalikan Set tersebut
        Contoh:
            arrToSet
                <- arr = [1, 1, 3]
                <- arrSize = 3
            -> [1, 3]
*/
{
    Set s;
    CreateEmpty(&s);
    int i;
    for (i=0; i<arrSize; i++){
        if (!IsMember(s, arr[i])){
            Insert(&s, arr[i]);
        }
    }
    return s;
}


void removeDuplicateDesc(int* arr, int arrSize, int* arrRes, int* arrResSize)
/*
    Dengan memanfaatkan fungsi arrToSet, hapuslah elemen duplikat pada array arr
    kemudian kembalikan isinya secara menurun

    Penjelasan Parameter:
    Parameter 1: arr, merupakan array masukan yang perlu dihapus elemen duplikatnya
    Parameter 2: arrSize, merupakan panjang arr
    Parameter 3: arrRes, merupakan array keluaran, hasil pengapusan elemen duplikat
        dan elemen-elemennya terurut menurun
    Parameter 4: arrResSize, merupakan panjang arrRes

    Contoh: 
        removeDuplicate
            <- arr = [1, 1, 2, 3]
            <- arrSize = 4
            -> arrRes = [3, 2, 1]
            -> arrResSize = 3
        removeDuplicate
            <- arr = [3, 1, 1]
            <- arrSize = 3
            -> arrRes = [3, 1]
            -> arrResSize = 2
*/
{
    Set s;
    s = arrToSet(arr, arrSize);
    *arrResSize = s.Count;
    int i;
    for (i=0; i<s.Count; i++){
        arrRes[i] = s.Elements[i];
    }

    // sprt arres descending
    int j;
    for (i=0; i<*arrResSize; i++){
        for (j=i+1; j<*arrResSize; j++){
            if (arrRes[i] < arrRes[j]){
                int temp = arrRes[i];
                arrRes[i] = arrRes[j];
                arrRes[j] = temp;
            }
        }
    }
}