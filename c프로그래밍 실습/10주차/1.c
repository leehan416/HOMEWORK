#include <stdio.h>
#include <math.h>

float evalBmi(int h, int w);

int main(void) {
    float height, weight, bmi;
    int count = 0;
    // 이 곳에 코드를 작성하라.
    //---------------------------------------
    FILE *file;
    file = fopen("data.txt", "r");
    for (int i = 0; i < 5; i++) {
        // 데이터 읽기
        fscanf(file, "%f", &height);
        fscanf(file, "%f", &weight);
        // 계산
        bmi = evalBmi(height, weight);
        // 결과 출력
        printf("%d번째 사람의 신장(cm)과 체중(kg): %d %d\n", i + 1, (int) height, (int) weight);
        // 비만 검사
        if (bmi >= 25)
            count++;
    }
    fclose(file);
    //---------------------------------------
    printf("비만인 사람은 %d명입니다.\n", count);
    return 0;
}

float evalBmi(int h, int w) {
    return (float) w / pow(((float) h * 0.01), 2);
}