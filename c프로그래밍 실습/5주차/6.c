/*
5-6. 5명의 점수 분석하기
학생 5명의 국어, 영어, 수학 점수를 각각 입력받아 저장한 후에, 다음 항목들을 계산하여 출력하라.

1) 각 과목별 총점과 평균 점수

2) 각 학생별 총점과 평균점수, 평균에 따른 등급

등급은 다음과 같은 기준으로 결정하라.

평균 90이상 : A

평균 80이상 ~ 90미만 : B

평균 70이상 ~ 80미만 : C

평균 60이상 ~ 70미만 : D

평균 60미만 : F

변수는 다음과 같이 사용하라.
 int jumsu[5][3];            // 5명의 3과목 점수를 저장하고 있는 2차원 배열 
 int sum_student[5];         // 학생별 총점
 float average_student[5];   // 학생별 평균
 char grade[5];              // 학생별 등급 
 int sum_class[3];           // 과목별 총점
 float average_class[3];     // 과목별 평균
 int i, j;                   // 반복문을 위한 변수 
실행 예)
	1번 학생 국어, 영어, 수학 점수? 85 95 75
	2번 학생 국어, 영어, 수학 점수? 90 80 70
	3번 학생 국어, 영어, 수학 점수? 65 85 75
	4번 학생 국어, 영어, 수학 점수? 60 70 80
	5번 학생 국어, 영어, 수학 점수? 60 50 60
	1) 각 과목별 총점과 평균점수
	국어 점수의 총점은 360 평균은 72.0
	영어 점수의 총점은 380 평균은 76.0
	수학 점수의 총점은 360 평균은 72.0
	2) 각 학생별 총점과 평균점수, 평균에 따른 등급
	1번 학생의 총점은 255 평균은 85.0(등급 B)
	2번 학생의 총점은 240 평균은 80.0(등급 B)
	3번 학생의 총점은 225 평균은 75.0(등급 C)
	4번 학생의 총점은 210 평균은 70.0(등급 C)
	5번 학생의 총점은 170 평균은 56.7(등급 F)
*/
#include <stdio.h>

int main(void) {
	int jumsu[5][3];            // 5명의 3과목 점수를 저장하고 있는 2차원 배열 
	int sum_student[5] = {0, }; // 학생별 총점
	float average_student[5];   // 학생별 평균
	char grade[5];              // 학생별 등급 
	int sum_class[3] = {0, };   // 과목별 총점
	float average_class[3];	    // 과목별 평균
	int i, j;                   // 반복문을 위한 변수 

	// 입력
	for (i = 0; i < 5; i++) {
		printf("%d번 학생 국어, 영어, 수학 점수? ", i + 1);
		scanf("%d %d %d", &jumsu[i][0], &jumsu[i][1], &jumsu[i][2]);
		for (j = 0; j < 3; j++) {
			sum_class[j] += jumsu[i][j];
			sum_student[i] += jumsu[i][j];
		}
	}

	//연산
	for (i = 0; i < 3; i++)   // 과목 평균
		average_class[i] = sum_class[i] / 5.0;
	for (i = 0; i < 5; i++)
		average_student[i] = sum_student[i] / 3.0;
	for (i = 0; i < 5; i++) {
		float value = average_student[i];
		
		// 등급 지정
		if (90 <= value)
			grade[i] = 'A';
		else if (80 <= value && value < 90)
			grade[i] = 'B';
		else if (70 <= value && value < 80)
			grade[i] = 'C';
		else if (60 <= value && value < 70)
			grade[i] = 'D';
		else
			grade[i] = 'F';
	}

	//출력
	printf("1) 각 과목별 총점과 평균점수\n");
	printf("국어 점수의 총점은 %d 평균은 %.1f\n", sum_class[0], average_class[0]);
	printf("영어 점수의 총점은 %d 평균은 %.1f\n", sum_class[1], average_class[1]);
	printf("수학 점수의 총점은 %d 평균은 %.1f\n", sum_class[2], average_class[2]);

	printf("2) 각 학생별 총점과 평균점수, 평균에 따른 등급\n");
	for (i = 0; i < 5; i++)
		printf("%d번 학생의 총점은 %d 평균은 %.1f(등급 %c)\n", i + 1, sum_student[i], average_student[i], grade[i]);

	return 0;
}