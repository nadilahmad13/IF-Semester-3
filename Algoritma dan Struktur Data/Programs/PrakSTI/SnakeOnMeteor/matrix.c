// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 22 September 2022
// Topik praktikum  : ADT Matrix
// Deskripsi        : File "matrix.c"

#include <stdio.h>
#include "matrix.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m)
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
{
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;

    int i, j;
    for (i = 0; i < nRows; i++)
    {
        for (j = 0; j < nCols; j++)
        {
            MATRIXELMT(*m, i, j) = -1;
        }
    }
}

/* *** Selektor *** */
/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j)
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
{
    return (i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType_Mat getLastIdxRow(Matrix m)
/* Mengirimkan Index baris terbesar m */
{
    return ROW_EFF(m) - 1;
}

IdxType_Mat getLastIdxCol(Matrix m)
/* Mengirimkan Index kolom terbesar m */
{
    return COL_EFF(m) - 1;
}

boolean isIdxEff(Matrix m, IdxType_Mat i, IdxType_Mat j)
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
{
    return (i >= 0 && i <= getLastIdxRow(m) && j >= 0 && j <= getLastIdxCol(m));
}

ElType_Mat getMATRIXELMTDiagonal(Matrix m, IdxType_Mat i)
/* Mengirimkan elemen m(i,i) */
{
    return MATRIXELMT(m, i, i);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut)
/* Melakukan assignment mOut <- mIn */
{
    createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);

    int i, j;
    for (i = 0; i < ROW_EFF(mIn); i++)
    {
        for (j = 0; j < COL_EFF(mIn); j++)
        {
            MATRIXELMT(*mOut, i, j) = MATRIXELMT(mIn, i, j);
        }
    }
    for (i = 0; i < ROW_EFF(mIn); i++)
    {
        for (j = 0; j < COL_EFF(mIn); j++)
        {
            MATRIXELMT(*mOut, i, j) = MATRIXELMT(mIn, i, j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol)
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
{
    createMatrix(nRow, nCol, m);
    int i,j;
    for (i = 0; i < nRow; i++)
    {
        for (j = 0; j < nCol; j++)
        {
            scanf("%d", &MATRIXELMT(*m, i, j));
        }
    }
}
void displayMatrix(Matrix m)
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    int i,j;
    for (i = 0; i < ROW_EFF(m); i ++){
        for (j = 0; j < COL_EFF(m); j++){
            if (j < COL_EFF(m)-1){
                printf("%d ", MATRIXELMT(m, i,j));
            }else{
                printf("%d\n", MATRIXELMT(m, i,j));
            }
        }
    }
}


/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2)
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
{
    Matrix m;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &m);

    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++)
    {
        for (j = 0; j < COL_EFF(m1); j++)
        {
            MATRIXELMT(m, i, j) = MATRIXELMT(m1, i, j) + MATRIXELMT(m2, i, j);
        }
    }
    return m;
}
Matrix subtractMatrix(Matrix m1, Matrix m2)
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
{
    Matrix m;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &m);

    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++)
    {
        for (j = 0; j < COL_EFF(m1); j++)
        {
            MATRIXELMT(m, i, j) = MATRIXELMT(m1, i, j) - MATRIXELMT(m2, i, j);
        }
    }
    return m;
}
Matrix multiplyMatrix(Matrix m1, Matrix m2)
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
{
    Matrix m;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &m);

    int i, j, k;
    for (i = 0; i < ROW_EFF(m1); i++)
    {
        for (j = 0; j < COL_EFF(m2); j++)
        {
            for (k = 0; k < COL_EFF(m1); k++)
            {
                MATRIXELMT(m, i, j) += MATRIXELMT(m1, i, k) * MATRIXELMT(m2, k, j);
            }
        }
    }
    return m;
}
Matrix multiplyByConst(Matrix m, ElType_Mat x)
/* Mengirim hasil perkalian setiap elemen m dengan x */
{
    Matrix mOut;
    createMatrix(ROW_EFF(m), COL_EFF(m), &mOut);

    int i, j;
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            MATRIXELMT(mOut, i, j) = MATRIXELMT(m, i, j) * x;
        }
    }
    return mOut;
}
void pMultiplyByConst(Matrix *m, ElType_Mat k)
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */
{
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++)
    {
        for (j = 0; j < COL_EFF(*m); j++)
        {
            MATRIXELMT(*m, i, j) *= k;
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
{
    if (ROW_EFF(m1) != ROW_EFF(m2) || COL_EFF(m1) != COL_EFF(m2))
    {
        return false;
    }
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++)
    {
        for (j = 0; j < COL_EFF(m1); j++)
        {
            if (MATRIXELMT(m1, i, j) != MATRIXELMT(m2, i, j))
            {
                return false;
            }
        }
    }
    return true;
}
boolean isMatrixNotEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika m1 tidak sama dengan m2 */
{
    return !isMatrixEqual(m1, m2);
}
boolean isMatrixSizeEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */
{
    return ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2);
}

