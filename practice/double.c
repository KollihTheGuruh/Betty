#include <stdio.h>

int main() {
    double salary = 4;
    double *ptr;
    double **ptr2 = &ptr;

    /* Assign the address of salary to ptr */
    ptr = &salary;

    /* Print the value of salary using the pointer */
    printf("Your salary is: %.2lf\n", *ptr);

    /* Increase the value of salary by two times using the pointer */
    *ptr = (salary * 2);

    /* Print the new value of salary using the pointer */
    printf("Your new salary is: %.2lf\n", *ptr);

    /* Print the address of salary and the new salary using the pointer */
    printf("Address of salary: %p\n", ptr);
    printf("Address of new salary: %p\n", &salary);

    /* Print the address of the pointer variable and the double pointer variable */
    printf("Address of ptr: %p\n", &ptr);
    printf("Address of ptr2: %p\n", &ptr2);
    printf("Value of ptr2: %p\n", ptr2);
    printf("Value of *ptr2: %p\n", *ptr2);

    return 0;
}

