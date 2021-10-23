#include <stdio.h>
#include <math.h>

int askBiman(int height, int weight);

int main(void) {
    int height, weight;
    char text[5][100] = {"저체중", "정상", "과체중", "경도비만", "고도비만"}; // 출력용 변수 

    for (int i = 0; i < 10; i++) {
        // 변수 입력
        printf("%d번째 사람 신장과 체중? ", i + 1);
        scanf("%d %d", &height, &weight);

        //잘못 입력한 경우
        if ((height <= 0) || (weight <= 0))
            printf("잘못 입력하셨습니다.\n");
        else
            printf("%s\n", text[askBiman(height, weight)]); // 결과 출력
    }


    return 0;
}

int askBiman(int height, int weight) {
    float h = (float) height * 0.01; // 단위 변화
    float value = (float) weight / pow(h, 2); // 연산
    if (value < 18.5)
        return 0;
    else if (18.5 <= value && value < 23)
        return 1;
    else if (23 <= value && value < 25)
        return 2;
    else if (25 <= value && value < 30)
        return 3;
    else
        return 4;
}