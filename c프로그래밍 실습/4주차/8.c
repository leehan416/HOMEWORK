#include <stdio.h>

int main(void) {
	int height;   // 입력받은 높이
	int i, j;	 // 반복문 사용을 위한 변수
	
	// 변수 입력
	printf("height? ");
	scanf("%d", &height);
	
	// 결과 출력
	for (i = 1; i <= height; i++) {
		for (j = height - i; j > 0; j--)printf(" "); // 여백 출력
		for (j = 0; j < 2 * i - 1; j++) printf("*"); // 별 출력
		printf("\n");
	}
	return 0;
}