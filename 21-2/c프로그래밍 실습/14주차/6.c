#include <stdio.h>
#include <string.h>

void rPrint(char *str, int n);

int main(void) {
    char str[80];
    printf("Enter a string >> ");
    fgets(str, 80, stdin);
    str[strlen(str) - 1] = '\0';
    rPrint(str, strlen(str));
    return 0;
}

void rPrint(char *str, int n) {
    if (n == -1) return;
    if (*(str + n) != '\0')
        printf("%2d. %c\n", (int) (strlen(str) - n), *(str + n));
    rPrint(str, n - 1);
}