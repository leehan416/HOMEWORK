#include <stdio.h>

int markBingo(int num, int b[5][5]);

//파라미터 : 선택된 칸번호(num), 빙고매트릭스(b)
//리턴값 : 이미 마크되어 있었음 0, 마크 안되어 마크함 1
//수행내용 : 현재의 빙고매트릭스에 선택된 칸번호에 해당되는 칸 검사한 후 마크함
void printBingo(int b[5][5]);
//파라미터 : 빙고매트릭스(b)
//리턴값 : 없음
//수행내용 : 현재의 빙고매트릭스 내용 표현

int main(void) {
    int bingo[5][5] = {0}; // 빙고용 매트릭스
    int input; // 유저 입력

    while (1) {
        // 변수 입력
        printf("Enter a number(1~25) > ");
        scanf("%d", &input);

        if ((0 < input) && (input < 26)) { //잘못된 입력이 아니라면
            int value = markBingo(input, bingo); // 변수에 함수 결과 저장
            if (value) {
                continue;
            } else { // 0 
                printf("중복!\n");
                continue;
            }
        } else {
            break;
        }
    }
    printf("EXIT!\n");
    printBingo(bingo);
    return 0;
}

int markBingo(int num, int b[5][5]) {
    int y = num / 5;
    int x = (num % 5) - 1;
    y = (x == -1) ? y - 1 : y;
    x = (x == -1) ? 4 : x;
    if (!b[y][x]) {
        b[y][x]++;
        return 1;
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
