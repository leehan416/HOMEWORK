#include <stdio.h>

int main(void) {
	int height;   // 입력받은 높이
	int blank;	// 입력받은 여백 크기
	int i, j;	 // 반복문 사용을 위한 변수

	// 변수 입력
	printf("height? ");
	scanf("%d", &height);

	printf("blank? ");
	scanf("%d", &blank);

	// 결과 출력
	for (i = 1; i <= height; i++) { // 열
		// 행
		for (j = 0; j < blank; j++) // 여백 출력
			printf(" ");
		for (j = 0; j < height - i; j++) // 삼각형 탑을 쌓기 위한 여백 출력
			printf(" ");
		for (j = i; j > 0; j--) // 별 출력
			printf("*");

		printf("\n"); // 한 행이 끝나면 줄 바꿈
	}

	return 0;
}