#include <stdio.h>

int main() {
    int year, month, firstDay = 1; // 년도, 달, 처음 요일
    int day; // 일
    scanf("%d %d", &year, &month); // 입력
    // 1900 1 1 = mon
    
    
    
    //--------------------------------------------------------------------------
    // 시작 요일 탐색
    
    // year
    if (year < 1900) {
        for (int i = 1900; i > year; i--) {
            if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0)) // 윤년
                firstDay += 5;
            else // 평년
                firstDay += 6;
        }
    } else {
        for (int i = 1900; i < year; i++) {
            if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0)) // 윤년
                firstDay += 2;
            else // 평년
                firstDay += 1;
        }
    }
    
    // month
    for (int i = 1; i < month; i++) {
        if (i == 2) { // 2월
            if ((year % 4 == 0 && (year % 100 != 0)) || (year % 400 == 0)) // 윤년
                firstDay += 7;
            else // 평년
                firstDay += 6;
        } else { // 나머지 월
            if (((i % 2 == 1) && (i <= 7)) || ((i % 2 == 0) && (8 <= i)))
                firstDay += 3;
            else if (((i % 2 == 0) && (i <= 6)) || ((i % 2 == 1) && (9 <= i)))
                firstDay += 2;
        }
    }

    firstDay %= 7; // 요일 지정

    //--------------------------------------------------------------------------
    // 끝 날자 탐색
    if (month == 2) { // 2월
        if ((year % 4 == 0 && (year % 100 != 0)) || (year % 400 == 0)) // 윤년
            day = 29;
        else // 평년
            day = 28;
    } else { // 나머지 월
        if (((month % 2 == 1) && (month <= 7)) || ((month % 2 == 0) && (8 <= month)))
            day = 31;
        else if (((month % 2 == 0) && (month <= 6)) || ((month % 2 == 1) && (9 <= month)))
            day = 30;
    }

    //--------------------------------------------------------------------------
    // 달력 출력
    printf("Sun    Mon    Tue    Wed    Thu   Fri    Sat\n");

    for (int i = 0; i < firstDay; i++) // 시작 요일 이전까지
        printf("       "); // 공백 출력


    for (int i = 1; i <= day; i++) { // 날짜 출력
        printf("%3d    ", i);
        firstDay++;
        if (firstDay > 6) { // 날짜가 토요일을 넘어가면
            firstDay = 0; // 일요일로 지정
            printf("\n"); // 줄바꿈
        }
    }

    return 0;
}
