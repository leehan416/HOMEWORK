#include <stdio.h>

int main(void) {
	// 변수 선언
	float c_degree; // 섭씨 온도 
	float f_degree; // 화씨 온도 

	//--------------------------
 
	// "섭씨 온도를 입력하시오. " 출력
	printf ("섭씨 온도를 입력하시오. ");
	// 섭씨 온도 입력 받기
	scanf("%f", &c_degree);
	// 화씨 온도 계산
	f_degree = c_degree * 1.8 + 32;
	// 화씨 온도 출력
	printf ("화씨 온도는 %.1f도 입니다.",f_degree);

	//----------------------------------------

	// 함수 종료
	return 0;
}