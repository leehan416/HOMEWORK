#include <stdio.h>

int maxOfTen(int number[10]);

int minOfTen(int number[10]);

int main(void) {
    int input[10];

    //변수 입력
    for (int i = 0; i < 10; i++) {
        printf("%d번째 숫자를 입력하시오. ", i + 1);
        scanf("%d", &input[i]);
    }

    //출력
    printf("가장 큰 수는 %d이고, 가장 작은 수는 %d입니다.", maxOfTen(input), minOfTen(input));

    return 0;
}


int maxOfTen(int number[10]) {
    int max = -9999;
    for (int i = 0; i < 10; i++)
        if (max < number[i])
            max = number[i];
        
    return max;
}

int minOfTen(int number[10]) {
    int min = 9999;
    for (int i = 0; i < 10; i++)
        if (min > number[i])
            min = number[i];
    return min;
}
