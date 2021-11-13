#include <stdio.h>
#include <string.h>

#define size 3

struct st_person {
    char name[20];
    char address[80];
    int age;
};

int main(void) {
    struct st_person list[size];
    char str[3][20] = {"첫", "두", "세"}; // 코드 가독성을 위한 문자열
    FILE *file; // 파일 변수

    // 파일 열기
    file = fopen("data.txt", "w");

    
    // 데이터 입력
    for (int i = 0; i < size; i++) {
        printf("%s 번째 사람 인적사항을 입력하시오.\n", str[i]);

        printf("이름은? ");
        fgets(list[i].name, 100, stdin);
        list[i].name[strlen(list[i].name) - 1] = '\0';
        printf("주소는? ");
        fgets(list[i].address, 100, stdin);
        list[i].address[strlen(list[i].address)] = '\0';

        char age[5];
        printf("나이는? ");
        fgets(age, 4, stdin);
        list[i].age = (age[0] - '0') * 10 + age[1] - '0';
        list[i].address[strlen(list[i].address) - 1] = '\0';
        fprintf(file, "%s %s %d\n", list[i].name, list[i].address, list[i].age);
    }

    // 파일 닫기
    fclose(file);
    
    // 결고 출력 
    for (int i = 0; i < 3; i++)
        printf("%s 번째 사람 : %s/ %s/ %d\n",
               str[i], list[i].name, list[i].address, list[i].age);
    
    return 0;
}