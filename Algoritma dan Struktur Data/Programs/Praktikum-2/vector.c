// Ahmad Nadil
// 13521024
// File vector.c

#include <stdio.h>
#include <math.h>
#include "vector.h"

void CreateVector(VECTOR *v, float x, float y)
{
    AbsisComponent(*v) = x;
    OrdinatComponent(*v) = y;
}

void TulisVector(VECTOR v)
{
    printf("<.%2f,.%2f>",AbsisComponent(v),OrdinatComponent(v));
}

float Magnitude (VECTOR v)
{
    float ans;
    ans =  sqrt(pow(AbsisComponent(v),2) + pow(OrdinatComponent(v),2));
    return ans;
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
    float ans;
    ans = (AbsisComponent(a) * AbsisComponent(b)) + (OrdinatComponent(a) + OrdinatComponent(b));
    return ans;
}

VECTOR Multiply(VECTOR v, float s)
{
    VECTOR a;
    AbsisComponent(a) = s * AbsisComponent(v);
    OrdinatComponent(a) = s * OrdinatComponent(v);
    return a;
}