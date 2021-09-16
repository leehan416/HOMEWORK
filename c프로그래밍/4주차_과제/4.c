#include <stdio.h>

int main() {
    int year; // 입력받을 변수
    scanf("%d", &year); //변수 입력
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) // 조건 검사
        printf("%d년은 윤년 입니다.", year); // 결과 출력
    else // 아니라면
        printf("%d년은 윤년이 아닙니다.", year); // 결과 출력

    return 0;
}