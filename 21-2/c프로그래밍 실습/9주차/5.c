#include <stdio.h>

void maxMinOfTen(int number[10], int *maxmin[]);

int main(void) {

    int num[10];      // 10개의 숫자를 받을 배열
    int *max_min[2];  // 최댓값과 최솟값을 가리킬 포인터 배열 
    
    // 변수 입력
    for (int i = 0; i < 10; i++) {
        printf("%d번째 숫자를 입력하시오. ", i + 1);
        scanf("%d", &num[i]);
    }
    // 결과 연산
    maxMinOfTen(num, max_min);
    
    // 결과 출력
    printf("가장 큰 수는 %d이고, 가장 작은 수는 %d입니다.\n", *max_min[0], *max_min[1]);
    
    return 0;
}

void maxMinOfTen(int number[10], int *maxmin[]) {
    //maxmin[0] -> 최댓값의 포인터, maxmin[1] -> 최솟값의 포인터
    int max = -9999, min = 9999;
    maxmin[0] = &max;
    maxmin[1] = &min;

    for (int i = 0; i < 10; i++) {
        if (*maxmin[0] < number[i]) maxmin[0] = &number[i];
        if (*maxmin[1] > number[i]) maxmin[1] = &number[i];
    }
}