#include <stdio.h>

int rSpaces(char* str);

int main(void) {
	char line[100];
	printf("Enter a string > ");
	fgets(line, 100, stdin);
	printf("spaces : %d\n", rSpaces(line));
	return 0;
}
int rSpaces(char* str){
    int value = 0;
    if (*str == ' ')
        value = 1;
    if (*str == '\0' || *str == '\n')
        return 0;
    return rSpaces(str+ 1) + value;
}
