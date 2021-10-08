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