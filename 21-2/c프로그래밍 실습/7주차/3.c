#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int lotto_com[6];   // 컴퓨터가 만들어 낸 로또 번호
    int lotto_user[6];  // 사용자가 입력한 로또 번호
    int i;              // 반복문을 위한 변수
    int count = 0;      // 현재 만들어지고 있는 로또 번호의 순서(0, 1, 2, 3, 4, 5)
    int match_count;    // 일치하는 로또 번호의 갯수 (0~6) 
    
    srand(time(NULL)); // 랜덤 시드 변경
    
    for (i = 0; i < 6; i++) { // 로또 번호 생성 => 이전 문제와 같은 로직이므로 설명 생략
        int b = 0;
        int value = rand() % 45 + 1;
        for (int j = 0; j < i; j++) {
            if (lotto_com[i] == value) {
                b = 1;
                break;
            }
        }
        if (b == 1) {
            i--;
            continue;
        } else {
            lotto_com[i] = value;
        }
    }

    for (i = 0; i < 6; i++) { // 입력 반복문
        int b = 0;
        int value;
        // 변수 입력
        printf("원하는 %d번째 로또 숫자를 입력 ", i); 
        scanf("%d", &value);

        // 변수가 이미 입력되었는지 검사
        for (int j = 0; j < i; j++) {
            if (lotto_user[i] == value) { // 이미 입력된 수라면
                b = 1; // true
                break;
            }
        }
        if (b == 1) {
            printf("-> 잘못 입력\n");
            i--;
            continue; // 다시 입력
        } else {
            lotto_user[i] = value; //변수 적용
        }
    }

    //결과 출력
    printf("이번 주의 로또 당첨 번호는 %d %d %d %d %d %d \n\n", lotto_com[0], lotto_com[1], lotto_com[2], lotto_com[3],
           lotto_com[4], lotto_com[5]);
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            if (lotto_com[i] == lotto_user[j])
                count++;

    printf("일치하는 로또 번호는 %d개 입니다", count);
    return 0;
}