#include <stdio.h>

int main(void) {

	//변수 선언
	int birth_year = 0; // 태어난 년도 
	int age = 0; // 나이 

	//---------------------------

	// "Birth year?" 를 출력한다.
	printf ("Birth year? ");
	// 태어난 년도를 입력 받는다
	scanf ("%d", &birth_year);
	// 나이를 계산한다
	age = 2021 - birth_year + 1;
	// 나이를 출력한다
	printf("%d", age);

	//---------------------------

	// 함수 종료
	return 0;
}