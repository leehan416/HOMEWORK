#include <stdio.h>
#include <stdlib.h>

struct st_bmi {
    int height, weight; // 키(cm), 몸무게(kg)
    float bmi; // 비만도
    // int bmi_index; // 1,2,3,4
};

float evalbmi(int h, int w);

int main(void) {
    int count = 0; // 비만인 사람
    FILE *file;    // 파일 변수
    file = fopen("data.txt", "r"); // 파일 열기

    // 구조체 선언
    struct st_bmi person[5];


    for (int i = 0; i < 5; i++) {
        // 파일에서 데이터 읽어오기
        fscanf(file, "%d", &person[i].height);
        fscanf(file, "%d", &person[i].weight);

        // 결과 출력
        printf("%d번째 사람의 신장(cm)과 체중(kg) : %d %d\n", i + 1, person[i].height, person[i].weight);

        // bmi 연산
        person[i].bmi = evalbmi(person[i].height, person[i].weight);

        // 비만이라면 변수 증가
        if (person[i].bmi >= 25)
            count++;

    }
    // 파일 닫기
    fclose(file);

    // 결과 출력
    printf("비만인 사람은 %d명입니다.", count);
    return 0;
}


float evalbmi(int h, int w) {
    float value = ((float) h * 0.01) * ((float) h * 0.01);
    return (float) w / value;
}