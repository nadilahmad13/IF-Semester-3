#include <stdio.h>
#include <stdlib.h>

static int bunny(int l, int r, int *A){
    int x = A[1];
    int i = l-1;
    int j = r+1;
    while (i < j){
        do j--; while(A[j] > x);
        do i++; while (A[i] < x);
        if (i < j){
            int t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    return j;
}

int main(){
    return 0;
}