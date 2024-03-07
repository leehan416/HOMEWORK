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