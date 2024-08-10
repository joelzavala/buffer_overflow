#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 50

void vulnerable_function(const char *str) {
    char buffer[BUFFER_SIZE];
    
    // Ensure input length does not exceed buffer size - 1 (for null terminator)
    size_t input_len = strlen(str);
    if (input_len >= BUFFER_SIZE - strlen("Hello, ")) {
        printf("Input too long, truncating...\n");
        input_len = BUFFER_SIZE - strlen("Hello, ") - 1;
    }
    
    // Safe copying using strncpy
    strncpy(buffer, "Hello, ", BUFFER_SIZE);
    strncat(buffer, str, input_len);
    buffer[BUFFER_SIZE - 1] = '\0'; // Ensure null termination
    
    printf("%s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }
    vulnerable_function(argv[1]);
    return 0;
}
