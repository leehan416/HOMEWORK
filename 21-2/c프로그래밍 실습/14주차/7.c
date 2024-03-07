#include <stdio.h>
#include <string.h>

void rPrint(char *str);

int main(void) {
    char str[80];
    printf("Enter a string >>");
    fgets(str, 80, stdin);
    str[strlen(str) - 1] = '\0';
    rPrint(str);
    printf("\n");
    return 0;
}

void rPrint(char *str) {
    if (strlen(str) <= 2) {
        printf("%s", str);
    } else {
        rPrint(str + 2);
        if ('a' <= *str && *str <= 'z') {
            printf("%c%c", *str - ('a' - 'A'), *(str + 1) - ('a' - 'A'));
        } else {
            printf("%c%c", *str, *(str + 1));
        }

    }
}