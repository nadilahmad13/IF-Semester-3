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
    BacaPOINT(&PAwal(*L));
    BacaPOINT(&PAkhir(*L));
    while(EQ(PAwal(*L),PAkhir(*L)))
    {
        printf("Garis tidak valid\n");
        BacaPOINT(&PAwal(*L));
        BacaPOINT(&PAkhir(*L));
    }
    CreateGaris(L,PAwal(*L),PAkhir(*L));
}

void TulisGARIS(GARIS L)
{
    printf("("); TulisPOINT(PAwal(L)); printf(","); TulisPOINT(PAkhir(L)); printf(")");
}

float PanjangGARIS (GARIS L)
{
   return sqrt(pow(Absis(PAkhir(L))-Absis(PAwal(L)),2) + pow(Ordinat(PAkhir(L)) - Ordinat(PAwal(L)),2));
}

float Gradien (GARIS L)
{   
    if (Absis(PAwal(L)) == Absis(PAkhir(L))){
        return 0;
    }

    return (Ordinat(PAkhir(L)) - Ordinat(PAwal(L))) / (Absis(PAkhir(L)) - Ordinat(PAkhir(L)));
}

void GeserGARIS (GARIS * L, float deltaX, float deltaY)
{
    Geser(&PAwal(*L), deltaX, deltaY);
    Geser(&PAkhir(*L), deltaX, deltaY);
}

boolean IsTegakLurus (GARIS L1, GARIS L2)
{
    return (Gradien(L1) * Gradien (L2) == -1);
}

boolean IsSejajar(GARIS L1, GARIS L2)
{
    return (Gradien(L1) == Gradien(L2));
}