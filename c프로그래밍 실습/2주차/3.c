/*
2-3. 직사각형 넓이 계산 및 정사각형 판정
직사각형의 가로크기와 세로크기를 입력받아 이 값을 이용하여 직사각형의 넓이를 계산하고 정사각형인지의 여부를 판정하여 함께 출력하라.

단, 직사각형의 넓이 = 가로크기 * 세로크기 로 계산한다.

변수는 다음과 같이 사용하라.

int width, height;  // 가로크기, 세로크기 
int area;           // 사각형의 넓이 
int width, height;  // 가로크기, 세로크기 
int area;           // 사각형의 넓이 
	
	실행 예)

	width? 10
	height? 20
	넓이는 200이고 정사각형이 아닙니다.

	width? 20 
	height? 20
	넓이는 400이고 정사각형입니다.
*/

#include <stdio.h>

int main(void) {

	int width, height;  // 가로크기, 세로크기 
	int area;           // 사각형의 넓이 

	//-------------------------------

	// "width? " 출력
	printf("width? ");
	// width 입력받기
	scanf("%d", &width);

	// "height? " 출력
	printf("height? ");
	// height 입력받기
	scanf("%d", &height);

	// 넓이 계산
	area = width * height ;
	// 넓이 출력
	printf("넓이는 %d이고 ",area);
	// 가로와 세로가 같다면 
	if (width == height) printf("정사각형입니다.");
	// 그렇지 않다면
	else printf("정사각형이 아닙니다.");

	//-------------------------------

	return 0;
}