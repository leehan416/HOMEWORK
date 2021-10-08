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