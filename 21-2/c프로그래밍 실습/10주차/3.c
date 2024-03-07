#include <stdio.h>

void evalClass(int j[5][3], int i, int *s, float *a);

// 과목번호, 총점, 평균
// - 총점과 평균을 계산
void evalStudent(int j[5][3], int i, int *s, float *a, char *g);
// 학생번호, 총점, 평균, 등급
// - 총점과 평균, 등급을 계산

int main(void) {
    int jumsu[5][3]; // 5명의 3과목 점수를 저장하고 있는 2차원 배열 
    char classname[3][20] = {"국어", "영어", "수학"};
    int sum = 0;//총점저장용
    float avg;// 평균저장용
    char grade;// 등급저장용
    int i, j;// 반복문을 위한 변수
    FILE *data;
    // 이곳에 코드를 작성하라. 

    //------------------------
    data = fopen("data.txt", "r");
    // 데이터 읽기
    for (i = 0; i < 5; i++)
        for (j = 0; j < 3; j++)
            fscanf(data, "%d", &jumsu[i][j]);
    fclose(data);
    //------------------------
    for (i = 0; i < 5; i++) {
        printf("%d번 학생 : ", i + 1);
        for (j = 0; j < 3; j++) {
            printf("%s %d", classname[j], jumsu[i][j]);
            if (j < 2) printf(", ");
            else printf("\n");
        }
    }
    printf("1) 각 과목별 총점과 평균점수\n");
    for (i = 0; i < 3; i++) {
        evalClass(jumsu, i, &sum, &avg);
        printf("%s 점수의 총점은 %d 평균은 %.1f\n", classname[i], sum, avg);
    }
    printf("2) 각 학생별 총점과 평균점수, 평균에 따른 등급\n");
    for (i = 0; i < 5; i++) {
        evalStudent(jumsu, i, &sum, &avg, &grade);
        printf("%d번 학생의 총점은 %d 평균은 %.1f(등급 %c)\n", i + 1, sum, avg, grade);
    }
    fclose(data);
    return 0;
}


void evalClass(int j[5][3], int i, int *s, float *a) {
    // 합 초기화
    *s = 0;
    // 데이터 연산
    for (int index = 0; index < 5; index++)
        *s += j[index][i];
    // 평균 계산
    *a = *s / 5.0;
}

void evalStudent(int j[5][3], int i, int *s, float *a, char *g) {
    // 합 초기화
    *s = 0;
    // 데이터 연산
    for (int index = 0; index < 3; index++)
        *s += j[i][index];
    // 평균 계산
    *a = *s / 3.0;
    // 점수 적용
    if (90 <= *a)
        *g = 'A';
    else if (80 <= *a && *a < 90)
        *g = 'B';
    else if (70 <= *a && *a < 80)
        *g = 'C';
    else if (60 <= *a && *a < 70)
        *g = 'D';
    else
        *g = 'F';
}