#include <stdio.h>

int main(void) {
	int length;  // 입력받은 정사각형 한 변의 길이 
	int i, j;    // 반복문 사용을 위한 변수 
	
	// 변수 입력
	printf("정사각형의 크기를 입력하시오. ");
	scanf("%d",&length);
	
	// 결과 출력
	for (i = 0; i < length; i++) { // 열
		for (j = 0 ; j < length; j++) { // 행
			printf("#");
		}
		printf("\n"); // 한 행이 끝나면 줄바꿈
	}

	return 0;
}