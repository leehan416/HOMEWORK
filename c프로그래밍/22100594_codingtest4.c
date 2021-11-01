//4 
//22100594 이한결
#include <stdio.h>

int main() {
    int month;
    int day;
    int sum = 0;

    printf("임의의 월, 일 ");
    scanf("%d %d", &month, &day);
    for (int i = 1; i < month; i++) {
        if (i == 2)
            sum += 28;
        else if ((i < 8 && i % 2 == 1) || (i > 7 && i % 2 == 0))
            sum += 31;
        else
            sum += 30;
    }
    sum += day;
    printf("결과 값 %d", sum);
    return 0;
}
