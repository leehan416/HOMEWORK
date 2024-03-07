#include <stdio.h>

int age(int year);

int ageToGroup(int b);

int main(void) {
    int birth_year = 0;   // 입력받은 태어난 년도
    int year[100];        // 각 사람들의 생년 (최대 100명)  
    int count_person = 0; // 입력된 인원 수
    int count[6] = {0,};  // 6가지 연령대별 숫자

    char text[6][100] = {"유아", "어린이", "청소년", "청년", "중년", "노년"}; // 출력을 위한 변수

    while (1) {
        printf("%d번째 사람의 태어난 년도를 입력하시오. ", count_person + 1);
        scanf("%d", &birth_year);

        if (birth_year < 2020) { // 나가는 조건 검사
            year[count_person++] = birth_year; // 배열에 데이터 넣기
            ++count[ageToGroup(birth_year)]; // count 증가
        } else {
            break; // 그만
        }

    }

    // 출력
    for (int i = 0; i < count_person; i++)
        printf("%d번째 사람의 나이는 %d입니다.\n", i + 1, age(year[i]));

    for (int i = 0; i < 6; i++)
        printf("%s%s %d%s입니다.\n", text[i], (i <= 1) ? "는" : "은", count[i], (i == 0) ? "명" : "명 ");
}


int ageToGroup(int b) {
    b = age(b);

    if (b < 7)
        return 0;
    else if (7 <= b && b < 13)
        return 1;
    else if (13 <= b && b < 20)
        return 2;
    else if (20 <= b && b < 30)
        return 3;
    else if (30 <= b && b < 60)
        return 4;
    else if (60 <= b)
        return 5;
    else
        return -1; //error
}

int age(int year) { // 나이계산 함수
    return 2021 - year + 1;
}