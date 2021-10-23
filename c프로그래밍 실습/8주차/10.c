#include <stdio.h>

int markBingo(int num, int b[5][5]);

void printBingo(int b[5][5]);

int checkBingo(int b[5][5]);

int main(void) {
    int bingo[5][5] = {0}; // 빙고용 매트릭스
    int input; // 유저 입력

    while (1) {
        // 변수 입력
        printf("Enter a number(1~25) > ");
        scanf("%d", &input);

        if ((0 < input) && (input < 26)) { // 올바른 입력이라면
            int value = markBingo(input, bingo); // 함수 결과값 저장
            if (value == -1) {
                continue;
            } else if (value == 1) {
                printf("빙고!\n");
                break;
            } else {
                printf("중복!\n");
                continue;
            }
        } else {
            printf("EXIT!\n");
            break;
        }
    }
    // 빙고 출력
    printBingo(bingo);
    
    return 0;
}

int markBingo(int num, int b[5][5]) {
    int x = (num % 5) - 1;
    int y = num / 5;
    y = (x == -1) ? y - 1 : y;
    x = (x == -1) ? 4 : x;

    if (!b[y][x]) {
        b[y][x]++;
        return (checkBingo(b)) ? 1 : -1; // 빙고 검사
    } else {
        return 0;
    }
}

void printBingo(int b[5][5]) {
    printf("BINGO MATRIX\n");
    printf("---------------------\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j == 0) printf("|");
            printf("%2d |", b[i][j]);
        }
        printf("\n");
    }
    printf("---------------------\n");

}

// 빙고 검사
int checkBingo(int b[5][5]) {
    int sum1 = 0;
    int sum2 = 0;

    // 1자 빙고
    for (int i = 0; i < 5; i++) {
        sum1 = 0;
        sum2 = 0;
        for (int j = 0; j < 5; j++) {
            sum1 += b[i][j];
            sum2 += b[j][i];
        }
        if (sum1 == 5 || sum2 == 5) {
            break;
        }
    }
    if (sum1 == 5 || sum2 == 5) {
        return 1;
    }
    sum1 = 0;
    sum2 = 0;

    // 대각선 빙고
    for (int i = 0, k = 4; i < 5; i++, k--) {
        sum1 += b[i][i];
        sum2 += b[i][k];
    }
    if (sum1 == 5 || sum2 == 5) {
        return 1;
    }
    return 0;
}