#include <stdio.h>

int main() {
    int year, month, day;
    int days = 0; // 요일
    // 1900 1 1 = mon


    scanf("%d %d %d", &year, &month, &day); // 일자 입력

    // year
    for (int i = 1900; i < year; i++) {
        if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0)) // 윤년
            days += 2;
        else // 평년
            days += 1;
    }

    // month
    for (int i = 1; i < month; i++) {
        if (i == 2) { // 2월
            if ((year % 4 == 0 && (year % 100 != 0)) || (year % 400 == 0)) // 윤년
                days += 29;
            else // 평년
                days += 28;
        } else { // 나머지 월
            if (((i % 2 == 1) && (i <= 7)) || ((i % 2 == 0) && (8 <= i)))
                days += 31;
            else if (((i % 2 == 0) && (i <= 6)) || ((i % 2 == 1) && (9 <= i)))
                days += 30;
        }
    }

    //day
    days += day;

    days %= 7;

    // 결과 출력
    switch (days) {
        case 0: { // 일
            printf("Sunday");
            break;
        }
        case 1: { // 월
            printf("Monday");
            break;
        }
        case 2: { // 화
            printf("Tuesday");
            break;
        }
        case 3: { // 수
            printf("Wednesday");
            break;
        }
        case 4: { // 목
            printf("Thursday");
            break;
        }
        case 5: { // 금
            printf("Friday");
            break;
        }
        case 6: { // 토
            printf("Saturday");
            break;
        }
    }

    return 0;
}
