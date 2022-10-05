#include <stdio.h>
#include "ADTList1.c"

int main(){
    List L;
    int i;
    L = MakeList();

    // set elemen ke-0 sampai ke-10 dengan nilai 0 sampai 10
    for (i = 0; i <= 10; i++){
        Set(&L, i, i);
    }

    // print list until mark
    for (i = 0; i < MaxEl; i++){
        if (L.A[i] == Mark)
            break;
        printf("%d ", L.A[i]);
    }

    // print length
    printf("\nLength: %d\n", Length(L));

    // print first and last index
    printf("First index: %d\n", FirstIdx(L));
    printf("Last index: %d\n", LastIdx(L));

    // isIdxValid
    printf("Is index 5 valid? %d\n", IsIdxValid(L, 5));
    printf("Is index 15 valid? %d\n", IsIdxValid(L, 15));
    printf("Is index -1 valid? %d\n", IsIdxValid(L, -1));

    // isIdxEff
    printf("Is index 5 effective? %d\n", IsIdxEff(L, 5));
    printf("Is index 15 effective? %d\n", IsIdxEff(L, 15));

    // Search
    printf("Search 5: %d\n", Search(L, 5));
    printf("Search 15: %d\n", Search(L, 15));

    // InsertFirst
    InsertFirst(&L, 66);
    printf("InsertFirst 66: ");
    for (i = 0; i < MaxEl; i++){
        if (L.A[i] == Mark)
            break;
        printf("%d ", L.A[i]);
    }

    // InsertLast
    InsertLast(&L, 77);
    printf("\nInsertLast 77: ");
    for (i = 0; i < MaxEl; i++){
        if (L.A[i] == Mark)
            break;
        printf("%d ", L.A[i]);
    }

    // InsertAt
    InsertAt(&L, 88, 5);
    printf("\nInsertAt 88 at index 5: ");
    for (i = 0; i < MaxEl; i++){
        if (L.A[i] == Mark)
            break;
        printf("%d ", L.A[i]);
    }

    // DeleteFirst
    DeleteFirst(&L);
    printf("\nDeleteFirst: ");
    for (i = 0; i < MaxEl; i++){
        if (L.A[i] == Mark)
            break;
        printf("%d ", L.A[i]);
    }

    // DeleteLast
    DeleteLast(&L);
    printf("\nDeleteLast: ");
    for (i = 0; i < MaxEl; i++){
        if (L.A[i] == Mark)
            break;
        printf("%d ", L.A[i]);
    }

    // DeleteAt
    DeleteAt(&L, 4);
    printf("\nDeleteAt index 5: ");
    for (i = 0; i < MaxEl; i++){
        if (L.A[i] == Mark)
            break;
        printf("%d ", L.A[i]);
    }

    // Concat
    List L2;
    L2 = MakeList();
    for (i = 0; i <= 10; i++){
        Set(&L2, i, 555);
    }

    List L3 = Concat(L, L2);
    printf("\nConcat L2 to L: ");
    for (i = 0; i < MaxEl; i++){
        if (L3.A[i] == Mark)
            break;
        printf("%d ", L3.A[i]);
    }

    return 0;   
}