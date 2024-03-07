#include <stdio.h>

void maxMinOfTen(int number[10], int *max, int *min);

int main(void) {
    int num[10];    // 10개의 숫자를 받을 배열
    int max_num;    // 가장 큰 숫자를 리턴 받을 변수,
    int min_num;    // 가장 작은 숫자를 리턴 받을 변수
    char file[20];  // 파일 이름
    FILE *data;
    // 이 곳에 코드를 작성하라.
    //--------------------------------------------
    // 파일 이름 입력
    printf("파일 이름을 입력하세요. ");
    scanf("%s.txt", file);
    // 파일 이름 지정
    data = fopen(file, "r");
    for (int i = 0; i < 10; i++) // 데이터 읽기
        fscanf(data, "%d", &num[i]);

    maxMinOfTen(num, &max_num, &min_num);
    //--------------------------------------------
    printf("가장 큰 수는 %d이고, 가장 작은 수는 %d입니다.\n", max_num, min_num);
    fclose(data);
    return 0;
}

void maxMinOfTen(int number[10], int *max, int *min) {
    *max = -9999;
    *min = 9999;
    for (int i = 0; i < 10; i++) {
        // 최대 최소 검사
        if (number[i] > *max)
            *max = number[i];
        if (number[i] < *min)
            *min = number[i];
    }
}