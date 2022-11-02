#include <stdio.h>
#include "duplicate.c"

void printSet(Set M){
    int i;
    printf("{");
    printf("%d", M.Elements[0]);
    for (i=1; i<M.Count; i++){
        printf(", %d", M.Elements[i]);
    }
    printf("}\n");
}

int main(){
    // Set S;
    // int arr[5] = {1,1,3,1,1};
    // int arrSize = 5;
    // S = arrToSet(arr, arrSize);
    // printSet(S);

    int arr[4] = {1,1,2,3};
    int arrSize = 4;
    int arrRes[4];
    int arrResSize;
    removeDuplicateDesc(arr, arrSize, arrRes, &arrResSize);
    // print arrRes
    int i;
    printf("[");
    printf("%d", arrRes[0]);
    for (i=1; i<arrResSize; i++){
        printf(", %d", arrRes[i]);
    }
    printf("]\n");

}