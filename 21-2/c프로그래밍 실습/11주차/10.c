#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 10 - 10 에서 미리 대각선빙고를 구현하여 동일한 코드를 제출합니다.

int markBingo(int num, int b[25]);

void shuffleBingo(int b[25]);

void printBingo(int b[25]);

int checkBingo(int num, int b[]);

int shuffledBingo[25] = {0,};  // 빙고용 매트릭스

int main(void) {
    int bingo[25] = {0,};  // 빙고용 매트릭스
    int count = 0;    // 시도 횟수
    int number;     // 입력받는 번호
    int check;      // 빙고검사 결과값
    int i;
    srand(time(0)); // 랜덤 초기화
    // 빙고매트릭스 초기화(1부터 25까지 순서대로 넣음)
    for (i = 0; i < 25; i++) bingo[i] = i + 1;

    shuffleBingo(bingo); // 빙고 매트릭스 섞기
    printBingo(bingo);   // 빙고 매트릭스 출력
    while (1) {
        printf("Enter a number(1~25) > ");
        scanf("%d", &number);
        if ((number < 1 || number > 25)) break;
        else {
            check = markBingo(number, bingo);
            if (check != 0) count++;
            if (check == 1) break;
        }
    }
    printBingo(bingo);  // 빙고 매트릭스 출력
    printf("%d번 시도됨!\n", count);
    return 0;
}

void printBingo(int b[25]) {
    int i;
    printf("BINGO MATRIX\n");
    for (i = 0; i < 25; i++) {
        if (i % 5 == 0)
            printf("--------------------------\n|");
        printf(" %2d |", b[i]);
        if (i % 5 == 4) printf("\n");
    }
    printf("--------------------------\n");
}


int markBingo(int num, int b[25]) {
    if (b[shuffledBingo[num - 1]] == 0) { // 중복
        printf("중복!\n");
        return 0;
    } else {
        b[shuffledBingo[num - 1]] = 0; // 숫자 지우기
        return checkBingo(num, b); // 빙고 검사
    }
}

void shuffleBingo(int b[25]) {
    int index = 0;
    for (int i = 0; i < 25; i++) // 배열 초기화
        b[i] = 0;

    while (index < 25) { // 셔플
        int value = rand() % 25;
        if (b[value] == 0) {
            b[value] = ++index;
            shuffledBingo[index - 1] = value;
        }
    }
}


int checkBingo(int num, int b[]) {
    int sum = 0;
    int vertical = num % 5; // 세로 검사
    int horizontal = num - vertical; // 가로 검사

    for (int i = vertical; i < 25; i += 5) // 세로
        if (!b[i]) sum++;

    if (sum > 4) return 1;
    else sum = 0;

    for (int i = horizontal; i < horizontal + 5; i++) // 가로
        if (!b[i]) sum++;

    if (sum > 4) return 1;
    else sum = 0;

    for (int i = 0; i < 25; i += 6) // 대각선
        if (!b[i]) sum++;

    if (sum > 4) return 1;
    else sum = 0;

    for (int i = 4; i < 21; i += 4) // 반대 대각선
        if (!b[i]) sum++;

    if (sum > 4)
        return 1;
    else
        return -1;
}