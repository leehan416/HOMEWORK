#include <stdio.h>

int main(void) {
	// 변수 선언
	float m2_area;		 // 면적 (제곱미터)	
	float pyung_area;	// 면적 (평수)

	//------------------

	// "m2_area? " 출력
	printf ("m2_area? "); 
	// m2_area 입력받기
	scanf("%f", &m2_area);
	//평수 계산
	pyung_area = m2_area / 3.305;
	//평수 출력
	printf ("pyung_area is %.1f.",pyung_area );

	//------------------

	//함수 종료
	return 0;
}