#include <string.h>
#include "password.h"

int verify_password(const char* password) {
    // Check password length
    if (strlen(password) < 8) {
        return 0;
    }
    
    // Check password complexity
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        } else if (islower(password[i])) {
            has_lowercase = 1;
        } else if (isdigit(password[i])) {
            has_digit = 1;
        }
    }
    
    if (!has_uppercase || !has_lowercase || !has_digit) {
        return 0;
    }
    
    // Password is valid
    return 1;
}
