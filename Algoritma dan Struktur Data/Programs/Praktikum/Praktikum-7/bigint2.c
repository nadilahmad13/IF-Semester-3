// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 20 Oktober 2022
// Topik praktikum  : ADT Stack
// Deskripsi        : File "bigint.c"

#include <stdio.h>
#include "stack.c"

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
    Stack STemp1, STemp2;
    CreateEmpty(&STemp1);
    CreateEmpty(&STemp2);

    copyStack(S1, &STemp1);
    copyStack(S2, &STemp2);

    int temp1, temp2;
    
    if (IsEmpty(STemp1) && IsEmpty(STemp2)){
        return false;
    }
    else if (IsEmpty(STemp1)){
        return true;
    }
    else if (IsEmpty(STemp2)){
        return false;
    }
    else{
        // check all digits first before returning values
        while (!IsEmpty(STemp1) && !IsEmpty(STemp2)){
            Pop(&STemp1, &temp1);
            Pop(&STemp2, &temp2);
            if (temp1 < temp2){
                // decrease next digitin stack by 1
                int temp;
                Pop(&STemp1, &temp);
                Push(&STemp1, temp - 1);
            }
            else if (temp1 >= temp2){
                return false || isSmaller(STemp1, STemp2);
            }
        }
        if (IsEmpty(STemp1)){
            return true;
        }
        else if (IsEmpty(STemp2)){
            return false;
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

    // S3 = S1-S2
    int val1, val2, result;
    int sisa = 0;
    if (!isSmaller(S1, S2)) {
        while (!IsEmpty(S2)) {
            Pop(&S1, &val1);
            Pop(&S2, &val2);
            result = val1 - val2 + sisa;
            if (result < 0) {
                sisa = -1; 
                result += 10;
                Push(&S3, result);
            }
            else {
                sisa = 0;
                Push(&S3, result);
            }
        }
        while (!IsEmpty(S1)) {
            Pop(&S1, &val1);
            result =  val1 + sisa;
            if (result < 0) {
                sisa = -1; 
                result += 10;
                Push(&S3, result);
            }
            else {
                sisa = 0; 
                Push(&S3, result);
            }
        }
        while (InfoTop(S3) == 0 && Top(S3) > 0) {
            Pop(&S3, &val1);
        }
    }

    else{
        while (!IsEmpty(S1)) {
            Pop(&S2, &val1);
            Pop(&S1, &val2);
            result = val1 - val2 + sisa;
            if (result < 0) {
                sisa = -1; 
                result += 10;
                Push(&S3, result);
            }
            else {
                sisa = 0;
                Push(&S3, result);
            }
        }
        while (!IsEmpty(S2)) {
            Pop(&S2, &val1);
            result =  val1 + sisa;
            if (result < 0) {
                sisa = -1; 
                result += 10;
                Push(&S3, result);
            }
            else {
                sisa = 0; 
                Push(&S3, result);
            }
        }
        while (InfoTop(S3) == 0 && Top(S3) > 0) {
            Pop(&S3, &val1);
        }
        printf("-");
    }

    // OUTPUT
    while (!IsEmpty(S3)){
        Pop(&S3, &temp);
        printf("%d", temp);
    }

    printf("\n");
    return 0;
}