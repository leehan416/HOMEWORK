#include <stdio.h>

int checkBingo(int num, int b[]);

int markbingo(int num, int b[]);


//파라미터 : 선택된 칸번호(num), 빙고매트릭스(b)
//리턴값 : 이미 마크되어 있었음 0,
//       마크 안되어 마크하였는데 빙고 완성됨 1,
//       마크 안되어 마크하였는데 빙고는 미완성 -1,
//수행내용 : 현재의 빙고매트릭스에 선택된 칸번호에 해당되는
//         칸 검사한 후 마크함
void printBingo(int b[]);
//파라미터 : 빙고매트릭스(b)
//리턴값 : 없음
//수행내용 : 현재의 빙고매트릭스 내용 표현

int main(void) {
    int bingo[25] = {0}; // 빙고용 매트릭스
    int input;
    while (1) {

        // 변수 입력
        printf("Enter a number(1~25) > ");
        scanf("%d", &input);

        // 결과 비교
        if ((input <= 0 || 25 < input)) {
            printf("EXIT!\n");
            break;
        } else {
            // 함수 결과 받아오기
            int value = markbingo(input - 1, bingo);

            if (value == 1) {
                printf("빙고!\n");
                break;
            } else if (value == 0) {
                printf("중복!\n");
                continue;
            } else { // -1
                continue;
            }
        }
    }
    printBingo(bingo);
}

int markbingo(int num, int b[]) {
    if (b[num])
        return 0;
    else
        b[num]++;

    // 빙고 검사
    return (checkBingo(num, b) ? 1 : -1);


}

int checkBingo(int num, int b[]) {
    int sum = 0;
    int vertical = num % 5; // 세로 검사
    int horizontal = num - vertical; // 가로 검사

    for (int i = vertical; i < 25; i += 5) // 세로
        if (b[i]) sum++;

    if (sum > 4) return 1;
    else sum = 0;

    for (int i = horizontal; i < horizontal + 5; i++) // 가로
        if (b[i]) sum++;

    if (sum > 4) return 1;
    else sum = 0;

    for (int i = 0; i < 25; i += 6) // 대각선

        if (b[i]) sum++;

    if (sum > 4) return 1;
    else sum = 0;

    for (int i = 4; i < 21; i += 4) // 반대 대각선
        if (b[i]) sum++;

    if (sum > 4)
        return 1;
    else
        return 0;
}

void printBingo(int b[]) {
    printf("BINGO MATRIX\n");

    for (int i = 0; i < 25; i++) {
        if (i % 5 == 0)
            printf("---------------------\n");
        printf("| %d ", b[i]);
        if ((i + 1) % 5 == 0) printf("|\n");
    }
    printf("---------------------\n");

}