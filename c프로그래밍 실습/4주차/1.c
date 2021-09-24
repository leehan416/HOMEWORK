/*
4-1. 생각한 숫자 맞추기
사용자가 임의로 숫자(1~100사이) 하나를 생각한 다음, 컴퓨터가 맞추도록 하는 프로그램을 작성하라. 프로그램의 수행방식은 다음과 같다.

1부터 100까지의 숫자 중 하나를 맞추는 것이므로, 처음에 50부터 시작하여 맞춰 나간다.

더 큰 수라면 사용자가 1을, 더 작은 수라면 2를, 맞추었으면 0을 입력한다.

1,2 이외의 숫자를 입력하면 반복을 종료한 후, 지금까지 시도한 횟수를 출력한다.

아래 실행 예는 사용자가 33을 생각한 후에 컴퓨터가 답을 맞춰가는 과정을 보여준다.

실행 예)
	How about 50? (try more : 1, try less : 2, right : 0)  2
	How about 25? (try more : 1, try less : 2, right : 0)  1
	How about 37? (try more : 1, try less : 2, right : 0)  2
	How about 31? (try more : 1, try less : 2, right : 0)  1
	How about 34? (try more : 1, try less : 2, right : 0)  2
	How about 33? (try more : 1, try less : 2, right : 0)  0
6 trie
*/
#include<stdio.h>
#include <math.h>

int main(void) {
	// 변수 선언
	int input, i;
	int goal = 50;
	int min = 0;
	int max = 100;
	//------------------------------------------
	for (i = 1;; i++) {
		// 입력받기
		printf("How about %d? (try more : 1, try less : 2, right : 0) ", goal);
		scanf("%d", &input);
		
		if (input == 1) min = goal; // 최솟값 재설정
		else if (input == 2) max = goal; // 최댓값 재설정
		else if (input == 0) break; // 종료
		goal = (min + max) / 2; // 중간값으로 초기화
		if (((float)min + (float)max) / 2.0 - goal >= 0.5) goal++; // 반올림
	}
	printf("%d tried.", i); // 결과 출력

	return 0;
}