#include <stdio.h>

int main() {
    int num1, num2; // 입력받을 변수
    int max = 0; // 최대 공약수
    int value; // 판별용 변수
    scanf("%d %d", &num1, &num2);
    if (num1 > num2) // 더 큰 수로 value 초기화
        value = num1;
    else value = num2;
    for (int i = 1; i < value; i++) // 공약수를 찾기 위한 반복
        if ((num1 % i == 0 && num2 % i == 0) && max < i) // 공약수이면서 현재의 최대 공약수(발견한) 보다 클 떄
            max = i; // i를 최대 공약수로 지정
    printf("%d", max);  // 결과 출력
    return 0;
}