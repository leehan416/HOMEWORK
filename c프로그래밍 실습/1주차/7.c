
/*
1-7. 국,영,수 과목 점수를 입력받아 총점과 평균 계산
국어, 영어, 수학 점수를 입력받아 이 점수의 총점과 평균을 계산하여 출력하라.

단, 총점 = 국어점수 + 영어점수 + 수학점수,

평균 = 총점 / 3.0 으로 계산하라.

변수는 다음과 같이 사용하라.

int kor, eng, math;   // 국어점수, 영어점수, 수학점수 
int total;            // 총점
float average;        // 평균점수 
int kor, eng, math;   // 국어점수, 영어점수, 수학점수 
int total;            // 총점
float average;        // 평균점수 
실행 예)

	Kor? 85
	Eng? 95
	Math? 80
	total is 260,
	average is 86.7.

*/
#include <stdio.h>

int main(void) {
	// 변수 선언
	int kor, eng, math;  // 국어점수, 영어점수, 수학점수 
	int total;           // 총점
	float average;       // 평균점수 
	
	//---------------------------
	
	// "Kor? " 출력
	printf ("Kor? ");
	// kor 입력받기
	scanf("%d",&kor);
	
	// "Eng? " 출력
	printf ("Eng? ");
	// eng 입력받기
	scanf("%d",&eng);

	// "Math? " 출력
	printf ("Math? ");
	// math 입력받기
	scanf("%d",&math);
	
	// 총점 계산
	total = kor + eng + math;
	// 총점 출력
	printf ("total is %d, ", total);
	
	// 평균 계산
	average = total / 3.0;
	
	// 평균 출력
	printf ("average is %.1f.", average);
	
		//__________________________
		/*
		테스트에서 에러.
		printf ("\naverage is %.1f.", average);
		*/
		//__________________________

	//---------------------------

	// 함수 종료
	return 0;
}