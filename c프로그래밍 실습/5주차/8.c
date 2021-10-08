#include <stdio.h>

int main(void) {
	int number[10];   // 사용자가 입력한 숫자 10개
	int count;        // 현재까지 입력된 숫자의 갯수(0~10)
	int i, j;         // 반복문을 위한 변수

	// 변수 입력
	printf("1부터 100사이의 숫자를 입력하시오.\n");
	for (i = 0; i < 10; i++) {
		printf("%d번째 숫자를 입력하시오. ", i + 1);
		scanf("%d", &number[i]);

		// 중복 검사
		for (j = 0; j < i; j++) {
			if (number[i] == number[j]) { // 중복인 경우
				printf("잘못 입력하였습니다. 다시 입력하세요.\n");
				i--;
			}
		}
	}

	// 결과 출력
	for (i = 0; i < 10; i++)
		printf("%d번째 숫자는 %d입니다.\n", i + 1, number[i]);
	
	return 0;
}
