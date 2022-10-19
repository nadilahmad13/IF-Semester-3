// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 19 Oktober 2022
// Topik praktikum  : ADT Stack
// Deskripsi        : File "bigint.c"

#include <stdio.h>
#include <stdlib.h>
#include "stack.c"

int main(){
    Stack S1, S2, SPlus;
    CreateEmpty(&S1);
    CreateEmpty(&S2);
    CreateEmpty(&SPlus);

    char tempc;
    int temp;
    scanf("%c", &tempc);

    while(tempc != '#'){
        temp = tempc - 48;
        Push(&S1, temp);
        scanf("%c", &tempc);
    }

    scanf("%c", &tempc);
    scanf("%c", &tempc);
    while(tempc != '#'){
        temp = tempc - 48;
        Push(&S2, temp);
        scanf("%c", &tempc);
    }

    int carry = 0;
    while(!IsEmpty(S1) && !IsEmpty(S2)){
        Pop(&S1, &temp);
        carry += temp;
        Pop(&S2, &temp);
        carry += temp;
        Push(&SPlus, carry % 10);
        carry /= 10;
    }

    while(!IsEmpty(S1)){
        Pop(&S1, &temp);
        carry += temp;
        Push(&SPlus, carry % 10);
        carry /= 10;
    }

    while(!IsEmpty(S2)){
        Pop(&S2, &temp);
        carry += temp;
        Push(&SPlus, carry % 10);
        carry /= 10;
    }

    if(carry != 0){
        Push(&SPlus, carry);
    }

    while(!IsEmpty(SPlus)){
        Pop(&SPlus, &temp);
        printf("%d", temp);
    }

    printf("\n");
}