/*
5-9. 5명의 점수 채점하고 등급매기기
다음과 같이 5명의 학생들에게 10문제의 답을 입력받아, 이를 채점하여 등급을 매기는 작업을 하는 프로그램을 작성하라. 학생별로 10개씩의 답안을 입력받은 후에, 각 등급별 학생 이름과 인원수를 출력하라.

단, 10문제의 정답은 미리 코드에 제시된 그대로 사용하라.

등급은 다음과 같이 결정한다.

1st : 9~10문제 맞춘 경우

2nd : 7~8문제 맞춘 경우

Fail : 6문제 이하로 맞춘 경우

변수는 제시된 것을 사용하되, 부득이한 경우 용도를 명시하고 추가해도 좋다.

실행 예)
	Enter James's sheet >>  1 2 3 4 1 2 3 4 3 2
	Enter David's sheet >>  2 3 1 4 1 2 3 4 3 2
	Grade result
	1st : James Peter (2)
	2nd : David (1)
	Fail : Simon Jason (2)
*/
#include <stdio.h>

int main(void) {
	int i, j; // 반복문을 위한 변수
	int jumsu; // 점수 게산용 점수
	int count; // 인원수 계산용 변수
	char names[5][20] = {"James", "David", "Simon", "Peter", "Jason"}; // 학생 이름 
	int sheet[5][10]; // 학생별 답안내용
	int answer[10] = {1, 2, 3, 4, 1, 2, 3, 4, 3, 2}; // 정답순서
	int grade[5]; // 학생별 등급

	for (i = 0; i < 5; i++) {
		printf("Enter %s's sheet >> ", names[i]);
		for (j = 0; j < 10; j++)
			scanf("%d", &sheet[i][j]); //i번째학생의답안10개입력
	}


//-----------------------------------------------------
// 이 부분에 코드를 작성할 것!

	for (i = 0; i < 5; i++) { // 답안 검사, 결과 정리 반복문
		count = 0;
		for (j = 0; j < 10; j++) { // 답안 검사
			if (sheet[i][j] == answer[j]) 
				count++;
		
			// 결과 입력
			if (9 <= count) 
				grade[i] = 1;
			else if (7 <= count && count < 9) 
				grade[i] = 2;
			else 
				grade[i] = 3;
		}
	}

	// 결과 출력
	printf("\nGrade result\n"); 
	for (j = 0; j < 3; j++) {
		switch (j) {
			case 0:
				printf("1st : ");
				break;
			case 1:
				printf("2nd : ");
				break;
			case 2:
				printf("Fail : ");
				break;
		}

		count = 0;
		for (i = 0; i < 5; i++) {
			if (grade[i] == j + 1) {
				count++;
				printf("%s ", names[i]);
			}
		}
		printf("(%d)\n", count);
	}

//-----------------------------------------------------

	return 0;
}