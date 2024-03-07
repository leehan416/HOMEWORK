#include <stdio.h>
#include <string.h>

int rStrlen(char* str);

int main(void) {
	char line[100];
	printf("Enter a string > ");
	fgets(line, 100, stdin);
	printf("length : %d\n", rStrlen(line));
	return 0;
}
int rStrlen(char* str){
    int value = 0;
    if (*str != ' ')
        value = 1;
    if (*str == '\0' || *str == '\n')
        return 0;
    return rStrlen(str+ 1) + value;
}