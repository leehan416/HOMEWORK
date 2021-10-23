#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int jumsu[5][3];            // 5명의 3과목 점수를 저장하고 있는 2차원 배열 
    char classname[3][20] = {"국어", "영어", "수학"};
    int sum_student[5] = {0,};         // 학생별 총점
    float average_student[5];   // 학생별 평균
    char grade[5];              // 학생별 등급 
    int sum_class[3] = {0,};           // 과목별 총점
    float average_class[3];     // 과목별 평균

    srand(time(NULL)); // 랜덤 시드 변경

    // 점수 생성
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            jumsu[i][j] = rand() % 50 + 50;
            sum_student[i] += jumsu[i][j];
            sum_class[j] += jumsu[i][j];
        }
    }
    // 평균 계산
    for (int i = 0; i < 5; i++)
        average_student[i] = (float) sum_student[i] / 3;
    for (int i = 0; i < 3; i++)
        average_class[i] = (float) sum_class[i] / 5;

    //점수 매기기
    for (int i = 0; i < 5; i++) {
        if (90 <= average_student[i]) {
            grade[i] = 'A';
        } else if (80 <= average_student[i] && average_student[i] < 90) {
            grade[i] = 'B';
        } else if (70 <= average_student[i] && average_student[i] < 80) {
            grade[i] = 'C';
        } else if (60 <= average_student[i] && average_student[i] < 70) {
            grade[i] = 'D';
        } else {
            grade[i] = 'F';
        }
    }
    //--------------------------------------------------------------------
    // 결과 출력
    printf("5명의 학생 점수가 생성되었습니다.\n");
    for (int i = 0; i < 5; i++) {
        printf("%d번 학생 : ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%s %d", classname[j], jumsu[i][j]);
            if (j != 2)
                printf(", ");
        }
        printf("\n");
    }
    printf("1) 각 과목별 총점과 평균점수\n");
    for (int i = 0; i < 3; i++)
        printf("%s 점수의 총점은 %d 평균은 %.1f\n", classname[i], sum_class[i], average_class[i]);
    printf("2) 각 학생별 총점과 평균점수, 평균에 따른 등급\n");
    for (int i = 0; i < 5; i++) {
        printf("%d번 학생의 총점은 %d 평균은 %.1f(등급 %c)\n", i + 1, sum_student[i], average_student[i], grade[i]);
    }


    return 0;
}