#include<stdio.h>
#include <string.h>

int main(void){
    char firstname[30];
    char lastname[30];
    char age_group[4][30] = {
        "[Youth]",
        "[Junior]",
        "[Senior]",
        "[Silver]"
    }; 
    int birthyear;
    int age;
    char output[256] = {'\0',};

    // 변수 입력
    printf("Firstname? ");
    scanf("%s", firstname);
    printf("Lastname? ");
    scanf("%s", lastname);
    printf("Birthyear? ");
    scanf("%d", &birthyear);

    // 나이 연산
    age = 2021 - birthyear +1;
    
    // 연령대 지정 => 문자열 붙이기
    if (age < 20)
        strcat(output, age_group[0]);
    else if (20<=age && age < 40)
        strcat(output, age_group[1]); 
    else if (40<=age && age < 65)
        strcat(output, age_group[2]);
    else 
        strcat(output, age_group[3]);

    // 공백 붙이기
    strcat(output, " ");

    // 문자열 붙이기
    strcat(output, firstname);
    strcat(output, " ");
    strcat(output, lastname);
    
    // 결과 출력
    printf("결과 : %s", output);

    return 0;
}