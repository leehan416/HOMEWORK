#include <stdio.h>

int powerOfTwo(int n);

int main(void) {
    int input = 1;


    while (input != 0) {
        printf("숫자 입력 (0 종료) : ");
        scanf("%d", &input);
        printf("2의 %d승은 %d\n", input, powerOfTwo(input));
    }
    return 0;
}


int powerOfTwo(int n) {
    if (n == 0)
        return 1;
    else return 2 * powerOfTwo(n - 1);
}