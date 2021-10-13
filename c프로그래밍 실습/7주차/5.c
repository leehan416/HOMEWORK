#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int coins;      // 사용자의 코인 수. (최초에 입력받음)
    int number[3];  // 랜덤하게 만들어진 슬롯머신의 숫자 3개 
    int dummy;      // 게임스타트를 위한 의미 없는 입력 숫자 
    int i;          // 반복문을 위한 변수 
    int coin[] = {2, 4}; // 추가해주는 코인 갯수

    // 변수 입력
    printf("사용하실 코인의 개수를 입력하세요. ");
    scanf("%d", &coins);

    for (i = 0; coins > 0; coins--, i++) {
        // 변수 입력
        printf("게임 %d회 Start!!! (아무 숫자나 입력하세요) ", i + 1);
        scanf("%d", &dummy);
        //랜덤 시드 변경
        srand(time(NULL));

        for (int j = 0; j < 3; j++) // 랜덤 변수 생성
            number[j]  = rand() % 10 + 1;

        // 결과출력
        printf("게임 결과 : %d %d %d ----> ", number[0], number[1], number[2]);

        // 일치하는 숫자 탐색
        int count = 0;
        for (int j = 0; j < 3; j++) {
            count = 0;
            for (int k = 0; k < 3; k++) {
                if (number[j] == number[k])
                    count++;
            }
            if (count > 1)
                break;
        }
        
        // 코인 지급
        if (count != 1) {
            printf("숫자 %d개 일치... 코인 %d개 증정", count, coin[count - 2]);
            coins += coin[count - 2];
        } else {
            printf("꽝입니다... 아쉽군요");
        }
        printf("\n");
        // 결과 출력
        printf("남아있는 코인은 %d개입니다.\n", coins - 1);

    }

    printf("\n게임 종료!!");

    return 0;
}