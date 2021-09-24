/*
4-2. 2차원 숫자 출력하기
행의 크기(rows)와 열의 크기(columns)를 입력받은 후에, 이 크기만큼의 바둑판 모양의 2차원 공간의 각 칸마다 행 번호(1, 2, ..., width)와 열 번호(1, 2, ..., height)를 곱한 값을 출력하라.

변수는 다음과 같이 사용하라.

	int rows, columns;  // 행의 개수, 열의 개수
	int number;         // 각 칸에 출력하는 값
	int i, j;           // 반복문 사용을 위한 변수 
실행 예)

	rows? 4
	columns? 5
	1  2  3  4  5
	2  4  6  8  10
	3  6  9  12 15
	4  8  12 16 20
*/
#include <stdio.h>

int main(void) {
	int rows, columns;  // 행의 개수, 열의 개수
	int number;         // 각 칸에 출력하는 값
	int i, j;           // 반복문 사용을 위한 변수
	
	// ----------------------
	// 변수 입력
	
	printf("rows? ");
	scanf("%d", &rows);
	printf("columns? ");
	scanf("%d", &columns);

	// ----------------------------

	for (int horizontal = 1; horizontal <= rows; horizontal++) { // 출력을 위한 반복문
		for (int vertical = 1; vertical <= columns; vertical++) {
			if (horizontal == 0) printf("%-3d", vertical); // 입력받은 길이 출력
			else if (vertical == 0) printf("%-3d", horizontal);
			else printf("%-3d", vertical * horizontal); // 결과 출력
		}
		printf("\n"); // 한 행의 출력이 끝나면 줄넘김
	}
	return 0;
}
