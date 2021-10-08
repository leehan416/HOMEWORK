#include <stdio.h>
#include <math.h>

int main(void) {
	int height[10], weight[10]; // 10명의 신장(cm), 체중(kg)
	float bmi[10];              // 10명의 비만도 수치
	int count = 0;              // 비만인 사람의 숫자
	int i;                      // 반복문을 위한 변수  

	// 변수 입력
	for (i = 0; i < 10; i++) {
		printf("%d번째 사람의 신장과 체중? ", i + 1);
		scanf("%d %d", &height[i], &weight[i]);
		
		// 입력 이후 연산하여 배열에 저장
		bmi[i] = (float) weight[i] / pow((float) height[i] * 0.01, 2);
	}
	// linear search
	for (int i = 0; i < 10; i++) {
		if (bmi[i] >= 25) { // 만약 비만이라면
			printf("%d번째 사람은 비만\n", i + 1);
			count++; // 변수 증가
		}
	}

	// 결과 출력
	printf("\n총 %d명의 사람이 비만", count);
	
	return 0;
}