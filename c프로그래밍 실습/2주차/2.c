/*
2-2. 비만 판정
신장(cm단위)과 체중(kg단위)를 입력받은 후, 비만 여부를 판정하여 출력하라.

단, 비만여부는 다음 비만도 수치가 25이상인 경우에 "비만"으로 판단한다. 비만도 수치 = 체중(kg) / (신장(m)의 제곱) 으로 계산한다.

이 때, 신장은 미터 단위로 환산해야 함을 유의하라.

변수는 다음과 같이 사용하라.

int height, weight; // 신장(cm), 체중(kg)
float bmi;          // 비만도 수치 
int height, weight; // 신장(cm), 체중(kg)
float bmi;          // 비만도 수치 
	
	실행 예)

	height? 165
	weight? 70
	You are overweight.
	height? 185
	weight? 70
	You are not overweight.
*/
#include <stdio.h>
#include <math.h>

int main(void) {
    
	int height, weight; // 신장(cm), 체중(kg)
	float bmi;          // 비만도 수치 
	float value;        // 코드 가독성을 위한 변수 => m 단위 신장^2

	//----------------------------------

	// "height? " 출력
	printf("height? ");
	// height 입력받기
	scanf("%d",&height);

	// "weight? "
	printf("weight? ");
	// weight 입력받기
	scanf("%d", &weight);
 
	// bmi 계산
	bmi = weight / pow((float)height *0.01, 2);;

	// 만약 bmi가 25 보다 크다면
	if (bmi >= 25.0) printf ("You are overweight.");
	// 그렇지 않다면
	else printf("You are not overweight.");

	//----------------------------------

	return 0;

}