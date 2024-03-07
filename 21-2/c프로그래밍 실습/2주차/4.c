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