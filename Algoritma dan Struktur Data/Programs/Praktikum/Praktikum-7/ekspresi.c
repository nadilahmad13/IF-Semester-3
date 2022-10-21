// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 20 Oktober 2022
// Topik praktikum  : ADT Stack
// Deskripsi        : File "ekspresi.c"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.c"
#include "wordmachine.c"

int main()
{
    Stack S;
    CreateEmpty(&S);
    STARTWORD();
    int temp;
    int val1, val2;
    int i;
    while (!endWord){
        if (currentWord.TabWord[0] >= '0' && currentWord.TabWord[0] <= '9'){
            printf("%s", currentWord.TabWord);
            temp = 0;
            for (i = 0; i < currentWord.Length; i++){
                temp = temp * 10 + (currentWord.TabWord[i] - 48);
            }
            Push(&S, temp);
            printf("\n");
        } else {
            Pop(&S, &val2);
            Pop(&S, &val1);
            printf("%d %c %d", val1, currentWord.TabWord[0], val2);
            switch (currentWord.TabWord[0]){
                case '+':
                    temp = val1 + val2;
                    break;
                case '-':
                    temp = val1 - val2;
                    break;
                case '*':
                    temp = val1 * val2;
                    break;
                case '/':
                    temp = val1 / val2;
                    break;
                case '^':
                    temp = pow(val1, val2);
                    break;
            }
            printf("\n%d\n", temp);
            Push(&S, temp);
        }
        ADVWORD();
    }
    if (IsEmpty(S)){
        printf("Ekspresi kosong\n");
    } else {
        Pop(&S, &temp);
        printf("Hasil=%d\n", temp);
    }
    return 0;
}