#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    srand(time(NULL));

    int answer = rand() % 100 + 1;  // 컴퓨터가 만들어 낸 1부터 100사이의 임의의 숫자
    int number_try;                 // 사용자가 제시한 숫자
    int count = 0;                  // 사용자가 맞추려고 시도한 횟수 

    while (1) { // 반복 
        // 변수 입력
        printf("1부터 100까지의 숫자 하나를 맞춰보세요");
        scanf("%d", &number_try);

        // 입력한 값이 맞앗다면
        if (number_try == answer)
            break; // 반복문 나가기
        // 수가 작거나 크면
        else if (number_try > answer)
            printf("좀 더 작은 수 입니다.\n");
        else
            printf("좀 더 큰 수입니다.\n");
        count++; // 횟수 증가
    }
    
    // 결과 출력
    printf("%d 번만에 숫자를 맞추셨습니다.", ++count);

    return 0;
}