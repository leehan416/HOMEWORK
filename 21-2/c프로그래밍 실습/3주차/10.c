#include <stdio.h>

int main(void) {
	int number;                         // 입력받은 수 
	int max_num = -1, min_num = 100;    // 가장 큰 숫자, 가장 작은 숫자 
	
	//--------------------------------
	
	while (1) {
		//----------------------------
		// 변수 입력
		printf("0부터 100 사이의 숫자를 입력 ");
		scanf("%d", &number);
		//----------------------------
		// 종료 조건 검사
		if (!(0 <= number && number <= 100))break;
		//--------------------------------
		// 결과 적용
		if (min_num > number)
			min_num = number;
		if (max_num < number)
			max_num = number;
	}

	//--------------------------------
	// 결과 출력
	
	printf("입력된 숫자들 중 가장 큰수는 %d이고,\n", max_num);
	printf("가장 작은 수는 %d입니다.", min_num);
	
	//--------------------------------
	
	return 0;
}