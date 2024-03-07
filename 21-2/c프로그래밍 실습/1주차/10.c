#include <stdio.h>
#include <math.h>

int main(void) {

	float x1, x2;  // x좌표 값
	float y1, y2;  // y좌표 값 
	float distance; // 거리 값
	
	//---------------------------
	
	// "첫번째 좌표의 x값? " 출력
	printf ("첫번째 좌표의 x값? ");
	// x1 입력받기
	scanf("%f", &x1);
	// "첫번째 좌표의 y값? " 출력
	printf ("첫번째 좌표의 y값? ");
	// y1 입력받기
	scanf("%f", &y1);
	// "두번째 좌표의 x값? " 출력
	printf ("두번째 좌표의 x값? ");
	// x2 입력받기
	scanf("%f", &x2);
	// "두번째 좌표의 y값? " 출력
	printf ("두번째 좌표의 y값? ");
	// y2 입력받기
	scanf("%f", &y2);

	// 거리 계산
	distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); 
	
	//출력
	printf ("두 좌표 사이의 거리는 %.1f", distance);
 
	//---------------------------
 
	// 함수 종료
	return 0;
}