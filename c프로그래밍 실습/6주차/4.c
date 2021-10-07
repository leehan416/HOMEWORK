#include <stdio.h>
#include <string.h>

int main(void) {

    // data set
    char username[5][20]={
        "kim", 
        "lee", 
        "park", 
        "hong", 
        "choi"
    }; 
    char password[5][20]={
        "1111", 
        "1234", 
        "3456", 
        "3535", 
        "7777"
    };
    // user input 
    char input[2][20];
    // index 저장 변수
    int index = -1;

    printf("아이디를 입력하시오. ");
    scanf("%s", input[0]);
    printf("비밀번호를 입력하시오. ");
    scanf("%s", input[1]);


    // 아이디 찾기
    for (int i = 0 ; i < 5 ; i++) {
        if (strcmp(username[i], input[0]) == 0) {
            index = i;
            break;
        }
    }
    // 결과 출력
    if (index == -1) { // 변경 없을 시
        printf("그런 아이디가 없음");
    } else { 
        if (strcmp(password[index], input[1]) == 0) {
            // 아이디 비밀번호 일치
            printf("로그인 성공");
        } else {
            // 비밀번호 일치하지 않음
            printf("아이디는 맞는데 비번이 틀림");
        }
    }
    
    return 0;
}