//제공된 코드 main() 수정 금지
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// int used[50] = {0}; // 숫자 사용 여부 (0:미사용, 1:사용), 9번이 빙고에 사용되었으면 used[8]=1이 됨!
int markBingo(int num, int b[25]);

void shuffleBingo(int b[25]);

void printBingo(int b[25]);

int checkBingo(int b[]);

int shuffledBingo[50] = {-1,};  // 빙고용 매트릭스

int main(void) {
    int bingo[25];        // 빙고용 매트릭스
    int count = 0;        // 시도 횟수
    int number;        // 입력받는 번호
    int check;            // 빙고검사결과값
    srand(time(0));        // 랜덤 초기화
    shuffleBingo(bingo);    // 빙고 매트릭스 섞기

    while (1) {
        printf("Enter a number(1~50) > ");
        scanf("%d", &number);
        if ((number < 1 || number > 50)) {
            printf("EXIT!");
            break;
        } else {
            check = markBingo(number, bingo);
            if (check == 1 || check == -1) count++;
            if (check == 1) break;
        }
    }
    printBingo(bingo);    // 빙고 매트릭스 출력
    printf("%d번 시도됨!\n", count);
    return 0;
}

void printBingo(int b[25]) {
    int i;
    printf("\nBINGO MATRIX\n");
    for (i = 0; i < 25; i++) {
        if (i % 5 == 0)
            printf("--------------------------\n|");
        printf(" %2d |", b[i]);
        if (i % 5 == 4) printf("\n");
    }
    printf("--------------------------\n");
}


int markBingo(int num, int b[25]) {
    if (shuffledBingo[num - 1] == -1) {
        printf("없는 값!\n");
        return -2;
    } else if (b[shuffledBingo[num - 1] - 1] == 0) { // 중복
        printf("중복!\n");
        return 0;
    } else {
        b[shuffledBingo[num - 1] - 1] = 0; // 숫자 지우기
        return checkBingo(b); // 빙고 검사
    }
}

void shuffleBingo(int b[25]) {
    int index = 0;
    for (int i = 0; i < 25; i++) // 배열 초기화
        b[i] = 0;

    while (index < 25) { // 셔플
        int value = rand() % 50;

        if (!shuffledBingo[value]) {
            shuffledBingo[value] = ++index;
            b[index - 1] = value + 1;
        }
    }
}


int checkBingo(int b[]) {
    int sum = 0;

    for (int i = 0; i < 25; i += 5) {
        sum = 0;
        for (int j = i; j < i + 5; j++) {
            if (b[j] == 0)
                sum++;
        }
        if (sum > 4) {
            printf("빙고! %d번째 줄", i + 1);
            return 1;

        }
    }

    for (int i = 0; i < 5; i++) {
        sum = 0;
        for (int j = i; j < 25; j += 5) {
            if (b[j] == 0)
                sum++;
        }
        if (sum > 4) {
            printf("빙고! %d번째 칸", i + 1);
            return 1;
        }
    }


    for (int i = 0; i < 25; i += 6) // 대각선
        if (!b[i]) sum++;

    if (sum > 4) {
        printf("빙고! 대각선");
        return 1;
    } else sum = 0;

    for (int i = 4; i < 21; i += 4) // 반대 대각선
        if (!b[i]) sum++;

    if (sum > 4) {
        printf("빙고! 대각선");
        return 1;
    } else
        return -1;
}