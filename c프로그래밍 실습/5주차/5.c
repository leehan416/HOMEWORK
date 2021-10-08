#include <stdio.h>

int main(void) {
	int monthdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int month, day;    // 입력받은 월, 일
	int day_count = 0; // 1년 중 날 수
	int i;             // 반복문을 위한 변수

	// 변수 입력
	printf("Month? ");
	scanf("%d", &month);
	printf("Day? ");
	scanf("%d", &day);

	// 종료 조건 검사
	if (month > 12) { // 바로 아래 조건문에서 null exception 방지로 먼저 검사
		printf("잘못 입력하셨습니다.");
		return 0;
	}
	if (monthdays[month - 1] <= day) {
		printf("잘못 입력하셨습니다.");
		return 0;
	}


	// 연산 반복문
	for (i = 0; i < month - 1; i++)
		day_count += monthdays[i];

	// 날자 더하기
	day_count += day;
	
	// 결과 출력
	printf("이 날짜는 1년 중 %d번째 날에 해당", day_count);
	return 0;
}