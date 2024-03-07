#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    
    char map[10][10];
    int size;
    int x, y;

    // 배열 초기화
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            map[i][j] = '+';

    // 변수 입력
    printf("Enter size >> ");
    scanf("%d", &size);

    // @ 넣기
    for (int i = 0; i < size; i++) {
        srand(time(NULL));
        x = rand() % 9 + 0;
        y = rand() % 9 + 0;

        if (map[y][x] == '@') { // 중복이면 넘어가기
            i--;
            continue;
        } else {
            map[y][x] = '@';
        }
    }

    // 결과 출력
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }


    return 0;
}