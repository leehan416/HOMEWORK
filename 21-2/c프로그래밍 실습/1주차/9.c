#include <stdio.h>

int main(void) {
	// 변수 선언
	int a, b; // 1차 함수의 계수 a, b
	int x;    // x값

	//---------------------------

	// "1차 함수의 계수 a와 b를 입력 " 출력
	printf ("1차 함수의 계수 a와 b를 입력 ");
	// a, b 입력 받기
	scanf ("%d %d", &a, &b);
	
	// "x값을 입력 " 출력
	printf("x값을 입력 ");
	// x 값 입력받기
	scanf ("%d", &x);
	
	// 결과 출력
	printf ("f(x)의 값은 %d입니다.", (a * x + b));

	//---------------------------
 
	// 함수 종료
	return 0; 

}