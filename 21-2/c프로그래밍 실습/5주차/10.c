#include <stdio.h>

int main(void) {
	int bingo[5][5] = {0,}; // 5*5 매트릭스
	int input;

	for (int i = 0; i < 25; i++) { // 변수 입력 반복문
		printf("Enter a number(1~25) > ");
		scanf("%d", &input);
		if (input > 25) { // 25 이상이면 반복문 나가기
			printf("EXIT!\n");
			break;
		} else if (bingo[input / 5][(input % 5) - 1] == 1) { // 중복이면 다시하기
			printf("중복!\n");
			i--;
			continue;
		} else {
			bingo[input / 5][(input % 5) - 1]++;
		}
	}

	// 결과 출력
	printf("매트릭스의 내용은 다음과 같습니다.\n");
	for (int i = 0; i < 5; i++) {
		printf("---------------------\n");
		printf("|");
		for (int j = 0; j < 5; j++) {
			printf(" %d |", bingo[i][j]);
		}
		printf("\n");
	}
	printf("---------------------\n");
	return 0;
}