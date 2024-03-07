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