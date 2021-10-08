#include <stdio.h>

int main(void) {
	float score[10];   // 심사점수
	float max, min;	   // 가장 큰 점수, 가장 작은 점수
	float total;       // 점수 총 합계
	float average;     // 평균점수
	int i;             // 반복문을 위한 변수  
	float sum = 0;
	
	// 변수 초기화
	max = 0;
	min = 100;
	
	for (i = 0; i < 10; i++) { // 입력, 연산하는 반복문
		// 변수 입력
		printf("%d번 심사점수? ", i + 1);
		scanf("%f", &score[i]);
		
		// 최대, 최솟값 찾기
		if (max < score[i]) max = score[i];
		if (min > score[i]) min = score[i];
		
		// 전체값에 더하기
		sum += score[i];
	}

	// 결과 에 맞추어 연산
	sum -= (max + min);

	// 결과 출력
	printf("가장 큰 점수와 가장 작은 점수를 제외한 8개의 점수에 대한 평균은 %.1f입니다.", sum / 8);

	return 0;
}