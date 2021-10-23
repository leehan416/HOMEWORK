#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int matchLotto(int lotto1[6], int lotto2[6]);

int checkNum(int num, int arr[6]);

int main(void) {
    int input;
    int inputLotto[6] = {0,};
    int Lotto[6] = {0,};
    srand(time(NULL));

    // 로또 번호 생성
    for (int i = 0; i < 6; i++) {
        int value = rand() % 45 + 1;
        if (checkNum(value, Lotto)) // 이미 존재하는 수
            i--;
        else
            Lotto[i] = value;
    }

    // 로또 번호 정렬 
    // bubble sort
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6 - (i + 1); j++) {
            if (Lotto[j] > Lotto[j + 1]) {
                int temp = Lotto[j];
                Lotto[j] = Lotto[j + 1];
                Lotto[j + 1] = temp;
            }
        }
    }

    // 로또 번호 입력
    for (int i = 0; i < 6; i++) {
        printf("원하는 %d번째 로또 숫자를 입력 ", i + 1);
        scanf("%d", &input);
        if (checkNum(input, inputLotto) || input > 45) { // 이미 입력한 수
            printf("-> 잘못 입력\n");
            i--;
        } else { 
            inputLotto[i] = input;
        }
    }

    // 결과 출력
    printf("이번 주의 로또 당첨 번호는");
    for (int i = 0; i < 6; i++)
        printf(" %d", Lotto[i]);
    printf("\n");
    printf("일치하는 로또 번호는 %d", matchLotto(inputLotto, Lotto)); // 일치 번호 출력

    return 0;
}

// 입력한 숫자인지 검사 
int checkNum(int num, int arr[6]) {
    int value = 0;
    for (int i = 0; i < 6; i++)
        if (arr[i] == num)
            value++;
    return value;
}


int matchLotto(int lotto1[6], int lotto2[6]) {
    int count = 0;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            if (lotto1[i] == lotto2[j])
                count++;
    return count;
}