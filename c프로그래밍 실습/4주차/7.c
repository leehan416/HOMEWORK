/*
4-7. 입력한 숫자 크기의 높이를 갖는 우직각 삼각형 출력하기
높이와 여백을 정하는 숫자 두 개를 입력받은 후에 이 숫자만큼의 높이와 왼쪽 여백을 갖는 우직각 삼각형을 '*' 문자 로 화면에 출력하라.

예를 들어 10을 입력하면 첫 줄에는 1개, 2번째 줄에는 2개, 3번째 줄에는 3 개, .. 10번째 줄에는 10개의 '*' 을 왼쪽 여백을 가진 우측 정렬된 모습으로 출력하는 것이다.

변수는 다음과 같이 사용하라.
	int height;     // 입력받은 높이
	int blank;      // 입력받은 여백 크기
실행 예)
	height? 4
	blank? 2
	*
	**
	***
	****
*/
#include <stdio.h>

int main(void) {
	int height;   // 입력받은 높이
	int blank;	// 입력받은 여백 크기
	int i, j;	 // 반복문 사용을 위한 변수

	// 변수 입력
	printf("height? ");
	scanf("%d", &height);

	printf("blank? ");
	scanf("%d", &blank);

	// 결과 출력
	for (i = 1; i <= height; i++) { // 열
		// 행
		for (j = 0; j < blank; j++) // 여백 출력
			printf(" ");
		for (j = 0; j < height - i; j++) // 삼각형 탑을 쌓기 위한 여백 출력
			printf(" ");
		for (j = i; j > 0; j--) // 별 출력
			printf("*");

		printf("\n"); // 한 행이 끝나면 줄 바꿈
	}

	return 0;
}