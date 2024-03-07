#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int classSum(int s[5][3], int classnum); // 과목 총점
// 파라미터 : 점수배열(s)과 과목번호(0,1,2) 
// 리턴값 : 해당 과목의 총점
int studentSum(int s[5][3], int classnum); // 학생 총점
// 파라미터 : 점수배열(s)과 학생번호(0,1,2,3,4) 
// 리턴값 : 해당 학생의 총점
char studentGrade(int s[5][3], int classnum); // 학생 등급
// 파라미터 : 점수배열(s)과 학생번호(0,1,2,3,4) 
// 리턴값 : 해당 학생의 등급 ('A','B','C','D','F')

int main(void) {

    int jumsu[5][3];            // 5명의 3과목 점수를 저장하고 있는 2차원 배열 
    char classname[3][20] = {"국어", "영어", "수학"};
    // int sum_student[5];         // 학생별 총점
    float average_student[5];   // 학생별 평균
    // char grade[5];              // 학생별 등급 
    // int sum_class[3];           // 과목별 총점
    float average_class[3];     // 과목별 평균
    int i, j;                   // 반복문을 위한 변수 

    srand(time(NULL));

    // 점수 생성
    for (i = 0; i < 5; i++)
        for (j = 0; j < 3; j++)
            jumsu[i][j] = rand() % 50 + 50;

    // 평균 계산
    for (i = 0; i < 5; i++)
        average_student[i] = (float) studentSum(jumsu, i) / 3.0;
    for (i = 0; i < 3; i++)
        average_class[i] = (float) classSum(jumsu, i) / 5.0;
    
    // 출력
    for (i = 0; i < 5; i++) {
        printf("%d번 학생 : ", i + 1);
        for (j = 0; j < 3; j++) {
            printf("%s %d", classname[j], jumsu[i][j]);
            if (j < 2) {
                printf(", ");
            }
        }
        printf("\n");
    }
    printf("1) 각 과목별 총점과 평균점수\n");
    for (i = 0; i < 3; i++)
        printf("%s 점수의 총점은 %d 평균은 %.1f\n", classname[i], classSum(jumsu, i), average_class[i]);
    printf("2) 각 학생별 총점과 평균점수, 평균에 따른 등급\n");
    for (i = 0; i < 5; i++)
        printf("%d번 학생의 총점은 %d 평균은 %.1f (등급 %c)\n", i + 1, studentSum(jumsu, i), average_student[i],
               studentGrade(jumsu, i));
    
    return 0;
}

int classSum(int s[5][3], int classnum) {
    int sum = 0;
    for (int i = 0; i < 5; i++)
        sum += s[i][classnum];
    return sum;
}

int studentSum(int s[5][3], int classnum) {
    int sum = 0;
    for (int i = 0; i < 3; i++)
        sum += s[classnum][i];
    return sum;
}

char studentGrade(int s[5][3], int classnum) {
    float value = (float) studentSum(s, classnum) / 3.0; // 평균 연산

    if (90 <= value)
        return 'A';
    else if (80 <= value && value < 90)
        return 'B';
    else if (70 <= value && value < 80)
        return 'C';
    else if (60 <= value && value < 70)
        return 'D';
    else
        return 'F';
}   