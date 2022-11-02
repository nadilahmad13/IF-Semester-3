#include <stdio.h>
#include <stdlib.h>

short loop_while (short a, short b)
{
    short result = 0;
    while (a > b){
        result = result + (a*b);
        a = a-1;
    }
    return result;
}

long fun_b (unsigned long x)
{
    long val = 0;
    long i;
    for (i = 64 ; i != 0 ; i--){
        val = (val << 1) | (x & 0x1);
        x = x >> 1;
    }
    return val;
}

void switcher (long a, long b, long c, long *dest)
{
    long val;
    switch(a){
        case 5:
            c = b ^ 15;
            /* Fall through */
        case 0:
            val = c + 112;
            break;
        case 2:
        case 7:
            val = (c + b) << 2;
            break;
        case 4:
            val = a;
            break;
        default:
            val = b;
    }
    *dest = val;
}