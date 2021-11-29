//22100594 이한결
//2
#include <stdio.h>
#define N 100
int main() {
    int arr[10]; // 입력 배열

    int arrNum[N] = {0,}; // 횟수 저장
    int index = 0;
    int max = -1; // 수
    int value = 0; // 횟수

    for (int i = 0; i < 10; i++) {
        printf("%d번째 수 입력", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 10; i++)
        arrNum[arr[i]]++;

    for (int i = 0; i < N; i++) {
        if (max < arrNum[i]) {
            max = arrNum[i];
            index = i;
        }
    }

    printf("가장 빈도가 높은 수 %d", index);

    return 0;

}
