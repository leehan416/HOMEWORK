/*
1-2. 키와 몸무게로 비만도(BMI) 계산
신장(cm단위)과 체중(kg단위)를 입력받은 후, 비만도(BMI)를 계산하여 출력하라.

비만도 수치 = 체중(kg) / (신장(m)의 제곱) 으로 계산한다.

이 때, 신장은 미터 단위로 환산해야 함을 유의하라.

변수는 다음과 같이 사용하라.

int height, weight; // 신장(cm), 체중(kg) 
float bmi; // 비만도 수치 
int height, weight; // 신장(cm), 체중(kg) 
float bmi; // 비만도 수치 

실행 예)

	height? 165
	weight? 70
	Your bmi is 25.7

	height? 185
	weight? 70
	Your bmi is 20.5
*/

#include <stdio.h>

int main(void) {

	// 변수 선언
	int height, weight; // 신장(cm), 체중(kg) 
	float bmi; // 비만도 수치
	float value; // 코드 가독성을 위한 변수 : (신장 m 단위)^2

	//-------------------------
  
	// "height? " 출력
	printf ("height? ");
	// height 입력받기
	scanf("%d", &height);
	// "weight? " 출력
	printf ("weight? ");
	// weight 입력받기
	scanf ("%d", &weight);

	// 신장 m 단위 변환 => 제곱
	value  =  (float)height * 0.01 * (float)height * 0.01;
  
	// bmi 계산
	bmi = weight / value;

	// 출력
	printf ("Your bmi is %.1f", bmi);

	//-------------------------

	// 함수 종료
	return 0;
}