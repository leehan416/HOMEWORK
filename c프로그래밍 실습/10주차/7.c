#include <stdio.h>

int main(void) {
    char userid[10][20];
    char userpw[10][20];
    FILE *file;
    // 파일 열기 
    file = fopen("user.txt", "r");
    
    printf("등록된 사용자 목록\nNo ID   Password\n");
    
    // 데이터 읽기
    for (int i = 0; i < 10; i++) {
        fscanf(file, "%s %s", userid[i], userpw[i]);
        printf("%-2d %s %s\n", i + 1, userid[i], userpw[i]);
    }
    return 0;
}