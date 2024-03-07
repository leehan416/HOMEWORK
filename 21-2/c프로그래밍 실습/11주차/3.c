#include <stdio.h>

struct st_jumsu {
    int kor, eng, mat;
    int sum;
    float avg;
    char grade;
};

void sumClass(struct st_jumsu p[], int *sum, float *avg, int i);

void evalStudent(struct st_jumsu *p);

int main(void) {
    struct st_jumsu p[5]; // 구조체 선언
    int sum; // 총합
    float avg; // 평균
    FILE *data; // 파일 변수
    data = fopen("data.txt", "r"); // 파일 열기

    // 데이터 읽기
    for (int i = 0; i < 5; i++) {
        fscanf(data, "%d %d %d", &p[i].kor, &p[i].eng, &p[i].mat);
        evalStudent(p + i);
    }
    // 파일 닫기
    fclose(data);

    // 출력
    for (int i = 0; i < 5; i++) {
        printf("%d번 학생 : 국어 %d, 영어 %d, 수학 %d\n", i + 1, p[i].kor, p[i].eng, p[i].mat);
    }

    printf("1) 각 과목별 총점과 평균점수\n");
    sumClass(p, &sum, &avg, 0);
    printf("국어 점수의 총점은 %d 평균은 %.1f\n", sum, avg);
    sumClass(p, &sum, &avg, 1);
    printf("영어 점수의 총점은 %d 평균은 %.1f\n", sum, avg);
    sumClass(p, &sum, &avg, 2);
    printf("수학 점수의 총점은 %d 평균은 %.1f\n", sum, avg);
    printf("2) 각 학생별 총점과 평균점수, 평균에 따른 등급\n");

    for (int i = 0; i < 5; i++) {
        printf("%d번 학생의 총점은 %d 평균은 %.1f(등급 %c)\n", i + 1, p[i].sum, p[i].avg, p[i].grade);
    }
    return 0;
}


void sumClass(struct st_jumsu p[], int *sum, float *avg, int i) {
    *sum = 0;
    for (int j = 0; j < 5; j++) {
        switch (i) {
            case 0: {
                *sum += p[j].kor;
                break;
            }
            case 1: {
                *sum += p[j].eng;
                break;
            }
            case 2: {
                *sum += p[j].mat;
                break;
            }
        }
        *avg = (float) *sum / 5.0;
    }


}

void evalStudent(struct st_jumsu *p) {
    p->sum = p->kor + p->eng + p->mat;
    p->avg = (float) p->sum / 3.0;
    float value = p->avg;
    if (90 <= value)
        p->grade = 'A';
    else if (80 <= value && value < 90)
        p->grade = 'B';
    else if (70 <= value && value < 80)
        p->grade = 'C';
    else if (60 <= value && value < 70)
        p->grade = 'D';
    else
        p->grade = 'F';
}