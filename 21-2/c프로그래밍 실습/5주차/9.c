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