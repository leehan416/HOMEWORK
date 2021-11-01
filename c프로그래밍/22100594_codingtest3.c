//3
//22100594 이한결

#include<stdio.h>

#define N 10

int main() {
   int arr[N] = {3, 7, 2, 6, 9, 4, 8, 1, 3, 3};
   
    for (int i = 0; i < N; i++) {
        for (int j = 0; (N - 1) > j; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < N; i++) 
        printf("%d ", arr[i]);
    printf("두번째로 큰 값은 %d", arr[N-2]);
}
