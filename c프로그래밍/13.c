#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// DataBase Structure
struct DataBase {
    char name[20];
    char stuid[20];
    int grade;
    int mid;
    int final;
};

// processor functions
void addData(struct DataBase *data[], int length);

void delData(struct DataBase *data[], int index, int length);

int searchData(struct DataBase *data[], char string[]);

void print(struct DataBase *data[], int index);

void sortList(struct DataBase *data[], int length);

float avgTest(struct DataBase *data[], int length, int value);

// Input functions
void adding(struct DataBase *data[], int *length);

void removing(struct DataBase *data[], int *length);

void showAll(struct DataBase *data[], int *length);

void searching(struct DataBase *data[]);

int main() {
    struct DataBase *data[100] = {NULL,}; // Data
    int input; // 입력 값
    int *length = (int *) malloc(sizeof(int)); // 데이터 길이
    *length = 0;

    while (1) {
        printf("--------------------------\n");
        printf("원하는 명령을 선택하시오.\n1. 데이터 추가\n2. 데이터 삭제\n3. 전체 현황 보기\n4. 데이터 조회\n5. 종료\n명령 선택 : ");

        scanf("%d", &input);

        if (input == 1) adding(data, length);
        else if (input == 2) removing(data, length);
        else if (input == 3) showAll(data, length);
        else if (input == 4) searching(data);
        else if (input == 5) break;
        else printf("\n다시 입력하세요.\n\n");
    }
    // 데이터 free
    for (int i = 0; i < 100; i++)
        free(data[i]);
    free(length);
    return 0;
}

// 1
void adding(struct DataBase *data[], int *length) {
    if (*length >= 100) {
        printf("\n더 이상 추가 할 수 없습니다.\n\n");
    } else {
        addData(data, *length);
        *length += 1;
        if (searchData(data, data[*length - 1]->stuid) != *length - 1) {
            printf("\n이미 존재하는 학번 입니다.\n\n");
            delData(data, *length, *length);
            *length -= 1;
        } else {
            printf("\n데이터 추가 완료.\n\n");
        }
    }
}

// 2
void removing(struct DataBase *data[], int *length) {
    char string[100];
    printf("학번 입력 : ");
    scanf("%s", string);
    int value = searchData(data, string);
    if (value != -1) {
        delData(data, value, *length);
        *length -= 1;
        printf("\n데이터 삭제 완료.\n\n");
    } else {
        printf("\n해당 데이터가 존재하지 않습니다.\n\n");
    }
}

// 3
void showAll(struct DataBase *data[], int *length) {
    sortList(data, *length);
    if (*length == 0) {
        printf("\n현재 데이터 없음\n\n");
    } else {
        printf("\n성명 / 학번 / 학년 / 중간고사 / 기말고사\n");
        for (int i = 0; i < *length; i++)
            print(data, i);
    }
    printf("\n총 인원 %d 명 중간고사 평균 : %.1f 기말고사 평균 : %.1f\n\n", *length, avgTest(data, *length, 1),
           avgTest(data, *length, 0));
}

// 4
void searching(struct DataBase *data[]) {
    char string[10];
    printf("학번 입력 : ");
    scanf("%s", string);
    int value = searchData(data, string);
    if (value == -1) {
        printf("\n해당 데이터가 존재하지 않습니다.\n\n");
    } else {
        printf("성명 / 학번 / 학년 / 중간고사 / 기말고사\n");
        print(data, value);
    }
}

// 평균 계산
float avgTest(struct DataBase *data[], int length, int value) {
    float sum = 0;

    if (value) { // 중간고사
        for (int i = 0; i < length; i++)
            sum += (float) data[i]->mid;
    } else { // 기말고사
        for (int i = 0; i < length; i++)
            sum += (float) data[i]->final;
    }
    return sum / (float) length;
}

// 데이터 추가
void addData(struct DataBase *data[], int length) {
    data[length] = (struct DataBase *) malloc(sizeof(struct DataBase));
    printf("\n데이터 추가\n성명 학번 학년 중간고사 기말고사\n입력 : ");
    scanf("%s %s %d %d %d", data[length]->name, data[length]->stuid, &data[length]->grade, &data[length]->mid,
          &data[length]->final);
}

// 데이터 삭제
void delData(struct DataBase *data[], int index, int length) {
    free(data[index]);
    for (int i = index; i < length; i++)
        data[i] = data[i + 1];
}

// 데이터 찾기
int searchData(struct DataBase *data[], char string[]) {
    for (int index = 0; index < 100 && data[index] != NULL; index++)
        if (strcmp(data[index]->stuid, string) == 0)
            return index;
    // 데이터 없음
    return -1;
}

// 데이터 출력
void print(struct DataBase *data[], int index) {
    printf("%s / %s / %d / %d / %d\n", data[index]->name, data[index]->stuid, data[index]->grade, data[index]->mid,
           data[index]->final);
}

// 학번 기준 정렬
void sortList(struct DataBase *data[], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - (i + 1); j++) {
            int k;
            // 같은 char 이라면 다음 글자 비교
            for (k = 0; data[j]->stuid[k] == data[j + 1]->stuid[k]; k++);
            if (data[j]->stuid[k] > data[j + 1]->stuid[k]) {
                struct DataBase *temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}