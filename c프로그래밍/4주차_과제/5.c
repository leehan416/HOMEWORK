#include <stdio.h>

int main() {
    int year, month, day; // 년, 달, 월
    scanf("%d %d %d", &year, &month, &day); // 변수 입력
    if (month == 2 && day >= 28) { // 2월달 마지막 날이라면
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) { //윤년 확인
            day++; // 윤년은 29일까지 있음
        } else { // 윤년 아님
            month++; // 다음달
            day = 1;

        }
    } else if (month == 12 && day == 31) { // 새 해 검사
        // new year
        year++;
        month = 1;
        day = 1;
    } else { // 일반 날자
        // 30 ~31일때 달 검사 
        if (day > 29) { // 다음달 검사
            month++; // 다음달
            day = 1;
        } else
            day++; // 일반 날짜
    }
    printf("%d %d %d", year, month, day); // 출력

    return 0;
}