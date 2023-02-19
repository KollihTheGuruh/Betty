#include <stdio.h>

int main(void)
{
    int math, eng, sci, sst, kisw, tot;
    char student_first_name[15];
    char student_second_name[15];
    float avg;

    printf("Enter student second name,Enter student first name: ");
    scanf("%s %s", student_first_name,student_second_name);

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
    avg = (float)tot / 5;

    printf("Name: %s\n", student_first_name);
    printf("Total marks: %d\n", tot);
    printf("Average marks: %.2f\n", avg);

    return 0;
}
