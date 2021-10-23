#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int bingo[5][5] = {0}; // 빙고용 매트릭스
    int number[10]; // 입력받는 행, 열 번호 

    srand(time(NULL)); // 랜덤 시드 변경

    // 랜덤 위치 생성
    for (int i = 0; i < 10; i++) {
        int value = rand() % 25 + 1;
        int val = 0;

        for (int j = 0; j < i; j++) {
            if (number[j] == value) {
                val = 1;
                break;
            }
        }
        if (val) {
            i--;
            continue;
        } else {
            number[i] = value;
        }
    }

    int x, y;
    // 위치 적용
    for (int i = 0; i < 10; i++) {
        x = (number[i] % 5) - 1;
        y = number[i] / 5;
        y = (x == -1) ? y - 1 : y;
        x = (x == -1) ? 4 : x;
        bingo[y][x]++;
    }

    // 결과 출력
    printf("---------------------\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("| ");
            printf("%d ", bingo[i][j]);
        }
        printf("|\n");
        printf("---------------------\n");
    }

    return 0;
}
