#include <stdio.h>
#include <string.h>

void vulnerable_function(char *str) {
    char buffer[50];
    strcpy(buffer, "Hello, ");
    strcat(buffer, str);
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
