/*
2-1. 나이 계산 및 미성년자 판정
태어난 년도를 입력받아 나이를 계산한 후, 미성년자인지 여부를 판정하여 그 결과를 출력하라.

단, 나이 = 올해년도 – 태어난 년도 + 1 로 계산하고 나이가 20세 미만인 경우, 미성년자로 판정한다.

변수는 다음과 같이 사용하라.

int birth_year;  // 태어난 년도
int age;         // 나이 
int birth_year;  // 태어난 년도
int age;         // 나이 

	실행 예)

	Birth year? 1980
	미성년자가 아닙니다.

	Birth year? 2005
	미성년자입니다.
*/

#include <stdio.h>

int main(void) {

	int birth_year;	// 태어난 년도
	int age;        // 나이 

	//---------------------------
	// "Birth year? " 출력
	printf("Birth year? ");
	// birth_year 입력받기
	scanf("%d",&birth_year);
  
	// 나이 계산
	age = 2021 - birth_year + 1; 

	// 만약 나이가 20 이상이라면
	if (age < 20) printf("미성년자입니다.");
	// 그렇지 않다면  
	else printf("미성년자가 아닙니다.");
	
	//---------------------------

	return 0;
}
