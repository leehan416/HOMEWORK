#include <stdio.h>

void sort3Num(int *n1, int *n2, int *n3);

int main(void) {
    int num1, num2, num3;
    
    // 변수 입력
    printf("숫자 3개 입력 ");
    scanf("%d %d %d", &num1, &num2, &num3);

    //정렬
    sort3Num(&num1, &num2, &num3);

    // 결과 출력
    printf("정렬 결과 %d %d %d\n", num1, num2, num3);
    
    return 0;
}

void sort3Num(int *n1, int *n2, int *n3) {
    int arr[3];
    arr[0] = *n1;
    arr[1] = *n2;
    arr[2] = *n3;

    // bubble sort
    for (int i = 0; i < 3; i++) {
        for (int j = 0; 3 - (i + 1) > j; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    *n1 = arr[0];
    *n2 = arr[1];
    *n3 = arr[2];
}