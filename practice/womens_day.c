#include <stdio.h>

int main()
{
    float x, y, a;
    for (y = 1.5; y > -1; y -= 0.05)
    {
        // Set foreground color to red
        printf("\x1b[31m");

        for (x = -1.5; x < 1.5; x += 0.025)
        {
            a = x * x + y * y - 1;
            putchar(a * a * a - x * x * y * y * y <= 0.0 ? '*' : ' ');
        }

        // Reset color to default
        printf("\x1b[0m");

        putchar('\n');
    }
    return 0;
}
