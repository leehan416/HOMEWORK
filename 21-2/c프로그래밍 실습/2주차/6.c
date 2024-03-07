#include <stdio.h>

int main(void) {

	float m2_area;      // 면적 (제곱미터) 
	float pyung_area;   // 면적 (평수) 

	//------------------------------------

	// "아파트의 분양 면적(제곱미터)을 입력하시오. " 출력
	printf("아파트의 분양 면적(제곱미터)을 입력하시오. ");
	// m2_area 입력받기
	scanf("%f", &m2_area);

	// 면적 계산
	pyung_area = m2_area / 3.305;
	// 면적 출력
	printf("아파트의 평형은 %.1f 입니다.\n",pyung_area);

	// 만약 면적이 15 미만이라면
	if (pyung_area < 15) printf("소형 ");
	// 만약 면적이 15 이상 30 미만이라면
	else if ((15 <= pyung_area) && (pyung_area < 30)) printf("중소형 ");
	// 만약 면적이 30 이상 50 미만이라면
	else if ((30 <= pyung_area) && (pyung_area < 50)) printf("중형 ");
	// 만약 면적이 50 이상이라면
	else printf("대형 ");

	// "아파트 입니다." 출력
	printf("아파트 입니다.");

	//------------------------------------
	
	return 0;

}