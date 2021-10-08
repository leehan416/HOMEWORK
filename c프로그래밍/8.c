/*

Programming Assignment 08 2021-09-14 00:00 ~ 2021-10-07 23:50
Date
Writer hjkim(김호준)
Read0
구구단 출력 program
입출력 예)
Select a column of multiplication table : 7

7 * 1 =  7
7 * 2 = 14
7 * 3 = 21
7 * 4 = 28
7 * 5 = 35
7 * 6 = 42
7 * 7 = 49
7 * 8 = 56
7 * 9 = 63
*/

#include <stdio.h>
int main() {
    int num; // 입력 받을 변수
    printf("Select a column of multiplication table : ");
    scanf("%d", &num); // 입력
    for (int i = 1; i < 10; i++) { // 반복
        printf("%d x %d = %d\n", num, i, i * num); // 구구단 출력
    }
    return 0; // 함수 종료
}