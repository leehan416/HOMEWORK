#include <stdio.h>

int main() {
	int size;
	printf("size? >> ");
	scanf("%d", &size);
	for (int i = 0; i < (size * 2) - 1; i++) {

		if (i < ((size * 2) - 1) / 2) { // 증가
			for (int j = 0; j < i + 1; j++) // 앞쪽 별 출력
				printf("*");
			for (int j = 0; j < ((size * 2) - 2) - (2 * i); j++) // 공백 출력
				// i 와 반복횟수가 반비례
				printf(" ");
			for (int j = 0; j < i + 1; j++) // 뒤쪽 별 출력
				printf("*");
		} else { // 감소
			for (int j = i; j < (size * 2) - 1; j++) // 앞쪽 별 출력
				printf("*");
			for (int j = 0; j < (size * 2) - ((size * 2) - 1 - i) * 2; j++) // 공백 출력
				// i 와 반복 횟수가 비례
				printf(" ");
			for (int j = i; j < (size * 2) - 1; j++)// 뒤쪽 별 출력
				printf("*");
		}
		printf("\n");
	}
	return 0;
}
