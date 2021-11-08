#include <stdio.h>

# define size 20

int findMax(int arr[size]);

float getAvgClass(int arr[size], int value);

int main(void) {
    char pname[3][10] = {"C", "Java", "Python"};
    char name[size][30] = {0}; // 이름 (최대 20명)
    int score[3][size] = {0}; // 3과목 점수 (최대 20명)
    int sum[size] = {0,}; // 총점 (최대 20명)
    float avg[size]; // 평균 (최대 20명)

    int index = 0;
    FILE *file;

    // 입력
    file = fopen("data.txt", "r");
    for (int i = 0; !feof(file); i++) {
        fscanf(file, "%s", name[index]);
        if (name[i][0] == 0) // 빈 줄 넘어감
            break;
        
        for (int j = 0; j < 3; j++) {
            fscanf(file, "%d", &score[j][i]);
            sum[i] += score[j][i];
        }
        if (name[i][0] != '\n')
            index++;
    }
    // 파일 닫기
    fclose(file);
    
    // 결과 출력
    printf("%d records read.\n", index);

    // 출력
    for (int i = 0; i < index; i++) {
        avg[i] = sum[i] / 3.0;
        printf("%-7s %d  %d  %d  %d  %.1f\n", name[i], score[0][i], score[1][i], score[2][i], sum[i], avg[i]);
    }

    for (int i = 0; i < 3; i++) {
        int value = findMax(score[i]);
        printf("%s - average : %.1f, Top : %s (%d)\n", pname[i], getAvgClass(score[i], index), name[value],
               score[i][value]);
    }
    return 0;
}

int findMax(int arr[size]) {
    int value = -99;
    int index;
    for (int i = 0; i < size; i++) {
        if (value < arr[i]) {
            value = arr[i];
            index = i;
        }
    }
    return index;
}

float getAvgClass(int arr[size], int value) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return (float) sum / value;
}