#include <stdio.h>
#include <string.h>

#define size 10

struct st_user {
    char userid[20];
    char userpw[20];
};

int main(void) {
    struct st_user user[size];
    char userInput[2][10]; // 입력 변수
    FILE *file; // 파일 변수
    file = fopen("user.txt", "w"); // 파일 열기

    for (int i = 0; i < size; i++) {
        printf("%d번째 사람 ID Password? ", i + 1);
        scanf("%s %s", userInput[0], userInput[1]);
        strcpy(user[i].userid, userInput[0]);
        strcpy(user[i].userpw, userInput[1]);
        fprintf(file, "%s %s\n", userInput[0], userInput[1]);
    }

    // 파일 닫기
    fclose(file);

    // 파일 열기
    file = fopen("user.txt", "r");


    // 결과 출력
    printf("등록된 사용자 목록");
    printf("\nNo ID Password\n");
    for (int i = 0; i < size; i++) {
        char str[2][10];
        fscanf(file, "%s %s", str[0], str[1]);
        printf("%d %s %s\n", i + 1, str[0], str[1]);

    }
    fclose(file);
    printf("user.txt에 저장함");

    return 0;
}