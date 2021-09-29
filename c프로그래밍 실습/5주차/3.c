/*
5-3. 스포츠 심사 점수 계산하기
심사점수를 10개 입력받아 배열에 저장한 후, 이 중에서 가장 큰 점수와 가장 작은 점수를 제외한 8개의 점수에 대한 평균을 계산하여 출력하라.

변수는 다음과 같이 사용하라.

float score[10];      // 심사점수
float max, min;       // 가장 큰 점수, 가장 작은 점수
float total;          // 점수 총 합계
float average;        // 평균점수
int i;                // 반복문을 위한 변수  

실행 예)
	1번 심사점수? 9.5
	2번 심사점수? 6.8
	3번 심사점수? 7.9
	4번 심사점수? 9.9
	5번 심사점수? 4.6
	6번 심사점수? 6.2
	7번 심사점수? 7.7
	8번 심사점수? 5.4
	9번 심사점수? 8.0
	10번 심사점수? 7.6
	가장 큰 점수와 가장 작은 점수를 제외한 8개의 점수에 대한 평균은 7.4입니다.
*/
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