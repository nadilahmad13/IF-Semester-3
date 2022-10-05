#include <stdio.h>
#include "panjangstring.h"

int panjangString(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

int main()
{
    char s[100];
    scanf("%s", s);
    printf("%d", panjangString(s));
    return 0;
}