/* ********** Operasi lain ********** */
int countMATRIXELMT(Matrix m)
/* Mengirimkan banyaknya elemen m */
{
    return ROW_EFF(m) * COL_EFF(m);
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m)
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
{
    return ROW_EFF(m) == COL_EFF(m);
}
boolean isSymmetric(Matrix m)
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
{
    if (!isSquare(m))
    {
        return false;
    }
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            if (MATRIXELMT(m, i, j) != MATRIXELMT(m, j, i))
            {
                return false;
            }
        }
    }
    return true;
}   
boolean isIdentity(Matrix m)
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
    if (!isSquare(m))
    {
        return false;
    }
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            if (i == j)
            {
                if (MATRIXELMT(m, i, j) != 1)
                {
                    return false;
                }
            }
            else
            {
                if (MATRIXELMT(m, i, j) != 0)
                {
                    return false;
                }
            }
        }
    }
    return true;
}
boolean isSparse(Matrix m)
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
    int count = 0;
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            if (MATRIXELMT(m, i, j) != 0)
            {
                count++;
            }
        }
    }
    return count <= (ROW_EFF(m) * COL_EFF(m) * 5 / 100);
}
Matrix negation(Matrix m)
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
{
    Matrix mOut;
    createMatrix(ROW_EFF(m), COL_EFF(m), &mOut);

    int i, j;
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            MATRIXELMT(mOut, i, j) = -MATRIXELMT(m, i, j);
        }
    }
    return mOut;
}
void pNegation(Matrix *m)
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++)
    {
        for (j = 0; j < COL_EFF(*m); j++)
        {
            MATRIXELMT(*m, i, j) = -MATRIXELMT(*m, i, j);
        }
    }
}
float determinant(Matrix m)
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
{
   if (!isSquare(m)){
      return 0;
   }
   int n = getLastIdxRow(m) + 1;
   int tmpRow[11];
   int i, j, k, idx, temp1, temp2;
   int det = 1;
   int co = 1;
   for(i = 0; i < n; i++){
      idx = i;
      while(MATRIXELMT(m,idx,i) == 0 && idx < n){
         idx++;
      }
      if (idx == n){
         return 0;
      }
      if (i != idx){
         for(j = 0; j < n; j++){
            temp1 = MATRIXELMT(m,i,j);
            MATRIXELMT(m,i,j) = MATRIXELMT(m,idx,j);
            MATRIXELMT(m,idx,j) = temp1;
         }
         det *= -1;
      }
      for(j = 0;j<n;j++){
         tmpRow[j] = MATRIXELMT(m,i,j);
      }
      for (j=i+1; j<n; j++){
         temp1 = tmpRow[i];
         temp2 = MATRIXELMT(m,j,i);
         for(k=0;k<n;k++){
            MATRIXELMT(m,j,k) = ((temp1 * MATRIXELMT(m,j,k)) - (temp2 * tmpRow[k]));
         }
         co *= temp1;
      }
   }
   for(i=0;i<n;i++){
      det *= MATRIXELMT(m,i,i);
   }
   return det/co;
}
Matrix transpose(Matrix m)
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
{
    Matrix mOut;
    createMatrix(ROW_EFF(m), COL_EFF(m), &mOut);

    int i, j;
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            MATRIXELMT(mOut, i, j) = MATRIXELMT(m, j, i);
        }
    }
    return mOut;
}
void pTranspose(Matrix *m)
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
{
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++)
    {
        for (j = i + 1; j < COL_EFF(*m); j++)
        {
            int temp = MATRIXELMT(*m, i, j);
            MATRIXELMT(*m, i, j) = MATRIXELMT(*m, j, i);
            MATRIXELMT(*m, j, i) = temp;
        }
    }
}

/* Operasi berbasis baris dan per kolom */


float AvgRow(Matrix M, IdxType_Mat i)

/* Menghasilkan rata-rata dari elemen pada baris ke-i */

/* Prekondisi: i adalah indeks baris efektif dari M */
{
    float sum = 0;
    int j;
    for (j =  0 ;  j < COL_EFF(M) ; j++){
        sum += MATRIXELMT(M,i,j);
    }
    return sum / COL_EFF(M);

}


float AvgCol(Matrix M, IdxType_Mat j)

/* Menghasilkan rata-rata dari elemen pada kolom ke-j */

