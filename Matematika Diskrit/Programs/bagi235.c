#include <stdio.h>

int main()
{
    int n = 500;
    int x = 0;
    int i;
    for (i  = 51 ; i <= n ; i++)
    {
        if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0)
        {
            x++;
        }
    }
    printf("%d", x);
}