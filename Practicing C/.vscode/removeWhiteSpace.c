#include <stdio.h>
#include <string.h>

int main() {
    int i, n;
    char str[100];
    gets(str);

    n = strlen(str);
    char result[100] = ""; 
    for (i = 0; i < n; i++) {
        if (str[i] != ' ') {
            strncat(result, &str[i], 1);
        }
    }

    printf("%s\n", result);

    return 0;
}

