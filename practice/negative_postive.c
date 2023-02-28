#include <stdio.h>

int main()
{
	double number;

	printf("Enter number: ");
	scanf("%lf", &number);

	if(number>0)
	{

		printf("The number is postive\n");
	}
	if(number<0)
        {

                printf("The number is negative\n");
        }
	if(number==0)
        {

                printf("The number is zero\n");
 	}
	
	return (0);
}
