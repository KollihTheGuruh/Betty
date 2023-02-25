#include <stdio.h>

int main()
{
    int i, number0fnums = 0, total = 0, value;
    float average;

    printf("How many numbers are to be read?: ");
    scanf("%d", &number0fnums);

    for (i = 0; i < number0fnums; i++)
    {
        scanf("%d", &value);
        total += value; // eq. total = total + value;
        printf("Read %d\n", value);
    }
    average = (float)total / (float)number0fnums;
    printf("You read %d values. Average = %f.\n", number0fnums, average);

    return (0);
}
