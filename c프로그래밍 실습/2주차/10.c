/*
2-10. 3개의 수 중 최댓값과 최솟값 구하기
숫자를 3개 입력받은 후, 이 숫자 중에서 가장 큰 수, 가장 작은 수를 출력하라.

변수는 다음과 같이 사용하라.

int num1, num2, num3;   // 첫 번째 숫자, 두 번째 숫자, 세 번째 숫자 
int max_num, min_num;   // 가장 큰 숫자, 가장 작은 숫자 
int num1, num2, num3;   // 첫 번째 숫자, 두 번째 숫자, 세 번째 숫자 
int max_num, min_num;   // 가장 큰 숫자, 가장 작은 숫자 

	실행 예)

	첫번째 숫자? 20
	두번째 숫자? 80
	세번째 숫자? 50
	가장 큰 수는 80이고, 가장 작은 수는 20입니다.

	첫번째 숫자? 50
	두번째 숫자? 50
	세번째 숫자? 50
	가장 큰 수는 50이고, 가장 작은 수는 50입니다.
*/

#include <stdio.h>

int main(void) {


	int num1, num2, num3;   // 첫 번째 숫자, 두 번째 숫자, 세 번째 숫자 
	int max_num, min_num;   // 가장 큰 숫자, 가장 작은 숫자 

	max_num = 0;
	min_num = -99999999;

	//-----------------------------
	// 각각 입력받고 검사

	printf("첫번째 숫자? ");
	scanf("%d", &num1);
	max_num = num1; // 최댓값 설정
	min_num = num1; // 최솟값 설정

	printf("두번째 숫자? ");
	scanf("%d", &num2);

	if (max_num < num2)	max_num = num2;
	else if (min_num > num2) min_num = num2;

	printf("세번째 숫자? ");
	scanf("%d", &num3);

	if (max_num < num3) max_num = num3;
	else if (min_num > num3) min_num = num3;

	//-----------------------------
	// 결과 출력

	printf("가장 큰 수는 %d이고, 가장 작은 수는 %d입니다.", max_num, min_num);

	//-----------------------------
		
	return 0;
}