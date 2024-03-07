#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int lotto[6];  // 컴퓨터가 만들어 낸 로또 번호
    int count;     // 현재 만들어지고 있는 로또 번호의 순서(0, 1, 2, 3, 4, 5)
    int onemore = 1;   // 반복여부 입력 (1:Yes, 2:No)

    while (onemore == 1) {
        srand(time(NULL)); // 랜덤 시드 변경
        for (int i = 0; i < 6; i++) { // 로또 번호 생성
            int b = 0; // bool 
            int value = rand() % 45 + 1; // 랜덤 수 생성
            for (int j = 0; j < i; j++) { // 같은 수 있는지 검사
                if (value == lotto[i]) { // 같은 수가 있다면
                    b = 1; // bool = true
                    break;
                }
            }
            if (b == 1) {
                i--;
                continue; // 다시 수 뽑기
            } else {
                lotto[i] = value; // 수 적용
            }
        }

        // 결과 출력
        printf("생성된 로또 번호는 %d %d %d %d %d %d 입니다.\n", lotto[0], lotto[1],
               lotto[2], lotto[3], lotto[4], lotto[5]);
        printf("더 만드시겠습니까? (1:Yes, 2:No) >> ");
        scanf("%d", &onemore);
    }
    return 0;
}