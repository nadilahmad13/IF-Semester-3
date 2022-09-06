// File point.c
// Ahmad Nadil
// 13521024
// Pra Praktikum 2 Algoritma dan Struktur Data

#include <stdio.h>
#include "point.h"
#include "math.h"

void CreatePoint (POINT * P, float X, float Y)
{
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

void BacaPOINT (POINT * P)
{
    float X, Y;
    scanf("%f %f", &X, &Y);
    CreatePoint(P, X, Y);
}

void TulisPOINT(POINT P)
{
    printf("(%.2f, %.2f)", Absis(P), Ordinat(P));
}

boolean EQ (POINT P1, POINT P2)
{
    return (Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2));
}

boolean NEQ (POINT P1, POINT P2)
{
    return !EQ(P1, P2);
}

boolean IsOrigin (POINT P)
{
    return (Absis(P) == 0) && (Ordinat(P) == 0);
}

boolean IsOnSbX(POINT P)
{
    return Ordinat(P) == 0;
}

boolean IsOnSbY(POINT P)
{
    return Absis(P) == 0;
}

int Kuadran (POINT P)
{
    if (Absis(P) > 0)
    {
        if (Ordinat(P) > 0)
        {
            return 1;
        }
        else if (Ordinat(P) < 0)
        {
            return 4;
        }
        else
        {
            return 0;
        }
    }
    else if (Absis(P) < 0)
    {
        if (Ordinat(P) > 0)
        {
            return 2;
        }
        else if (Ordinat(P) < 0)
        {
            return 3;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

POINT NextX (POINT P)
{
    POINT P1;
    CreatePoint(&P1, Absis(P) + 1, Ordinat(P));
    return P1;
}

POINT NextY (POINT P)
{
    POINT P1;
    CreatePoint(&P1, Absis(P), Ordinat(P) + 1);
    return P1;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY)
{
    POINT P1;
    CreatePoint(&P1, Absis(P) + deltaX, Ordinat(P) + deltaY);
    return P1;
}

POINT MirrorOf (POINT P, boolean SbX)
{
    POINT P1;
    if (SbX)
    {
        CreatePoint(&P1, Absis(P), -Ordinat(P));
    }
    else
    {
        CreatePoint(&P1, -Absis(P), Ordinat(P));
    }
    return P1;
}

float Jarak0 (POINT P)
{   
    int num = Absis(P) * Absis(P) + Ordinat(P) * Ordinat(P);
    float temp, sqroot;

    sqroot = num / 2;
    temp = 0;

    while (sqroot != temp)
    {
        temp = sqroot;
        sqroot = (num / temp + temp) / 2;
    }

    return sqroot;
}

float Panjang (POINT P1, POINT P2)
{
    int num = (Absis(P1) - Absis(P2)) * (Absis(P1) - Absis(P2)) + (Ordinat(P1) - Ordinat(P2)) * (Ordinat(P1) - Ordinat(P2));
    float temp, sqroot;

    sqroot = num / 2;
    temp = 0;

    while (sqroot != temp)
    {
        temp = sqroot;
        sqroot = (num / temp + temp) / 2;
    }

    return sqroot;
}

void Geser (POINT *P, float deltaX, float deltaY)
{
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

void GeserKeSbX (POINT *P)
{
    Ordinat(*P) = 0;
}

void GeserKeSbY (POINT *P)
{
    Absis(*P) = 0;
}

void Mirror (POINT *P, boolean SbX)
{
    if (SbX)
    {
        Ordinat(*P) = -Ordinat(*P);
    }
    else
    {
        Absis(*P) = -Absis(*P);
    }
}

void Putar (POINT *P, float Sudut)
{
    float X, Y;
    X = Absis(*P) * cos(Sudut) - Ordinat(*P) * sin(Sudut);
    Y = Absis(*P) * sin(Sudut) + Ordinat(*P) * cos(Sudut);
    CreatePoint(P, X, Y);
}