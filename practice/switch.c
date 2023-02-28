#include <stdio.h>
#include <ctype.h>

int main()
{
    char grade;
    
    printf("Enter grade: ");
    scanf("%c", &grade);

    grade = toupper(grade);

switch (grade)
{
case 'A':
    printf("Excellent\n");
    break;
case 'B':
    printf("Very Good\n");
    break;
case 'C':
    printf("Good\n");
    break;
case 'D':
    printf("Fair\n");
    break;
case 'E':
    printf("Fail\n");
    break;

default:
    printf("Enter valid grade!\n");
    break;
}
return (0);
}
