#include <stdio.h>
#include <math.h>
// pow() 함수 활용

int main(void) {

    int number[5];        // 입력받은 5개의 숫자
    int pow_value[5][5];  // 임의의 두 수 a, b로 만들 수 있는 a^b의 값 들
    int max = 0, min = pow(9, 9);         // 최댓값과 최솟값
    int max_a, max_b;     // 최댓값을 만들어 내는 경우의 a와 b의 값
    int min_a, min_b;     // 최솟값을 만들어 내는 경우의 a와 b의 값
    int i, j;             // 반복문을 위한 변수

    printf("2에서 9 사이의 숫자 5개를 입력 ");
    scanf("%d %d %d %d %d", &number[0], &number[1], &number[2], &number[3], &number[4]);

    // 배열에 저장하는 반복문
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == j)
                continue; // 같은 수인 경우엔 넘어가기
            
            // 연산
            pow_value[i][j] = pow(number[i], number[j]);

            // 최대 최소 검사
            if (min > pow_value[i][j]) {
                min = pow_value[i][j];
                min_a = number[i];
                min_b = number[j];
            }
            if (max < pow_value[i][j]) {
                max = pow_value[i][j];
                max_a = number[i];
                max_b = number[j];
            }
        }
    }

    // 결과 출력
    printf("\n");
    printf("입력하신 5개의 수로 제곱수를 만들면...\n");
    printf("가장 큰 수는 %d의 %d승인 %d입니다.\n", max_a, max_b, max);
    printf("가장 작은 수는 %d의 %d승인 %d입니다.", min_a, min_b, min);
    return 0;
}