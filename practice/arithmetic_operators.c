#include <stdio.h>

int main(void)
{
    int math, eng, sci, sst, kisw, tot;
    char student_name[10];

    printf("Enter the name of the student: ");
    scanf("%s", &student_name);

    printf("Enter marks for English: ");
    scanf("%d", &eng);

    printf("Enter marks for Science: ");
    scanf("%d", &sci);

    printf("Enter marks for Social Studies: ");
    scanf("%d", &sst);

    printf("Enter marks for Maths: ");
    scanf("%d", &math);

    printf("Enter marks for Kiswahili: ");
    scanf("%d", &kisw);

    tot = eng + kisw + math + sst + sci;

    printf("Name: %s\n", student_name);
    printf("Total marks %s: %d\n",student name, tot);

    return 0;
}
