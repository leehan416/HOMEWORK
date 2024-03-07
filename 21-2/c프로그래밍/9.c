#include <stdio.h>

int main() {
    int firstDay; // 첫번째 요일 
    int days; // 그 달의 마지막 날 출력


    printf("1일의 요일 : ( 0: Sun,  1:Mon, 2:Tue, 3:Wed, 4:Thu, 5:Fri, 6:Sat) : "); // 요일 출력
    scanf("%d", &firstDay); // 요일 입력

    printf("Number of days : "); 
    scanf("%d", &days);

    printf("Sun    Mon    Tue    Wed    Thu   Fri    Sat\n");

    for (int i = 0; i < firstDay; i++) // 요일 이전 날 까지
        printf("       "); // 공백 출력

    for (int i = 1; i <= days; i++) { // 날짜 출력
        printf("%3d    ", i);
        firstDay++;
        if (firstDay > 6) { // 토요일을 넘어가면
            firstDay = 0; // 일요일으로
            printf("\n"); // 줄바꿈
        }
    }
}