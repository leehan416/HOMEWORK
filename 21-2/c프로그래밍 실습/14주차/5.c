#include <stdio.h>

int fibonacci(int n);

int main(void) {

    for (int i = 0; i < 17; i++) {
        int num1 = fibonacci(i + 2);
        int num2 = fibonacci(i + 1);
        printf("%d번째 비율 (%d / %d) : %f\n", i + 1, num1, num2, ((float) num1 / num2));
    }
    return 0;

}

int fibonacci(int n) {
    if (n <= 2)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}