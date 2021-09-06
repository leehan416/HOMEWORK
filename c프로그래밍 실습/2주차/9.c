/*
2-9. 연봉을 입력받아 소득세 계산
연봉(원 단위)을 숫자로 입력받은 후, 연봉 금액에 대한 소득세를 계산하여 출력하라.

단, 소득세의 금액은 다음과 같이 계산한다.

연봉 1천만 원 미만 : 연봉의 9.5%

연봉 1천만 원 이상 ~ 4천만원미만 : 연봉의 19%

연봉 4천만 원 이상 ~ 8천만원미만 : 연봉의 28%

연봉 8천만 원 이상 : 연봉의 37%

변수는 다음과 같이 사용하라.

int income;	 // 연봉 (원 단위) 
int tax;		// 소득세 (원 단위) 
int income;	 // 연봉 (원 단위) 
int tax;		// 소득세 (원 단위) 

	실행 예)

	income? 25000000
	tax is 4750000.

	income? 50000000
	tax is 14000000.


	income? 100000000
	tax is 37000000.


	income? 8000000
	tax is 760000.
*/

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