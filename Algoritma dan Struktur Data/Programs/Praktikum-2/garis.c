// Ahmad Nadil
// 13521024
// File garis.c

#include <stdio.h>
#include <math.h>
#include "garis.h"

void CreateGaris (GARIS * L, POINT P1, POINT P2)
{
    PAwal(*L) = P1;
    PAkhir(*L) = P2;
}

void BacaGARIS(GARIS * L)
{
    POINT P1, P2;
    BacaPOINT(&P1);
    BacaPOINT(&P2);
    while(EQ(P1,P2))
    {
        printf("Garis tidak valid\n");
        BacaPOINT(&P1);
        BacaPOINT(&P2);
    }
    CreateGaris(L,P1,P2);
}

void TulisGARIS(GARIS L)
{
    printf("((%.2f,%.2f),(%.2f,%.2f))",Absis(PAwal(L)),Ordinat(PAwal(L)),Absis(PAkhir(L)),Ordinat(PAkhir(L)));
}

float PanjangGARIS (GARIS L)
{
    return sqrt((Absis(PAwal(L)) - Absis(PAkhir(L))) * (Absis(PAwal(L)) - Absis(PAkhir(L))) + (Ordinat(PAwal(L)) - Ordinat(PAkhir(L))) * (Ordinat(PAwal(L)) - Ordinat(PAkhir(L))));
}

float Gradien (GARIS L)
{   
    float grad;
    if (Absis(PAwal(L)) == Absis(PAkhir(L))){
        return 0;
    }

    grad = (Ordinat(PAkhir(L)) - Ordinat(PAwal(L))) / (Absis(PAkhir(L)) - Ordinat(PAkhir(L)));
    return grad;
}

void GeserGARIS (GARIS * L, float deltaX, float deltaY)
{
    Absis(PAwal(*L)) += deltaX;
    Absis(PAkhir(*L)) += deltaX;
    Ordinat(PAwal(*L)) += deltaY;
    Ordinat(PAkhir(*L)) += deltaY;
}

boolean IsTegakLurus (GARIS L1, GARIS L2)
{
    return (Gradien(L1) * Gradien (L2) == -1);
}

boolean IsSejajar(GARIS L1, GARIS L2)
{
    return (Gradien(L1) == Gradien(L2));
}