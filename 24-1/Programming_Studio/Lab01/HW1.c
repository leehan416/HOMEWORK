#include <stdio.h>

int main() {
    int size; // 크기
    int stars, blank1, blank2; // 별의 갯수, 빈칸1의 갯수, 빈칸2의 갯수 
    int i, j; // 반복문을 위한 변수

    scanf("%d", &size); // 입력

    blank1 = 0; // 별 외부 공백
    blank2 = size * 2 - 2; // 별과 별 사이
    stars = 1;
    //------------------------------------------
    // v자
    for (i = 0; i < size; i++) {
        for (j = 0; j < blank1; j++) {
            printf(" ");
        }
        printf("*"); // 첫번째 별 출력
        for (j = 0; j < blank2; j++) {
            printf(" ");
        }
        printf("*"); // 두번쨰 별 출력

        printf("\n");
        blank1++;
        blank2 -= 2;
    }
    //------------------------------------------
    // 사각형
    for (i = 0; i < size; i++) {
        for (j = 0; j < size * 2; j++)
            printf("*");
        printf("\n");
    }
    //------------------------------------------
    // 역피라미드
    blank1 = 0;
    stars = size * 2;
    for (i = 0; i < size; i++) {
        for (j = 0; j < blank1; j++)
            printf(" ");
        for (j = 0; j < stars; j++)
            printf("*");
        printf("\n");
        stars -= 2;
        blank1++;
    }
    //------------------------------------------
    // 받침대
    for (i = 0; i < size * 2; i++) {
        printf("*");
    }
        printf("\n");
        return 0;
}