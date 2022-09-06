#include <stdio.h>

int main()
{
    int n = 1000;
    int x = 0;
    int i;
    for (i = 1 ; i <= n ; i++)
    {
        if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 6 == 0)
        {
            x++;
        }
    }
    printf("%d", x);
}