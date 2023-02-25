#include <stdio.h>
#include "password.h"

int main() {
    char password[100];
    
    printf("Enter password: ");
    scanf("%s", password);
    
    if (verify_password(password)) {
        printf("Password is valid!\n");
    } else {
        printf("Password is invalid.\n");
    }
    
    return 0;
}
