// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 20 Oktober 2022
// Topik praktikum  : ADT Stack
// Deskripsi        : File "bigint.c"

// Buatlah program dalam file bernama bigint.c yang membaca 2 (dua) buah string, S1 dan S2, yang masing-masing merepresentasikan sebuah integer besar (big integer) positif atau 0. Panjang setiap string maksimum adalah 100, sehingga integer maksimum yang bisa direpresentasikan terdiri atas 100 digit. Panjang string minimum adalah 1, yaitu jika integer yang direpresentasikan hanya terdiri atas sebuah digit. Selanjutnya program akan menampilkan hasil pengurangan kedua integer tersebut (S1 - S2).


// Kumpulkan bigint.c


// Petunjuk: 

// ● Gunakan stack untuk mensimulasikan pengurangan tiap digit dari integer. Pakailah ADT Stack (file header stack.h) yang telah Anda kerjakan sebagai tugas pra-praktikum.

// ● Konversi masing-masing karakter dalam string menjadi sebuah integer dan dengan menggunakan stack of integer, push setiap integer ke dalam stack. Dengan demikian, bilangan yang merepresentasikan satuan (digit terakhir bilangan) akan berada di top stack. 

// ● S1 mungkin kurang dari S2. Oleh karena itu perlu dilakukan pemeriksaan apakah S1 kurang dari S2, jika iya lakukan pengurangan dengan cara S2-S1 kemudian tandai bahwa nilainya negatif.


// Contoh I/O:

// Input

// Output

// 16
// 16
// 0

// 0
// 12345
// -12345


#include <stdio.h>
#include <stdlib.h>
#include "stack.c"

void deleteZero(Stack *S){
    // menghapus angka 0 pada stack paling bawah
    int temp;
    if (IsEmpty(*S)){
        return;
    }
    else{
        Pop(S, &temp);
        if (temp == 0){
            deleteZero(S);
        }
        else{
            Push(S, temp);
        }
    }
}

void copyStack(Stack Sa, Stack *Sb){
    int temp;
    if (IsEmpty(Sa)){
        return;
    }
    else{
        Pop(&Sa, &temp);
        copyStack(Sa, Sb);
        Push(Sb, temp);
    }
}

boolean isSmaller(Stack S1, Stack S2){
    // mengembalikan true jika S1 < S2
    int temp1, temp2;
    if (IsEmpty(S1) && IsEmpty(S2)){
        return false;
    }
    else if (IsEmpty(S1)){
        return true;
    }
    else if (IsEmpty(S2)){
        return false;
    }
    else{
        Pop(&S1, &temp1);
        Pop(&S2, &temp2);
        if (temp1 < temp2){
            return true;
        }
        else if (temp1 > temp2){
            return false;
        }
        else{
            return isSmaller(S1, S2);
        }
    }
}

int main()
{
    Stack S1, S2, S3;
    CreateEmpty(&S1);
    CreateEmpty(&S2);
    CreateEmpty(&S3);

    char tempc;
    int temp;

    // INPUT S1
    scanf("%c", &tempc);
    while(tempc != '\n'){
        temp = tempc - 48;
        Push(&S1, temp);
        scanf("%c", &tempc);
    }

    // INPUT S2
    scanf("%c", &tempc);
    while(tempc != '\n'){
        temp = tempc - 48;
        Push(&S2, temp);
        scanf("%c", &tempc);
    }
    
    // KURANGAN
    int i;
    int val1, val2;
    int temp1, temp2;
    boolean negatif = false;

    Stack Sa;
    CreateEmpty(&Sa);
    copyStack(S1, &Sa);

    Stack Sb;
    CreateEmpty(&Sb);
    copyStack(S2, &Sb);

    while (!IsEmpty(S1) && !IsEmpty(S2)){
        if (isSmaller(S1, S2)){
            negatif = true;
            Pop(&S1, &val1);
            Pop(&S2, &val2);
            temp1 = val2 - val1;
            Push(&S3, temp1);
        }
        else{
            Pop(&S1, &val1);
            Pop(&S2, &val2);
            temp1 = val1 - val2;
            Push(&S3, temp1);
        }
    }

    while (!IsEmpty(S1)){
        Pop(&S1, &val1);
        Push(&S3, val1);
    }

    while (!IsEmpty(S2)){
        Pop(&S2, &val2);
        Push(&S3, val2);
    }

    deleteZero(&S3);
    
    // OUTPUT
    if (IsEmpty(S3)){
        printf("%d\n",0);
    }
    else{
        if (negatif){
            printf("%c", '-');
        }
        while (!IsEmpty(S3)){
            Pop(&S3, &temp);
            printf("%d", temp);
        }
    }
    return 0;
}