#include <stdio.h>

float bmiFromHW(float *h, float *w);

int main(void) {
    float height, weight, bmi;
    int count = 0;


    for (int i = 0; i < 5; i++) {
        // 변수 입력, 연산
        bmi = bmiFromHW(&height, &weight);
        // 비만 출력
        if (bmi > 25) {
            printf("비만입니다. 키:%.2f미터 몸무게:%.1fkg\n", height, weight);
            count++;
        }
    }
    // 결과 출력
    printf("비만인 사람은 %d명입니다.\n", count);
    
    return 0;
}

float bmiFromHW(float *h, float *w) {
    float bmi;

    // 변수 입력
    printf("신장(cm)과 체중(kg)을 입력하시오. ");
    scanf("%f %f", h, w);
    
    // 결과 연산
    *h *= 0.01;
    bmi = *w / ((*h) * (*h));

    return bmi;
}