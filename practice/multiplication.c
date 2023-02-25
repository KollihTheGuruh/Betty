#include <stdio.h>

int main()
{
    int i, k;

    for (i = 1; i <= 5; i++)
    {
        for (k = 1; k <= 5; k++)
        {
            printf("%d * %d = %d\t", i, k, i * k);
        }
        printf("\n");
    }
    return (0);
}
