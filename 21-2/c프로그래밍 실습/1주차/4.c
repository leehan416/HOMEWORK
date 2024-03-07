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