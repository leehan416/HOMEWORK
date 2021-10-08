#include <stdio.h>

int main() {
    int size;
    printf("size? ");
    scanf("%d", &size); // 크기 입력
    int x, y;
    int map[size][size];

    for (int i = 0; i < size; i++) // 초기화
        for (int j = 0; j < size; j++)
            map[i][j] = 0;
        
    x = size / 2; // 중앙
    y = 0;

    for (int i = 1; i <= size * size; i++) { // 마방진 만들기
        if (map[y][x] == 0) { // 0 이면 적용하고 왼쪽 대각선 위로 이동
            map[y][x] = i;
            y--;
            x--;
            if (x < 0)
                x = size - 1;
            if (y < 0)
                y = size - 1;
        } else { // 0이 아니라면 이전 위치에서 y+1 하고 반복문 다시 진행
            x++;
            y += 2;
            if (y > size - 1)
                y = 0;
            if (x > size - 1)
                x = 0;
            i--;
            continue;
        }
    }

    //결과 출력
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%4d", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}
