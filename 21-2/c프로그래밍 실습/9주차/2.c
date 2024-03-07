#include <stdio.h>

void maxMinOfTen(int number[10], int *max, int *min);

int main(void) {
    int num[10];      // 10개의 숫자를 받을 배열
    int max_num;      // 가장 큰 숫자를 리턴 받을 변수, 
    int min_num;      // 가장 작은 숫자를 리턴 받을 변수

    for (int i = 0; i < 10; i++) {
        // 변수 입력
        printf("%d번째 숫자를 입력하시오. ", i + 1);
        scanf("%d", &num[i]);
    }
    maxMinOfTen(num, &max_num, &min_num); // 함수 호출
    // 결과 출력
    printf("가장 큰 수는 %d이고, 가장 작은 수는 %d입니다.\n", max_num, min_num);
 
    return 0;
}

void maxMinOfTen(int number[10], int *max, int *min) {
    // 값 찾기
    for (int i = 0; i < 10; i++) { 
        if (number[i] > *max)
            *max = number[i];
        if (number[i] < *min)
            *min = number[i];
    }
}