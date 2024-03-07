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
