#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "point.h"
#include "listdp.h"
#include "matrix.h"

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
    printf("---------------------\n");
    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            printf("| %c ", IntToMap(MATRIXELMT(m, i, j)));
        }
        printf("|\n---------------------\n");
    }

}
boolean isMoveValid(Matrix m, int x, int y){
    return (x >= 0 && x < 5 && y >= 0 && y < 5 && (MATRIXELMT(m, x, y) == -1 || MATRIXELMT(m, x, y) == 9));
}

void food(Matrix *m){
    int x,y;
    do{
        x = rand() % 5;
        y = rand() % 5;
    }while(MATRIXELMT(*m, x, y) != -1);
    MATRIXELMT(*m, x, y) = 9;
}

void eat(List *l, Matrix *m){

    int x,y;
    x = ABSCISSA((*l).First->loc);
    y = ORDINATE((*l).First->loc);
    // insert last new list
    int temp = l->Last->info + 1;
    int tempx = ABSCISSA(l->Last->loc);
    int tempy = ORDINATE(l->Last->loc);
    address p = Alokasi(temp);

    if(MATRIXELMT(*m,tempx-1,tempy) == -1){
        createPoint(&p->loc, tempx-1, tempy);
        p->loc.x = tempx-1;
        p->loc.y = tempy;
        InsertLast(l, p);
    }
    else if(MATRIXELMT(*m,tempx,tempy-1) == -1){
        createPoint(&p->loc, tempx+1, tempy);
        p->loc.x = tempx+1;
        p->loc.y = tempy;
        InsertLast(l, p);
    }
    else if(MATRIXELMT(*m,tempx,tempy+1) == -1){
        createPoint(&p->loc, tempx, tempy-1);
        p->loc.x = tempx;
        p->loc.y = tempy-1;
        InsertLast(l, p);
    }
    else if(MATRIXELMT(*m,tempx+1,tempy) == -1){
        createPoint(&p->loc, tempx, tempy+1);
        p->loc.x = tempx;
        p->loc.y = tempy+1;
        InsertLast(l, p);
    }
    else{
        printf("Game Over\n");
    }

    food(m);
}

void meteor(Matrix *m){
    int x,y;
    do{
        x = rand() % 5;
        y = rand() % 5;
    }while(MATRIXELMT(*m, x, y) != -1);
    MATRIXELMT(*m, x, y) = 8;
}

void hit(List *l, Matrix *m){
    // klo head
    int x,y;
    x = ABSCISSA((*l).First->loc);
    y = ORDINATE((*l).First->loc);
    if(MATRIXELMT(*m,x,y) == 8){
        printf("Game Over\n");
    }
}

