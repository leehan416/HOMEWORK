// 2. 세 개의 정수를 입력 받아, 최대값, 최소값 및 평균값을 구하는 프로그램을 작성하시오.
#include<stdio.h>

int main() {
	int num1, num2, num3; // 입력 변수
	int max = 0; // 최댓값
	int min; // 최솟값
	float average; // 평균

	scanf("%d %d %d", &num1, &num2, &num3); // 변수 입력

	//-------------------------------------
	// 최댓값 찾기

	if (max < num1) 
		max = num1;
	if (max < num2)
		max = num2;
	if (max < num3)
		max = num3;

	//-------------------------------------
	// 최솟값 찾기
	min = num1;
	if (min > num2)
		min = num2;
	if (min > num3)
		min = num3;

	//-------------------------------------
	// 평균값 계산

	average = ((float) num1 + (float) num2 + (float) num3) / 3;

	//-------------------------------------
	// 출력

	printf("최대값 : %d\n최소값 : %d\n평균값 : %f", max, min, average);

	return 0;
}