/* Prekondisi: j adalah indeks kolom efektif dari M */
{
    float sum = 0;
    int i;
    for (i = 0 ; i < ROW_EFF(M) ; i++){
        sum += MATRIXELMT(M,i,j);
    }
    return sum / ROW_EFF(M);
}


void MinMaxRow(Matrix M, IdxType_Mat i, ElType_Mat * max, ElType_Mat * min)

/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */

/* F.S. max berisi elemen maksimum pada baris i dari M

min berisi elemen minimum pada baris i dari M */
{
    *max = MATRIXELMT(M,i,0);
    *min = *max;
    int j;
    for (j = 1 ; j < COL_EFF(M) ; j++){
        if (MATRIXELMT(M,i,j) > *max){
            *max =  MATRIXELMT(M,i,j);
        }
        if (MATRIXELMT(M,i,j) < *min){
            *min =  MATRIXELMT(M,i,j);
        }
    }
}


void MinMaxCol(Matrix M, IdxType_Mat j, ElType_Mat * max, ElType_Mat * min)

/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */

/* F.S. max berisi elemen maksimum pada kolom j dari M

min berisi elemen minimum pada kolom j dari M */
{
    *max = MATRIXELMT(M,0,j);
    *min = *max;
    int i;
    for (i = 1 ; i < ROW_EFF(M) ; i++){
        if (MATRIXELMT(M,i,j) > *max){
            *max =  MATRIXELMT(M,i,j);
        }
        if (MATRIXELMT(M,i,j) < *min){
            *min =  MATRIXELMT(M,i,j);
        }
    }
}


int CountNumRow(Matrix M, IdxType_Mat i, ElType_Mat X)

/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
{
    int j;
    int count = 0;
    for (j = 0 ; j < COL_EFF(M) ; j++){
        if (MATRIXELMT(M,i,j) == X){
            count ++;
        }
    }
    return count;

}

int CountNumCol(Matrix M, IdxType_Mat j, ElType_Mat X)

/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
{
    int i;
    int count = 0;
    for (i = 0 ; i < ROW_EFF(M) ; i++){
        if(MATRIXELMT(M,i,j) == X){
            count++;
        }
    }
    return count;
}

void RotateMat(Matrix *m)

/* I.S. m terdefinisi dan IsSquare(m) */

/* F.S. m "di-rotasi" searah jarum jam

   untuk semua "lapisan" elemen mulai dari yang terluar

   Contoh matrix 3x3 sebelum dirotasi:

   1 2 3

   4 5 6

   7 8 9


   Contoh matrix 3x3 setelah dirotasi:

   4 1 2

   7 5 3

   8 9 6

   Contoh matrix 4x4 sebelum dirotasi:

   1 2 3 4

   5 6 7 8

   9 10 11 12

   13 14 15 16

   Contoh matrix 4x4 setelah dirotasi:

   5 1 2 3

   9 10 6 4

   13 11 7 8

   14 15 16 12

*/

// CONTOH Perpindahan :
// 3 x 3
// MATRIXELMT(0 1) = MATRIXELMT(0 0)
// MATRIXELMT(0 2) = MATRIXELMT(0 1)
// MATRIXELMT(1 2) = MATRIXELMT(0 2)
// MATRIXELMT(2 2) = MATRIXELMT(1 2)
// MATRIXELMT(2 1) = MATRIXELMT(2 2)
// MATRIXELMT(2 0) = MATRIXELMT(2 1)
// MATRIXELMT(1 0) = MATRIXELMT(2 0)
// MATRIXELMT(0 0) = MATRIXELMT(1 0)

{
    int row = 0, col = 0;
    int previous, current;
    int a = ROW_EFF(*m);
    int b = COL_EFF(*m);
    int i;
    while (row < a && col < b) {
        if (row + 1 == a || col + 1 == b) {
            break;
        }
        previous = MATRIXELMT(*m,row + 1,col);
        for (i = col; i < b; i++) {
            current = MATRIXELMT(*m,row,i);
            MATRIXELMT(*m,row,i) = previous;
            previous = current;
        }
        row++;
        for (i = row; i < a; i++) {
            current = MATRIXELMT(*m,i,b-1);
            MATRIXELMT(*m,i,b-1) = previous;
            previous = current;
        }
        b--;
        if (row < a) {
            for (i = b-1; i >= col; i--) {
                current = MATRIXELMT(*m,a-1,i);
                MATRIXELMT(*m,a-1,i) = previous;
                previous = current;
            }
        }
        a--;
        if (col < b) {
            for (i = a-1; i >= row; i--) {
                current = MATRIXELMT(*m,i,col);
                MATRIXELMT(*m,i,col) = previous;
                previous = current;
            }
        }
        col++;
    }
}