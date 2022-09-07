/* File: vector.h */
/* Tanggal: 29 Agustus 2019 */
#include <stdio.h>
#include <math.h>
#include "point.h"
#include "vector.h"

VECTOR MakeVector (float x, float y)
{
    VECTOR V;
    AbsisComponent(V) = x;
    OrdinatComponent(V) = y;
    return V;
}

void TulisVector(VECTOR v)
{
    printf("<%.2f,%.2f>", AbsisComponent(v), OrdinatComponent(v));
}

float Magnitude(VECTOR v){
    return sqrt(pow(AbsisComponent(v),2) + pow(AbsisComponent(v),2));
}

VECTOR Add (VECTOR a, VECTOR b)
{
    VECTOR v;
    AbsisComponent(v) = AbsisComponent(a) + AbsisComponent(b);
    OrdinatComponent(v) = OrdinatComponent(a) + OrdinatComponent(b);
    return v;
}

VECTOR Substract (VECTOR a, VECTOR b)
{
    VECTOR v;
    AbsisComponent(v) = AbsisComponent(a) - AbsisComponent(b);
    OrdinatComponent(v) = OrdinatComponent(a) - OrdinatComponent(b);
    return v;
}

float Dot(VECTOR a, VECTOR b)
{
    return AbsisComponent(a) * AbsisComponent(b) + OrdinatComponent(a) * OrdinatComponent(b);
}

VECTOR Multiply (VECTOR v, float s)
{
    VECTOR x;
    AbsisComponent(x) = s * AbsisComponent(v);
    OrdinatComponent(x) = s * OrdinatComponent(v);
    return x;
}