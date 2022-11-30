#include <stdio.h>
#include <stdlib.h>
#include "point.c"
#include "listlinier.c"
#include "matrix.c"

char IntToMap(char c){
    if (c == -1){ // KOSONG
        return ' ';
    }
    else if (c == 0){ // HEAD
        return 'H';
    }
    else if (c == 8){ // METEOR
        return 'm';
    }
    else if (c == 9){ // FOOD
        return 'o';
    }
    else{ // BODY
        return c + '0';
    }
}

void displayMap(Matrix m){
    int i,j;
    for (i = 0 ; i < COL_EFF(m)+2 ; i++){
        if (i != COL_EFF(m)+1){
            printf("* ");
        }else{
            printf("*\n");
        }
    }

    for (i = 0 ; i < ROW_EFF(m) ; i++){
        printf("* ");
        for (j = 0 ; j < COL_EFF(m) ; j++){
            printf("%c ",IntToMap(MATRIXELMT(m,i,j)));
        }
        printf("*\n");
    }

    for (i = 0 ; i < COL_EFF(m)+2 ; i++){
        if (i != COL_EFF(m)+1){
            printf("* ");
        }else{
            printf("*\n");
        }
    }
}


int main(){
    // MAP CREATION
    Matrix m;
    createMatrix(5,5,&m);

    // SNAKE CREATION
    List l;
    CreateList(&l);
    insertLast(&l,0);
    insertLast(&l,1);
    insertLast(&l,2);
    // displayList(l);

    // PUT THE SNAKE IN A RANDOM INDEX IN THE MAP
    int x,y;
    x = rand() % ROW_EFF(m);
    y = rand() % COL_EFF(m);
    MATRIXELMT(m,x,y) = INFO(l);

    // PUT THE FIRST BODY IN RADNOM ADJANET INDEX FROM THE HEAD IN THE MAP
    int x2,y2;
    x2 = rand() % ROW_EFF(m);
    y2 = rand() % COL_EFF(m);
    while (abs(x2-x) > 1 || abs(y2-y) > 1){
        x2 = rand() % ROW_EFF(m);
        y2 = rand() % COL_EFF(m);
    }
    MATRIXELMT(m,x2,y2) = INFO(NEXT(l));
    displayMap(m);
    // snake movement
}