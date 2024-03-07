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