void snakeMovement(Matrix *m, List *L, char move){
    // move w a s d
    int x,y,i;
    address temp;

    if (move == 'w'){ // MOVE UP
        // UPDATE HEAD LOCATION
        x = L->First->loc.x-1;
        y = L->First->loc.y;
        if (isMoveValid(*m, x, y)){ // CHECK IF THE MOVE IS VALID
            MATRIXELMT(*m, L->Last->loc.x, L->Last->loc.y) = -1; // UPDATE THE LAST ELEMENT LOCATION IN THE MAP TO EMPTY
            
            // UPDATE THE LOCATION OF THE SNAKE BODY
            temp = L->Last;
            while (L->Last->prev != Nil){
                L->Last->loc = L->Last->prev->loc;
                L->Last = L->Last->prev;
            }
            L->Last = temp;

            if (MATRIXELMT(*m, x, y) == 9){ // IF THE MOVE IS TO THE FOOD
                eat(L, m);
            }

            // UPDATE THE HEAD LOCATION
            L->First->loc.x = x;
            L->First->loc.y = y;

            // UPDATE THE MAP WITHT HE SNAKE
            MATRIXELMT(*m, x, y) = 0;
            temp = L->First->next;
            i = 1;
            while (temp != Nil){
                MATRIXELMT(*m, temp->loc.x, temp->loc.y) = i;
                temp = temp->next;
                i++;
            }

            // printf("\033[2J\033[1;1H");
            displayMap(*m);
            printf("Valid move\n");
        }
        else{
            printf("Invalid move!\n");
        }
    }

    else if (move == 'a'){ // MOVE LEFT
        // UPDATE HEAD LOCATION
        x = L->First->loc.x;
        y = L->First->loc.y-1;
        if (isMoveValid(*m, x, y)){ // CHECK IF THE MOVE IS VALID
            MATRIXELMT(*m, L->Last->loc.x, L->Last->loc.y) = -1; // UPDATE THE LAST ELEMENT LOCATION IN THE MAP TO EMPTY
            
            // UPDATE THE LOCATION OF THE SNAKE BODY
            temp = L->Last;
            while (L->Last->prev != Nil){
                L->Last->loc = L->Last->prev->loc;
                L->Last = L->Last->prev;
            }
            L->Last = temp;

            if (MATRIXELMT(*m, x, y) == 9){ // IF THE MOVE IS TO THE FOOD
                eat(L, m);
            }

            // UPDATE THE HEAD LOCATION
            L->First->loc.x = x;
            L->First->loc.y = y;

            // UPDATE THE MAP WITHT HE SNAKE
            MATRIXELMT(*m, x, y) = 0;
            temp = L->First->next;
            i = 1;
            while (temp != Nil){
                MATRIXELMT(*m, temp->loc.x, temp->loc.y) = i;
                temp = temp->next;
                i++;
            }

            // printf("\033[2J\033[1;1H");
            displayMap(*m);
            printf("Valid move\n");
        }
        else{
            printf("Invalid move!\n");
        }
    }

    else if (move == 's'){ // MOVE DOWN
        // UPDATE HEAD LOCATION
        x = L->First->loc.x+1;
        y = L->First->loc.y;
        if (isMoveValid(*m, x, y)){ // CHECK IF THE MOVE IS VALID
            MATRIXELMT(*m, L->Last->loc.x, L->Last->loc.y) = -1; // UPDATE THE LAST ELEMENT LOCATION IN THE MAP TO EMPTY
            
            // UPDATE THE LOCATION OF THE SNAKE BODY
            temp = L->Last;
            while (L->Last->prev != Nil){
                L->Last->loc = L->Last->prev->loc;
                L->Last = L->Last->prev;
            }
            L->Last = temp;

            if (MATRIXELMT(*m, x, y) == 9){ // IF THE MOVE IS TO THE FOOD
                eat(L, m);
            }

            // UPDATE THE HEAD LOCATION
            L->First->loc.x = x;
            L->First->loc.y = y;

            // UPDATE THE MAP
            MATRIXELMT(*m, x, y) = 0;
            temp = L->First->next;
            i = 1;
            while (temp != Nil){
                MATRIXELMT(*m, temp->loc.x, temp->loc.y) = i;
                temp = temp->next;
                i++;
            }

            // printf("\033[2J\033[1;1H");
            displayMap(*m);
            printf("Valid move\n");
        }
        else{
            printf("Invalid move!\n");
        }
    }
    else if (move == 'd'){ // MOVE RIGHT
        // UPDATE HEAD LOCATION
        x = L->First->loc.x;
        y = L->First->loc.y+1;
        if (isMoveValid(*m, x, y)){ // CHECK IF THE MOVE IS VALID
            MATRIXELMT(*m, L->Last->loc.x, L->Last->loc.y) = -1; // UPDATE THE LAST ELEMENT LOCATION IN THE MAP TO EMPTY
            
            // UPDATE THE LOCATION OF THE SNAKE BODY
            temp = L->Last;
            while (L->Last->prev != Nil){
                L->Last->loc = L->Last->prev->loc;
                L->Last = L->Last->prev;
            }
            L->Last = temp;

            if (MATRIXELMT(*m, x, y) == 9){ // IF THE MOVE IS TO THE FOOD
                eat(L, m);
            }

            // UPDATE THE HEAD LOCATION
            L->First->loc.x = x;
            L->First->loc.y = y;

            // UPDATE THE MAP
            MATRIXELMT(*m, x, y) = 0;
            temp = L->First->next;
            i = 1;
            while (temp != Nil){
                MATRIXELMT(*m, temp->loc.x, temp->loc.y) = i;
                temp = temp->next;
                i++;
            }

            // printf("\033[2J\033[1;1H");
            displayMap(*m);
            printf("Valid move\n");
        }
        else{
            printf("Invalid move!\n");
        }
    } 
}

int main(){
    // MAP CREATION
    Matrix m;
    createMatrix(5,5,&m);

    // SNAKE CREATION
    List L;
    CreateEmpty(&L);
    address P = Alokasi(0);
    InsertLast(&L, P);
    P = Alokasi(1);
    InsertLast(&L, P);
    P = Alokasi(2);
    InsertLast(&L, P);

    // PUT THE SNAKE IN A RANDOM INDEX IN THE MAP
    int x,y;
    x = rand() % ROW_EFF(m);
    y = rand() % COL_EFF(m);

    L.First->loc.x = x;
    L.First->loc.y = y;
    MATRIXELMT(m,x,y) = L.First->info;

    L.First->next->loc.x = x;
    L.First->next->loc.y = y-1;
    // PUT THE REST OF THE BODY NEXT TO THE HEAD
    MATRIXELMT(m,x,y-1) = L.First->next->info;

    L.First->next->next->loc.x = x;
    L.First->next->next->loc.y = y-2;
    MATRIXELMT(m,x,y-2) = L.Last->info;
    char move;
    food(&m);
    displayMap(m);
    while (true){
        scanf("%c", &move);
        snakeMovement(&m, &L, move);
    }
}