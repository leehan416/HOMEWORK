#include <stdio.h>

int main(void) {
	int mode; // 출력모드(1: 홀수단, 2: 짝수단)
	int column;   // 열 개수
	int i, j; // 반복문 사용을 위한 변수

	// 변수 입력
	printf("구구단의 출력모드(1: 홀수단, 2: 짝수단)를 입력하세요. ");
	scanf("%d", &mode);

	printf("한 줄에 출력할 갯수를 입력하세요. ");
	scanf("%d", &column);

	// 출력을 위한 반복문
	for (i = 2; i < 10; i++) {
		if ((mode == 1 && i % 2 == 0) || (mode == 2 && i % 2 == 1)) { // 조건에 맞는 경우에만 구구단 출력 
			if(i != 2) // 조건에 맞지 않으며 2단을 출력하는 경우가 아니면
				printf("\n"); // 줄바꿈
			continue;
		}
		for (j = 1; j < 10; j++) { // 구구단 출력
			printf("%d X %d =%3d", i, j, i * j);
			printf("  ");
			if (j % column == 0) printf("\n");
		}	
	}
	return 0;
}