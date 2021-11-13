#include <stdio.h>

#define size 8

struct st_score {
    char name[10]; // 이름
    int jumsu[3];  // 점수 (C, Java, Python)
    int sum;  // 총점
    float avg;  //  평균
};

float getClassAvg(struct st_score list[], int value);

int findTop(struct st_score list[], int value);

int main(void) {
    struct st_score person[8];
    int i;
    char cname[3][10] = {"C", "Java", "Python"};
    FILE *file;
    file = fopen("data.txt", "r");

    // 데이터 읽기
    for (i = 0; i < size; i++) {
        fscanf(file, "%s", person[i].name);
        for (int j = 0; j < 3; j++)
            fscanf(file, "%d", &person[i].jumsu[j]);
    }

    // 파일 닫기
    fclose(file);

    // 결과 출력
    printf("%d records read.\n", i);
    for (int i = 0; i < size; i++) {
        person[i].sum = 0;
        for (int j = 0; j < 3; j++)
            person[i].sum += person[i].jumsu[j];

        person[i].avg = (float) person[i].sum / 3.0;
        printf("%-7s %d  %d  %d  %d  %.1f\n", person[i].name, person[i].jumsu[0], person[i].jumsu[1],
               person[i].jumsu[2], person[i].sum, person[i].avg);
    }

    for (int i = 0; i < 3; i++) {
        int index = findTop(person, i);
        printf("%s - average : %.1f, Top : %s (%d)\n", cname[i], getClassAvg(person, i), person[index].name,
               person[index].jumsu[i]);
    }
    return 0;
}


float getClassAvg(struct st_score list[], int value) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += list[i].jumsu[value];
    return (float) sum / (float) size;
}

int findTop(struct st_score list[], int value) {
    int max = -99;
    int index;
    for (int i = 0; i < size; i++) {
        if (max < list[i].jumsu[value]) {
            index = i;
            max = list[i].jumsu[value];
        }
    }
    return index;
}