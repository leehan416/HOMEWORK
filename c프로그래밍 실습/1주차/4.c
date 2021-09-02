/*
1-4. 직사각형의 가로 세로 크기를 입력받아 넓이 계산
직사각형의 가로크기와 세로크기를 입력받아 이 값을 이용하여 직사각형의 넓이를 계산하고 출력하라.

단, 직사각형의 넓이 = 가로크기 * 세로크기 로 계산한다.

변수는 다음과 같이 사용하라.

int width, height;  // 가로크기, 세로크기 
int area;           // 직사각형의 넓이 
int width, height;  // 가로크기, 세로크기 
int area;           // 직사각형의 넓이 
실행 예)
	width? 10
	height? 20

	area is 200.
*/

#include <stdio.h>

int main(void) {
	//변수 선언
	int width, height;  // 가로크기, 세로크기 
	int area;           // 직사각형의 넓이 

	//---------------------------------

	//"width? " 출력
	printf ("width? ");
	//width 입력받기
	scanf ("%d",&width);
	//"height? " 출력
	printf ("height? ");
	//height 입력받기
	scanf("%d",&height);
	//넓이 출력하기
	printf ("area is %d.",width * height);

	//---------------------------------

	// 함수 종료
	return 0;
}