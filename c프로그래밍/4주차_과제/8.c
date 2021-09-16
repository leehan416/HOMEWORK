#include <stdio.h>
int main() {
	int num; // 입력 받을 변수
	scanf("%d", &num); // 입력
	for (int i = 1; i < 10; i++) { // 반복
		printf("%d x %d = %d\n", num, i, i * num); // 구구단 출력
	}
	return 0; // 함수 종료
}