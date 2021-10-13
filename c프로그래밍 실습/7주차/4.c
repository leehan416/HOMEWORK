#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int com_finger;   // 컴퓨터가 낸 가위(1), 바위(2), 보(3)
    int my_finger;    // 사용자가 낸 가위(1), 바위(2), 보(3)
    int score[2][3] = {0,};  // 결과 횟수 (1행 : 컴퓨터의 승, 무, 패, 2행 : 사용자의 승, 무, 패)
    //int i, j;         // 반복문을 위한 변수 
    char text[3][10] = {"가위", "바위", "보"};
    char result[3][100] = {"사용자 승!", "컴퓨터 승!", "비김~"};

    while (my_finger > 0) { // 전체 반복문
        srand(time(NULL)); // 랜덤 시드 변경
        
        // 변수 입력
        printf("가위(1), 바위(2), 보(3)를 입력하세요. ");
        scanf("%d", &my_finger);
        
        // 랜덤 변수 생성
        com_finger = rand() % 3 + 1;
        
        // 결과 연산
        int value = (3 + my_finger - com_finger) % 3;
        
        // 결과 출력
        printf("컴퓨터: %s", text[com_finger]);
        printf(" -> %s", result[value]);
        printf("\n");
    }
    return 0;
}