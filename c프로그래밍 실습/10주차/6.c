#include <stdio.h>

#define num 10

int main(void) {
    char userid[num][20];
    char userpw[num][20];

    FILE *file;
    //파일 열기
    file = fopen("user.txt", "w");

    // 데이터 쓰기
    for (int i = 0; i < num; i++) {
        printf("%d번째 사람 ID Password? ", i + 1);
        scanf("%s %s", userid[i], userpw[i]);
        fprintf(file, "%s %s\n", userid[i], userpw[i]);
    }
    // 파일 닫기
    fclose(file);

    // 결과 출력
    printf("\n등록된 사용자 목록\nNo ID Password\n");
    file = fopen("user.txt", "r");
    for (int i = 0; i < num; i++) {
        fscanf(file, "%s %s", userid[i], userpw[i]);
        printf("%d %s %s\n", i + 1, userid[i], userpw[i]);
    }

    printf("\nuser.txt에 저장함");
    return 0;
}