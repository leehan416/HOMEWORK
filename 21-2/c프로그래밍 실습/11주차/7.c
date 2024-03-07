#include <stdio.h>

int main(void) {
    FILE *file; // 파일 변수
    file = fopen("user.txt", "r"); // 파일 열기

    // 결과 출력
    printf("등록된 사용자 목록");
    printf("\nNo ID   Password\n");
    for (int i = 0; !feof(file); i++) {
        char str[2][10];
        fscanf(file, "%s %s", str[0], str[1]);
        printf("%-2d %-4s %s\n", i + 1, str[0], str[1]);

    }
    // 파일 닫기
    fclose(file);

    return 0;
}