#include <stdio.h>

int main(void) {
	int birth_year;   // 태어난 년도 
	int age;          // 나이 

	//---------------------------------

	// "Birth year? " 출력
	printf("Birth year? ");
	// birth_year 입력받기
	scanf("%d", &birth_year);
	
	//---------------------------------


	// 나이 계산
	age = 2019 - birth_year +1;

	// 만약 나이가 7 미만이라면
	if  (age < 7) printf("유아");
	// 만약 나이가 7 이상 13 미만이라면
	else if ((7 <= age) && (age < 13)) printf("어린이");
	// 만약 나이가 13 이상 20 미만이라면
	else if ((13 <= age) && (age < 20)) printf("청소년");
	// 만약 나이가 20 이상 30 미만이라면
	else if ((20 <= age) && (age < 30)) printf("청년");
	// 만약 나이가 30 이상 60 미만이라면
	else if ((30 <= age) && (age < 60)) printf("중년");
	// 만약 나이가 60 이상이면
	else printf("노년");

	// "입니다." 출력
	printf("입니다.");
	
	//---------------------------------

	return 0;
}