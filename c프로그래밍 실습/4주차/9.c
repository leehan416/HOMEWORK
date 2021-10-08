#include <stdio.h>

int main() {
	int size;
	
	// 변수 입력
	printf("size? >");
	scanf("%d", &size);
	
	// 결과 출력
	for (int i = 0; i < size; i++) {// 층
		
		for (int j = 0; j < size - (i + 1); j++) // 공백 출력
			printf(" ");
		//---------------------------------
		// 앞쪽 별 하나 출력
		if (i == 0) printf(" *"); // 테스트에서 에러 피하기 위함 => 원래는 공백 없애도 됨
		else printf("*"); 
		
		//---------------------------------
		// 상황에 맞춰 공백 or 별 출력
		
		if ((2 * i) - 1 == size - 2 || (2 * i) - 1 == size - 1) { // 별을 한줄 출력하는 경우
			int num; // 출력을 위한 변수
			// 짝수일 경우와 홀수일 경우로 나눠서 변수의 수가 달라짐
			if ((2 * i) - 1 == size - 2) num = size - 2; 
			else num = size - 1;
			for (int j = 0; j < num; j++) // 한줄 출력
				printf("*");
		} else { // 공백 출력
			if (i != 0) {
				for (int j = 0; j < (2 * i) - 1; j++) {
					printf(" ");
				}
			}
		}
		
		//---------------------------------
		// 끝쪽 별 출력
		
		if (i != 0)printf("*");
		printf("\n"); // 출력이 끝나면 줄바꿈
	}
	//-------------------------------

	return 0;
}