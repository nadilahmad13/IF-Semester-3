#include <stdio.h>
#include <stdlib.h>
#include "stacklinked.c"
#include "wordmachine.c"

boolean EndWord;
Word currentWord;

int main(){
    Stack S;
    CreateStack(&S);
    STARTWORD();
    int i,temp,tempbuangan;
    char ctemp;
    boolean cekSiku = false;
    boolean cekBulat = false;
    boolean cekKurawal = false;
    boolean cekSegitiga = false;
    int cekTegak = 1;

    while(!EndWord){
        for (i = 0 ; i < currentWord.Length ; i++){
            ctemp = currentWord.TabWord[i];
            if (ctemp == '['){
                cekSiku = true;
                push(&S,0);
                DisplayStack(S);
                printf("\n");
            }
            else if (ctemp == '('){
                cekBulat = true;
                push(&S,1);
                DisplayStack(S);
                printf("\n");
            }
            else if (ctemp == '|' && cekTegak == 1){
                cekTegak++;
                push(&S,2);
                DisplayStack(S);
                printf("\n");
            }
            else if (ctemp == '{'){
                cekKurawal = true;
                push(&S,3);
                DisplayStack(S);
                printf("\n");
            }
            else if (ctemp == '<'){
                cekSegitiga = true;
                push(&S,4);
                DisplayStack(S);
                printf("\n");
            }

            else if(ctemp == ']' && !cekBulat && !cekKurawal && !cekSegitiga && cekTegak != 2){
                cekSiku = false;
                if(!isEmpty(S)){
                   pop(&S,&tempbuangan); 
                }
                DisplayStack(S);
                printf("\n");
            }
            else if(ctemp == ')' && !cekSiku && !cekKurawal && !cekSiku & cekTegak != 2){
                cekBulat =false;
                if(!isEmpty(S)){
                   pop(&S,&tempbuangan); 
                }
                DisplayStack(S);
                printf("\n");
            }
            else if(ctemp == '}' && !cekSiku && !cekBulat && !cekSegitiga && cekTegak != 2){
                cekKurawal = false;
                if(!isEmpty(S)){
                   pop(&S,&tempbuangan); 
                }
                DisplayStack(S);
                printf("\n");
            }
            else if (ctemp == '|' && cekTegak == 2 && !cekSiku && !cekBulat && !cekSegitiga &&!cekKurawal){
                cekTegak--;
                if(!isEmpty(S)){
                   pop(&S,&tempbuangan); 
                }
                DisplayStack(S);
                printf("\n");
            }
            else if(ctemp == '>' && cekTegak != 2 && !cekSiku && !cekBulat && !cekKurawal){
                cekSegitiga = false;
                if(!isEmpty(S)){
                   pop(&S,&tempbuangan); 
                }
                DisplayStack(S);
                printf("\n");
            }
            
            printf("cekSiku : %d\n", cekSiku);
            printf("cekBulat : %d\n",cekBulat);
            printf("cekKurawal : %d\n", cekKurawal);
            printf("cekSegitiga : %d\n", cekSegitiga);
            printf("cekTegak : %d\n", cekTegak);
        }
    ADVWORD();
    }
    if (!isEmpty(S)){
        printf("kurung tidak valid\n");
    }
    else {
        printf("kurung valid\n");
    }
}

// [(1+1)*(7/3)-|(6/3+-2*9)|] = x.
// [()()|()|]