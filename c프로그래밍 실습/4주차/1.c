#include<stdio.h>
#include <math.h>

int main(void) {
	// 변수 선언
	int input, i;
	int goal = 50;
	int min = 0;
	int max = 100;
	//------------------------------------------
	for (i = 1;; i++) {
		// 입력받기
		printf("How about %d? (try more : 1, try less : 2, right : 0) ", goal);
		scanf("%d", &input);
		
		if (input == 1) min = goal; // 최솟값 재설정
		else if (input == 2) max = goal; // 최댓값 재설정
		else if (input == 0) break; // 종료
		goal = (min + max) / 2; // 중간값으로 초기화
		if (((float)min + (float)max) / 2.0 - goal >= 0.5) goal++; // 반올림
	}
	printf("%d tried.", i); // 결과 출력

	return 0;
}