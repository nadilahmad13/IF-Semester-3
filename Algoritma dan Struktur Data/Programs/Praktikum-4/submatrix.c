#include "matrix.c"
#include <stdio.h>

float sumSubmatrix(Matrix m, int startRow, int startCol, int n);

int main(){
    int tc; // test case
    int t; // test
    int N; // size of matrix
    int sub; // size of submatrix
    int tempsum; // temporary sum
    int maxsum; // maximum sum
    int startRow, startCol; // start row and start column of submatrix
    Matrix m, ans;

    printf("Masukkan banyaknya test case: ");
    scanf("%d", &tc); 
    for(t = 0; t<tc; t++){ // for each test case
        maxsum = 0;
        printf("N : "); 
        scanf("%d", &N);
        readMatrix(&m, N, N);
        printf("Submatrix size : ");
        scanf("%d", &sub);
        createMatrix(sub, sub, &ans);
        for(startRow=0; startRow<ROW_EFF(m)-sub+1; startRow++){ 
            for(startCol=0; startCol<COL_EFF(m)-sub+1;startCol++){
                tempsum = sumSubmatrix(m, startRow, startCol, sub);
                if (tempsum>maxsum){
                    maxsum = tempsum;
                }   
            }
        }
        printf("%d\n", maxsum);
    }
}


float sumSubmatrix(Matrix m, int startRow, int startCol, int n){
    // fungsi untuk menghitung jumlah elemen submatrix m dengan ukuran n x n yang dimulai dari startRow dan startCol
    float sum = 0;
    int i, j;
    for(i=startRow;i<startRow+n;i++){
        for(j=startCol;j<startCol+n;j++){
            sum += ELMT(m,i,j);
        }
    }
    return sum;
}
/* Testcase:
1
5
9 10 2 3 4
3 2 2 2 1
10 9 2 2 2
9 10 3 4 5
5 6 9 4 0
2
return 38 */