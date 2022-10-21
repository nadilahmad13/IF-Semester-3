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

boolean isAllZero(Stack S){
    int i;
    for (i = 0; i < Top(S); i++){
        if (S.T[i] != 0){
            return false;
        }
    }
    return true;
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

    // PENGURANGAN S1-S2
    int val1, val2;
    int negatif = 0;
    while(!IsEmpty(S1) && !IsEmpty(S2)){
        Pop(&S1, &val1);
        Pop(&S2, &val2);
        if (val1 < val2){
            temp = val2 - val1;
            negatif = 1;
        } else {
            temp = val1 - val2;
        }
        Push(&S3, temp);
    }
    
    while(!IsEmpty(S1)){
        Pop(&S1, &val1);
        Push(&S3, val1);
    }

    while(!IsEmpty(S2)){
        Pop(&S2, &val2);
        Push(&S3, val2);
    }

    // OUTPUT
    if (isAllZero(S3)){
        int zero = 0;
        printf("%d", zero);
    } else {
        if (negatif == 1){
            printf("-");
        }
        while(!IsEmpty(S3)){
            Pop(&S3, &temp);
            printf("%d", temp);
        }
    }
    printf("\n");
    return 0;
}

// boolean IsEqual(Stack S1, Stack S2){
//     Stack temp1, temp2;
//     CreateEmpty(&temp1);
//     CreateEmpty(&temp2);

//     temp1 = S1;
//     temp2 = S2;

//     int val1,val2;
//     boolean flag = true;

//     while (!IsEmpty(temp1) && !IsEmpty(temp2) && flag){
//         Pop(&temp1,&val1);
//         Pop(&temp2,&val2);
//         if (val1 != val2){
//             flag = false;
//         }
//     }

//     return flag;
// }

// int main()
// {
//     Stack S1, S2, S3;
//     CreateEmpty(&S1);
//     CreateEmpty(&S2);
//     CreateEmpty(&S3);

//     char tempc;
//     int temp;

//     // INPUT S1
//     scanf("%c", &tempc);
//     while(tempc != '\n'){
//         temp = tempc - 48;
//         Push(&S1, temp);
//         scanf("%c", &tempc);
//     }

//     // INPUT S2
//     scanf("%c", &tempc);
//     while(tempc != '\n'){
//         temp = tempc - 48;
//         Push(&S2, temp);
//         scanf("%c", &tempc);
//     }

//     // PENGURANGAN
//     int carry = 0;
    
//     while(!IsEmpty(S1) && !IsEmpty(S2))
//     {
//         Pop(&S1, &temp);
//         carry += temp;
//         Pop(&S2,&temp);
//         carry -= temp;
//         Push(&S3, carry);
//         carry = 0;
//     }
    
//     if (ius(S3)){
//         int zero = 0;
//         printf("%d\n",zero);
//     }
//     else{
//         while(!IsEmpty(S3)){
//             Pop(&S3, &temp);
//             printf("%d", temp);
//         }
//     }
//     return 0;
// }

// int stacktoint (Stack S){
//     // Stack STemp;
//     // CreateEmpty(&STemp);
//     // STemp = S;
//     int temp;
//     int result = 0;
//     int i = 1;
//     while (!IsEmpty(S)){
//         result = result + InfoTop(S) * i;
//         Pop(&S,&temp);
//         i *= 10;
//     }
//     return result;
// }

// int main()
// {
//     Stack S1, S2, S3;
//     CreateEmpty(&S1);
//     CreateEmpty(&S2);
//     CreateEmpty(&S3);

//     char tempc;
//     int temp;

//     // INPUT S1
//     scanf("%c", &tempc);
//     while(tempc != '\n'){
//         temp = tempc - 48;
//         Push(&S1, temp);
//         scanf("%c", &tempc);
//     }

//     // INPUT S2
//     scanf("%c", &tempc);
//     while(tempc != '\n'){
//         temp = tempc - 48;
//         Push(&S2, temp);
//         scanf("%c", &tempc);
//     }

//     int val1 = stacktoint(S1);
//     int val2 = stacktoint(S2);

//     printf("%d\n",(val1-val2));

//     return 0;
// }