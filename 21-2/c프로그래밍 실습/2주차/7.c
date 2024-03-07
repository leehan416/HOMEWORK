#include <stdio.h>

int main(void) {

	int month, day;  // 월, 일
	int day_count = 0;  // 1년 중 날 수 

	//---------------------------------

	// "Month? " 출력
	printf("Month? ");
	// month 입력받기
	scanf("%d", &month);
	// "Day? " 출력
	printf("Day? ");
	// day 입력받기
	scanf("%d", &day);

	//---------------------------------
	// 잘못된 입력 검사
	if (((1 > month) || (month >= 13)) || ((day < 0) || (31 < day))) {
		printf("잘못 입력하셨습니다.");
		return 0;
	}

	if ((month == 2 )&& (day > 28)) {
		printf("잘못 입력하셨습니다.");
		return 0;
	} else if (((month % 2 == 0) && (month <= 6)) || ((month % 2 == 1) && (9 <= month))) {
		if (day > 30) {
			printf("잘못 입력하셨습니다.");
			return 0;
		}
	}
	//---------------------------------

	// 날짜 계산
	for (int i = 1; i < month; i++) {
		if (i == 2) {
			day_count += 28;
		} else {
			if (((i % 2 == 1) && (i <= 7)) || ((i % 2 == 0) && (8 <= i)))
				day_count += 31;
			else if (((i % 2 == 0) && (i <= 6)) || ((i % 2 == 1) && (9 <= i)))
				day_count += 30;
		}
	}

	// 날짜 출력
	printf("이 날짜는 1년 중 %d번째 날에 해당됩니다.", day_count + day);
		
	//---------------------------------

	return 0;
}