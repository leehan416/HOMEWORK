#include <stdio.h>

int main(void) {
	int num[10];          // 10개의 숫자
	int sortNum[10];      // 10개의 숫자 => 정렬
	int first;            // 첫 번째로 큰 수
	int second;           // 두 번째로 큰 수
	int second_max_index; // 두 번째로 큰 수의 인덱스 
	int i, j;             // 반복문을 위한 변수 
	int temp;

	// 변수 입력
	for (i = 0; i < 10; i++) {
		printf("%d번째 수를 입력하시오. ", i + 1);
		scanf("%d", &num[i]);
		sortNum[i] = num[i]; // 정렬을 위한 배열에도 저장
	}

	//수 정렬
	for (i = 0; i < 10; i++) { // bubble sort
		for (j = 0; j < 9 - i; j++) {
			if (sortNum[j] > sortNum[j + 1]) { // swap
				temp = sortNum[j];
				sortNum[j] = sortNum[j + 1];
				sortNum[j + 1] = temp;
			}
		}
	}

	// linear search
	for (i = 0; i < 10; i++) {
		if (num[i] == sortNum[8]) { // 두번쨰로 큰 수라면
			// 출력
			printf("두번째로 큰 수는 %d번째 수 %d입니다.", i + 1, num[i]);
			break; // 반복문 나가기 => 연산 줄이기
		}
	}

	return 0;
}