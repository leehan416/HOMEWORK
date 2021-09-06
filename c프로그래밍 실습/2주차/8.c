/*
2-8. 국,영,수 과목 점수를 입력받아 총점과 평균을 계산하고, 등급 판정
국어, 영어, 수학 점수를 입력받아 이 점수의 총점과 평균을 계산하고, 각 과목별로 90점 이상이면 성적우수 로 표시하여 출력하라.

단, 총점 = 국어점수 + 영어점수 + 수학점수, 평균 = 총점 / 3.0 으로 계산하라.

변수는 다음과 같이 사용하라.

int kor, eng, math;   // 국어점수, 영어점수, 수학점수
int total;			// 총점
float average;		// 평균점수
int kor, eng, math;   // 국어점수, 영어점수, 수학점수
int total;			// 총점
float average;		// 평균점수
	실행 예)

	국어 점수를 입력하세요 95
	영어 점수를 입력하세요 85
	수학 점수를 입력하세요 88
	입력하신 점수의 총점은 268 이고,
	평균은 89.3 입니다.
	국어점수가 우수합니다.

	국어 점수를 입력하세요 95
	영어 점수를 입력하세요 99
	수학 점수를 입력하세요 94
	입력하신 점수의 총점은 288 이고,
	평균은 96.0 입니다.
	국어점수가 우수합니다.
	영어점수가 우수합니다.
	수학점수가 우수합니다.
*/

#include <stdio.h>

int main(void) {


	int kor, eng, math;   // 국어점수, 영어점수, 수학점수
	int total;            // 총점
	float average;        // 평균점수

	//--------------------------------------
	// 변수 입출력

	printf("국어 점수를 입력하세요 ");
	scanf("%d", &kor);
	printf("영어 점수를 입력하세요 ");
	scanf("%d", &eng);
	printf("수학 점수를 입력하세요 ");
	scanf("%d", &math);
	
	//--------------------------------------
	
	// 총점 계산
	total = math + eng + kor;
	// 총점 출력
	printf("입력하신 점수의 총점은 %d 이고,\n", total);

	// 평균 계산
	average = total / 3.0;
	// 평균 출력
	printf("평균은 %.1f 입니다.\n", average);

	//--------------------------------------

	// 변수들이 90 이상이면 우수합니다 출력하기
	if (kor >= 90) printf("국어점수가 우수합니다.\n");

	if (eng >= 90) printf("영어점수가 우수합니다.\n");
	
	if (math >= 90) printf("수학점수가 우수합니다.");
	
	//--------------------------------------

	return 0;
}