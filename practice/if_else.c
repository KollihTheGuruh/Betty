#include <stdio.h>

int main()
{
	int marks;

	printf("Enter marks: ");
	scanf("%d", &marks);


if (marks >= 80 && marks <= 100){
	printf("Your Grade is A\n");
    }
    else if (marks >= 60 && marks <= 79){
	printf("Your Grade is B\n");
    }
    else if (marks >= 50 && marks <= 59){
	printf("Your Grade is C\n");
    }
    else if (marks >= 40 && marks <= 49){
	printf("Your Grade is D\n");
    }
    else if (marks >= 0 && marks <= 39){
	printf("Your Grade is E\n");
    }
    else
    {
	    printf("Invalid entry\n");
    }
}
