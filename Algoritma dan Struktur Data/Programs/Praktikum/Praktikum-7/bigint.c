// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 20 Oktober 2022
// Topik praktikum  : ADT Stack
// Deskripsi        : File "bigint.c"

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

boolean IsEqual(Stack S1, Stack S2){
    Stack temp1, temp2;
    CreateEmpty(&temp1);
    CreateEmpty(&temp2);

    temp1 = S1;
    temp2 = S2;

    int val1,val2;
    boolean flag = true;

    while (!IsEmpty(temp1) && !IsEmpty(temp2) && flag){
        Pop(&temp1,&val1);
        Pop(&temp2,&val2);
        if (val1 != val2){
            flag = false;
        }
    }

    return flag;
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

    // PENGURANGAN
    int carry = 0;
    
    while(!IsEmpty(S1) && !IsEmpty(S2))
    {
        Pop(&S1, &temp);
        carry += temp;
        Pop(&S2,&temp);
        carry -= temp;
        Push(&S3, carry);
        carry = 0;
    }
    
    if (ius(S3)){
        int zero = 0;
        printf("%d\n",zero);
    }
    else{
        while(!IsEmpty(S3)){
            Pop(&S3, &temp);
            printf("%d", temp);
        }
    }
    return 0;
}

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