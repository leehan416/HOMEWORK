/*
5-1. 여러 사람들의 연령대 숫자 세기
최대 100명까지 사람들의 태어난 년도를 입력받아 그 값을 배열로 저장하되, 올해보다 큰 년도가 입력되기 전까지 태어난 년도를 반복하여 입력받도록 하라.

반복이 끝나면 지금까지 입력된 사람들의 각자 나이를 계산하여 출력하고, 나이에 따라 유아, 어린이, 청소년, 청년, 중년, 노년 여부를 판정하여 이 중 에 유아, 어린이, 청소년, 청년, 중년, 노년이 각각 몇 명인지 출력하라.
단, 나이 = 올해년도 – 태어난 년도 + 1 로 계산하고 연령대 구분은 다음과 같이 판정한다.

7세 미만 : 유아,
7세 이상 ~ 13세미만 : 어린이,
13세 이상 ~ 20세 미만 : 청소년,
20세 이상 ~ 30세 미만 : 청년,
30세 이상 ~ 60세 미만 : 중년,
60세 이상 : 노년

변수는 다음과 같이 사용하라.
	int birth_year;       // 입력받은 태어난 년도
	int year[100];        // 각 사람들의 생년 (최대 100명) 
	int count_person;     // 입력된 인원 수
	int count_baby;       // 유아 수
	int count_child;      // 어린이 수
	int count_youth;      // 청소년 수
	int count_young;      // 청년 수
	int count_adult;      // 중년 수
	int count_old;        // 노년 수
	int i;                // 반복문을 위한 변수 

출력 예)
	1번째 사람의 태어난 년도를 입력하시오.1996
	2번째 사람의 태어난 년도를 입력하시오. 2006
	3번째 사람의 태어난 년도를 입력하시오. 2009
	4번째 사람의 태어난 년도를 입력하시오. 1983
	5번째 사람의 태어난 년도를 입력하시오. 1957
	6번째 사람의 태어난 년도를 입력하시오. 1937
	7번째 사람의 태어난 년도를 입력하시오. 1952
	8번째 사람의 태어난 년도를 입력하시오. 1969
	9번째 사람의 태어난 년도를 입력하시오. 1981
	10번째 사람의 태어난 년도를 입력하시오. 2222
	1번째 사람의 나이는 26입니다.
	2번째 사람의 나이는 16입니다.
	3번째 사람의 나이는 13입니다.
	4번째 사람의 나이는 39입니다.
	5번째 사람의 나이는 65입니다.
	6번째 사람의 나이는 85입니다.
	7번째 사람의 나이는 70입니다.
	8번째 사람의 나이는 53입니다.
	9번째 사람의 나이는 41입니다.
	유아는 0명입니다.
	어린이는 0명 입니다.
	청소년은 2명 입니다.
	청년은 1명 입니다.
	중년은 3명 입니다.
	노년은 3명 입니다.
*/
#include <stdio.h>

int main(void) {
	int birth_year = 0;   // 입력받은 태어난 년도
	int year[100];        // 각 사람들의 생년 (최대 100명)
	int count_person = 0; // 입력된 인원 수
	int count_baby = 0;   // 유아 수
	int count_child = 0;  // 어린이 수
	int count_youth = 0;  // 청소년 수
	int count_young = 0;  // 청년 수
	int count_adult = 0;  // 중년 수
	int count_old = 0;    // 노년 수
	int i;                // 반복문을 위한 변수

	for (i = 0; birth_year <= 2021; i++) { // 2021 초과의 숫자가 입력될 때 까지 반복
		// 변수 입력
		printf("%d번째 사람의 태어난 년도를 입력하시오. ", i + 1); 
		scanf("%d", &birth_year);
		
		// 배열에 저장
		year[i] = birth_year;
		
		if (birth_year <= 2021) // 만약 2021 초과의 숫자가 아니라면
			count_person++; 
	}

	for (i = 0; i < count_person; i++) { // 출력 반복문
		int age = 2021 - year[i] + 1; // 나이 연산

		// 출력 이전에 변수 증가
		if (age < 7) // 유아
			count_baby++;
		else if (7 <= age && age < 13) // 어린이
			count_child++;
		else if (13 <= age && age < 20) // 청소년 
			count_youth++;
		else if (20 <= age && age < 30) //청년
			count_young++;
		else if (30 <= age && age < 60) //중년
			count_adult++;
		else // 노년
			count_old++;
		printf("%d번째 사람의 나이는 %d입니다.\n", i + 1, age); // 결과 출력
	}

	// 결과 출력
	printf("유아는 %d명입니다.\n", count_baby);
	printf("어린이는 %d명입니다.\n", count_child);
	printf("청소년은 %d명입니다.\n", count_youth);
	printf("청년은 %d명입니다.\n", count_young);
	printf("중년은 %d명입니다.\n", count_adult);
	printf("노년은 %d명입니다.", count_old);
	
	return 0;
}