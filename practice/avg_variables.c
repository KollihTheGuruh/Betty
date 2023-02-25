#include <stdio.h>

int main()
{
    int i, numberOfnums = 0, total = 0,valsRead, value;
    float average;

	valsRead =scanf("%d", &value);
	while(valsRead > 0)
    {
        if(value < 0)
	{
		valsRead = scanf("%d", &value);
		continue;
	}
	    numberOfnums++;
	    total += value; // eq. total = total + value;
        printf("Read %d\n", value);
	valsRead = scanf("%d", &value);

    }
    average = (float)total / (float)numberOfnums;
    printf("You read %d values. Average = %f.\n", numberOfnums, average);

    return (0);
}
