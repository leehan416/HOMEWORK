#include <stdio.h>

void PrintStar(char text, int size);

int main(void) {
    int input[10];
    char gihoooo; // 입력받는 기호

    // 변수 입력
    printf("사용할 문자? ");
    scanf("%c", &gihoooo);
    
    printf("숫자 10개? ");
    for (int i = 0; i < 10; i++) 
        scanf("%d", &input[i]); 
        
    // 출력
    for (int i = 0; i < 10; i++) 
        PrintStar(gihoooo, input[i]);

    return 0;
}

void PrintStar(char text, int size) {
    for (int i = 0; i < size; i++)printf("%c", text);
    printf("\n");
}