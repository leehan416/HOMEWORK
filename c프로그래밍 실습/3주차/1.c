/*
3-1. 미성년자 숫자 세기
가족이 몇 명인지 입력받은 후, 그 인원 수 만큼 태어난 년도를 입력받으면서, 나이를 계산하여 미성년자가 모두 몇 명인지 출력 하라.

단, 나이 = 올해년도 – 태어난 년도 + 1 로 계산하고 나이가 20세 미만인 경우, 미성년자로 판정한다.

변수는 다음과 같이 사용하라.
	int count_all;    // 가족 인원수
	int count_young;  // 미성년자의 수
	int birth_year;   // 태어난 년도
	int age;          // 나이
	int i;            // 반복문을 위한 변수 

실행 예)
	가족 인원수? 5
	Birth year? 1955
	Birth year? 1960
	Birth year? 1985
	Birth year? 1990
	Birth year? 2005
	가족들 중 미성년자는 모두 1명입니다.
*/

#include <stdio.h>

int main(void) {
	int count_all;       // 가족 인원수
	int count_young = 0; // 미성년자의 수
	int birth_year;      // 태어난 년도
	int age;             // 나이
	int i = 0;           // 반복문을 위한 변수
	
	//----------------------------------
	// 변수 입출력
	printf("가족 인원수? ");
	scanf("%d", &count_all);

	//----------------------------------
	// 입력 받는 반복문
	while (i < count_all) {
		//------------------------------
		// 변수 입력
		printf("Birth year? ");
		scanf("%d", &birth_year);
		//------------------------------
		age = 2021 - birth_year + 1; // 나이 연산
		if (age < 20) count_young++; // 미성년자면 변수 1증가
		i++; // index 증가
	}

	//----------------------------------
	// 결과 출력

	printf("가족들 중 미성년자는 모두 %d명입니다.", count_young);
	
	//----------------------------------
	return 0;
}