#include <stdio.h>

int main(void) {
	int a, b, c;          // 2차 함수의 계수 a, b, c
	int x_begin, x_end;   // x좌표의 시작 값과 끝 값 
	int x, y;             // x좌표, y좌표

	//------------------------------
	// 변수 입력

	printf("2차 함수의 계수 a와 b와 c를 입력 ");
	scanf("%d %d %d", &a, &b, &c);
	printf("x좌표의 시작 값과 끝 값을 입력 ");
	scanf("%d %d", &x_begin, &x_end);

	//------------------------------
	// 결과 계산 및 출력
	for (x = x_begin; x <= x_end; x++) {
		y = a * x * x + b * x + c; // 계산
		printf("좌표 (%d,%d)\n", x, y); //출력
	}

	//------------------------------
	
	return 0;
}