#include <stdio.h>
#include <math.h>

int main(void) {

	int income;	 // 연봉 (원 단위) 
	int tax;		// 소득세 (원 단위) 

	// 코드 가독성을 위한 변수들
	int value = pow(10, 7); //10000000
	float percent; 

	//-----------------------------------
	// 변수 입출력

	printf("income? ");
	scanf("%d", &income);

	//-----------------------------------
	// 소득세 적용

	// 연봉이 천만원 이하
	if (income < value)
		tax = (float) income * (float) (9.5 / 100);

	// 연봉이 천만원 이상 4천만원 이하
	else if (value <= income && income < 4 * value)
		tax = (float) income * (float) (19.0 / 100);

	// 연봉이 4천만원 이상 8천만원 이하
	else if (4 * value <= income && income < 8 * value) 
		tax = (float) income * (float) (28.0 / 100);
	
	// 연봉이 8천만원 이상
	else
		tax = (float) income * (float) (37.0 / 100);

	//-----------------------------------
	// 결과 출력
	printf("tax is %d.", tax);

	//-----------------------------------

	return 0;
}