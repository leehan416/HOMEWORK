#include <stdio.h>

void PrintStar(int size);

int main(void) {
    int input[10];

    // 변수 입력
    printf("숫자 10개를 입력 ");
    for (int i = 0; i < 10; i++)
        scanf("%d", &input[i]);

    // 별 출력
    for (int i = 0; i < 10; i++)
        PrintStar(input[i]);

    return 0;
}

void PrintStar(int size) {
    for (int i = 0; i < size; i++) printf("*");
    printf("\n");
}