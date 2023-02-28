#include <stdio.h>

int main() 
{
    double salary;
    double *ptr;
    
    printf("Enter your salary: ");
    scanf("%lf", &salary);
    
    /* Assign the address of salary to ptr */
    ptr = &salary;
    
    /* Print the value of salary using the pointer */
    printf("Your salary is: %.2lf\n", *ptr);
    
    /* Increase the value of salary by two times using the pointer */
    *ptr = (salary * 2);
    
    /* Print the new value of salary using the pointer */
    printf("Your new salary is: %.2lf\n", *ptr);

     printf("Address of salary: %p\n", &ptr);
	printf("Address of new salary: %p\n", &salary);
    
    return 0;
}
