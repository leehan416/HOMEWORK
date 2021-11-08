#include <stdio.h>

float findMax(float num[], int size);

float findMin(float num[], int size);

int main(void) {
    float arr[10];
    float sum = 0;
    float ave;
    FILE *file;
    // 파일 읽기
    file = fopen("data.txt", "r");
    for (int i = 0; i < 10; i++) {
        fscanf(file, "%f", &arr[i]);
        // 점수 출력
        printf("%d번 심사점수 : %.1f\n", i + 1, arr[i]);
        sum += arr[i];
    }
    //파일 닫기
    fclose(file);
    // 연산
    ave = (sum - (findMax(arr, 10) + findMin(arr, 10))) / 8.0;
    
    // 결과 출력
    printf("가장 큰 점수와 가장 작은 점수를 제외한 8개의 점수에 대한 평균은 %.1f 입니다. ", ave);

    return 0;
}

float findMax(float num[], int size) {
    float value = -999;
    for (int i = 0; i < size; i++)
        if (num[i] > value)
            value = num[i];
    return value;
}

float findMin(float num[], int size) {
    float value = 999;
    for (int i = 0; i < size; i++)
        if (num[i] < value)
            value = num[i];
    return value;
}