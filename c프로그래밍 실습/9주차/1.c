#include <stdio.h>

void askHW(float *h, float *w);

int main(void) {
    float height, weight, bmi;
    int count = 0;

    for (int i = 0; i < 5; i++) {
        // 변수입력
        printf("%d번째 사람의 신장(cm)과 체중(kg)을 입력하시오. ", i + 1);
        askHW(&height, &weight); 
        //연산
        bmi = weight / (height * height);
        // count증가
        if (bmi > 25) count++;
    }
    // 결과 출력
    printf("비만인 사람은 %d명입니다.\n", count);
    return 0;

}


void askHW(float *h, float *w) {
    int height, weight;

    scanf("%d %d", &height, &weight); // 입력
    //연산
    *h = (float) height * 0.01; 
    *w = (float) weight;
}

