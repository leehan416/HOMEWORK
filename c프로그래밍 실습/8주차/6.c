#include <stdio.h>

void PrintCharWithBlank(int blank, int height, char ch);

int main(void) {
    char ch;
    int height, blank;

    // 변수 입력
    printf("사용할 문자? ");
    scanf("%c", &ch);
    printf("높이와 여백의 크기? ");
    scanf("%d %d", &height, &blank);
    if (height <= 0 || blank < 0) { // 잘못입력한 경우
        printf("잘못 입력하셨습니다.");
        return 0;

    }
    // 출력
    PrintCharWithBlank(blank, height, ch);
}

void PrintCharWithBlank(int blank, int height, char ch) {
    static int index = 0; // static 타입 변수 생성
    if (index == height)
        return;
    for (int i = 0; i < blank + (height - index) - 1; i++)
        printf(" ");
    for (int i = 0; i < height - (height - index) + 1; i++)
        printf("%c", ch);
    printf("\n");
    index++;
    PrintCharWithBlank(blank, height, ch); // 재귀함수
}