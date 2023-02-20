#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char input[100];
    time_t start_time, current_time;

    printf("Enter something: ");

    start_time = time(NULL);

    while (fgets(input, 100, stdin) != NULL) {
        printf("Eat, Code, Sleep, Code\n");
        start_time = time(NULL);
        printf("Enter something: ");
    }

    while (1) {
        current_time = time(NULL);
        if (difftime(current_time, start_time) >= 10.0) {
            printf("Dead or Asleep\n");
            break;
        }
    }

    return 0;
}
