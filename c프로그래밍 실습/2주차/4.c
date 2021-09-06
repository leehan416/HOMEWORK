/*
2-4. 물의 온도 구간 판정
물의 온도를 입력받은 후, 이 물이 어느 정도의 온수인지 판정하여 그 결과를 출력하라.

단, 온수의 판정 구간은 다음과 같이 판정한다.

음수값 (0미만) : 잘못입력

0도 이상 ~ 25도 미만 : 냉수

25도 이상 ~ 40도 미만 : 미온수

40도 이상 ~ 80도 미만 : 온수

80도 이상 : 끓는 물

변수는 다음과 같이 사용하라.

float input_degree; // 입력받은 온도 
float input_degree; // 입력받은 온도 

	실행 예)

	degree? 30.7
	미온수 입니다.

	degree? 79.9
	온수 입니다.

	degree? -10.5
	잘못입력하셨습니다.

	degree? 95.0
	끓는 물입니다.
*/

#include <stdio.h>

int main(void) {
	
	float input_degree; // 입력받은 온도 

	//---------------------------------

	// "degree? " 출력
	printf("degree? ");
	// input_degree 입력받기
	scanf("%f", &input_degree);
	
	// 만약 input_degree가 0 보다 작다면
	if (input_degree < 0) {
  		printf("잘못입력하셨습니다.");
		//함수 종료
  		return 0;
	}

	// input_degree가 0 이상 25 미만이라면
	if ((0 <= input_degree) && (input_degree < 25)) printf("냉수 ");
	// input_degree가 25 이상 40 미만이라면
	else if ((25 <= input_degree) && (input_degree < 40)) printf("미온수 ");
	// input_degree가 40이상 80 미만이라면 
	else if ((40 <= input_degree) && (input_degree < 80)) printf("온수 ");
	// 80 이상이라면
	else printf("끓는 물");

	// "입니다." 출력
	printf("입니다.");

	//---------------------------------

	return 0;
}