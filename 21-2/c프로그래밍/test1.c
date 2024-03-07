//1번
//22100594 이한결
#include <stdio.h>

int main() {
    int hour1;
    int hour2;

    int min1;
    int min2;

    int sum = 0;

    printf("첫번째 시간 ");
    scanf("%d %d", &hour1, &min1);
    printf("두번째 시간 ");
    scanf("%d %d", &hour2, &min2);


    if (hour1 > hour2) { // 1 >2
        if (min1 > min2) {
            sum += min1 - min2;
            sum += (hour1 - hour2) * 60;
        } else {
            sum += min1 + min2;
            sum += (hour1 - hour2) * 60;
        }

    } else { // 2 > 1
        if (min2 > min1) {
            sum += min2 - min1;
            sum += (hour2 - hour1) * 60;
        } else {
            sum += min1 + min2;
            sum += (hour2 - hour1) * 60;
        }
    }
    printf("%d", sum);
    return 0;
}