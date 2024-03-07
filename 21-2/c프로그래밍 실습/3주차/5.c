#include <stdio.h>

int main(void) {
	int number;         // 입력받은 수
	int count = 0;      // 입력받은 숫자의 개수
	int totalsum = 0;   // 합계
	float average = 0.0;// 평균 값 

	//-------------------------------
	// 입력하는 반복문

	while (1) { // 무한 반복
		//---------------------------
		printf("0초과의 숫자를 입력하세요 ");
		scanf("%d", &number);
		//---------------------------
		if (number <= 0) break; // 종료 조건이면 반복문 나가기
		// 변수 증가
		count++; 
		totalsum += number;
	}

	//-------------------------------
	// 결과 연산

	if (count > 0) average = (float) totalsum / (float) count; // 0개 초과의 숫자가 입력되었을 때에 연산
		
	//-------------------------------
	// 결과출력

	printf("입력한 %d개의 숫자들의 총합계는 %d이고, 평균 값은 %.1f 입니다.", count, totalsum, average);
		
	//-------------------------------
		
	return 0;
}