#include <stdio.h>

int main(void) {
	int mode; // 출력모드(1: 홀수단, 2: 짝수단)
	int i, j; // 반복문 사용을 위한 변수

	// 변수 입력
	printf("구구단의 출력모드(1: 홀수단, 2: 짝수단)를 입력하세요. ");
	scanf("%d", &mode);

	for (i = 2; i < 10; i++) { // 출력을 위한 반복문

		if ((mode == 1 && i % 2 == 0) || (mode == 2 && i % 2 == 1)) // 각 모드에 맞게 아래 조건에 도달
			continue;

		for (j = 1; j < 10; j++) { // 조건에 맞았다면 구구단 출력
			printf("%d X %d =%3d", i, j, i * j);
			printf("    ");
			if (j % 3 == 0) printf("\n");
		}
		printf("\n");
	}
	return 0;
}