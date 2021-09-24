/*
4-5. 여러 가족의 연령대별 숫자를 기호로 표시하기
가족 수를 입력받고 각 가족 별로 아이, 어른, 노인 수를 입력받아

각각을 @, #, $ 기호로 표현하고, 가족 수 별로 입력이 끝나면

전체 아이, 어른, 노인의 수를 기호로 출력 하라

변수는 다음과 같이 사용하라.
	int family;                                // 총 가족  
	int children, adult, senior;               // 가족 별 아이, 어른, 노인 수
	int all_children, all_adult, all_senior;   // 아이, 어른, 노인의 합계
	int i, j;  
실행 예)
	전체 가족수는 ? 2
	1번 가족의 아이, 어른, 노인의 숫자는? 1 2 3
	@ ## $$$
	2번 가족의 아이, 어른, 노인의 숫자는? 2 2 1
	@@ ## $
	모든 가족들의 숫자는 다음과 같습니다.
	@@@ #### $$$$
*/

#include <stdio.h>

int main(void) {
	int family;                                            // 총 가족
	int children, adult, senior;                           // 가족 별 아이, 어른, 노인 수
	int all_children = 0, all_adult = 0, all_senior = 0;   // 아이, 어른, 노인의 합계
	int i, j;                                              // 반복문 사용을 위한 변수
	
	// 초기 변수 입력
	printf("전체 가족수는? ");
	scanf("%d", &family);

	// 입력을 위한 반복문
	for (i = 1; i <= family; i++) {
		printf("%d번 가족의 아이, 어른, 노인의 숫자는? ", i);
		scanf("%d %d %d", &children, &adult, &senior);
		// 변수에 적용
		all_adult += adult;
		all_senior += senior;
		all_children += children;

		//조건에 맞추어 출력
		for (j = 0; j < children; j++) printf("@"); 
		if (children > 0)printf(" ");
		for (j = 0; j < adult; j++) printf("#");
		if (adult > 0)printf(" ");
		for (j = 0; j < senior; j++) printf("$");
		printf("\n"); // 줄 바꿈
	}
	// 결과 출력
	printf("모든 가족들의 숫자는 다음과 같습니다.\n");
	for (j = 0; j < all_children; j++) printf("@");
	if (all_children > 0) printf(" ");
	for (j = 0; j < all_adult; j++) printf("#");
	if (all_adult > 0) printf(" ");
	for (j = 0; j < all_senior; j++) printf("$");

	return 0;
}