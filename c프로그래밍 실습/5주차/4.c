/*
5-4. 두번째로 큰 수의 순서찾기
10개의 숫자를 입력받아 배열에 저장한 후에 이 중에서 두 번째로 큰 수가 몇 번째 숫자인지 찾아내어 출력하라.

변수는 다음과 같이 사용하라.
 int num[10];             // 10개의 숫자
 int first;               // 첫 번째로 큰 수
 int second;              // 두 번째로 큰 수
 int second_max_index;    // 두 번째로 큰 수의 인덱스 
 int i;                   // 반복문을 위한 변수 

실행 예)
	1번째 수를 입력하시오. 11
	2번째 수를 입력하시오. 22
	3번째 수를 입력하시오. 33
	4번째 수를 입력하시오. 55
	5번째 수를 입력하시오. 66
	6번째 수를 입력하시오. 77
	7번째 수를 입력하시오. 88
	8번째 수를 입력하시오. 99
	9번째 수를 입력하시오. 44
	10번째 수를 입력하시오. 77
	두번째로 큰 수는 7번째 수 88입니다. 
*/
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