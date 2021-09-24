/*
1 ~ n (n>1) 범위의 정수 중에서 완전수( perfect number)를 모두 찾으시오.

- 완전수 : 어떤 수(n)가, n을 제외한 모든 약수의 합과 같은 경우
Ex)  6 = 1 + 2 + 3
*/
#include <stdio.h>

int main() {
    int num; // 입력받을 변수
    scanf("%d", &num); // 변수 입력
    int sum = 0; // 자기 자신과 같은지 확인을 위한 변수

    for (int i = 1; i < num; i++) {
        sum = 0;
        for (int j = 1; j < i; j++) 
            if (i % j == 0)
                sum += j; // 약수인지 확인하여 더함
        if (sum == i) // 자기 자신과 같은지 검사
            printf("%d ", i); // 출력
    }
    return 0;
}