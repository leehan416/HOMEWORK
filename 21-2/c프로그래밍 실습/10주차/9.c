#include <stdio.h>
#include <string.h>

int main(void) {
    int countUp = 0; //대문자 수 
    int countLow = 0; //소문자 수
    int countSpace = 0; //빈칸 수

    char str[100];
    FILE *file;
    
    // 파일 열기
    file = fopen("data.txt", "r");

    //파일 읽기
    while (!feof(file)) {
        fgets(str, sizeof(str), file);
        for (int i = 0; i < strlen(str); i++) {
            if ('A' <= str[i] && str[i] <= 'Z') // 대문자
                countUp++;
            else if ('a' <= str[i] && str[i] <= 'z') // 소문자
                countLow++;
            else if (str[i] == ' ') // 공백
                countSpace++;
        }
    }
    
    // 파일 닫기
    fclose(file);
    
    printf(">> 대문자 : %d개, 소문자 : %d개, 공백 : %d개", countUp, countLow, countSpace);
    
    return 0;
}