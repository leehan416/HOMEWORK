#include <stdio.h>
#include <string.h>

int main(void) {
    char userid[30];
    char password[30];
    char name[30];


    // 변수 입력
    printf("User Id? ");
    scanf("%s", userid);
    // 3글자 이상 입력할 때까지 반복
    while(1) {
        // 변수 입력
        printf("Password? ");
        scanf("%s", password);
        if (strlen(password) < 3) // 만약 3글자 미만으로 입력했다면
            printf("-> 3글자 이상 입력할 것\n"); 
        else // 아니라면
            break; // 반복문 나가기
    }
    // 변수 입력
    printf("User Name? ");
    scanf("%s", name);
    printf("\n");
    
    // 결과 출력
    printf("User Id: %s\n", userid);
    printf("Password: ");
    for (int i = 0 ; i < strlen(password) ; i++) { // 2번째 글자 이후엔 * 출력 
        if (i < 2)
            printf("%c", password[i]);
        else
            printf("*");
    }
    printf("\n");
    printf("User Name: %s", name);

    return 0;
}