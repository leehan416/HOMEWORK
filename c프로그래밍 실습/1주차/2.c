int main(void) {

	// 변수 선언
	int height, weight; // 신장(cm), 체중(kg) 
	float bmi; // 비만도 수치
	float value; // 코드 가독성을 위한 변수 : (신장 m 단위)^2

	//-------------------------
  
	// "height? " 출력
	printf ("height? ");
	// height 입력받기
	scanf("%d", &height);
	// "weight? " 출력
	printf ("weight? ");
	// weight 입력받기
	scanf ("%d", &weight);

	// 신장 m 단위 변환 => 제곱
	value  =  (float)height * 0.01 * (float)height * 0.01;
  
	// bmi 계산
	bmi = weight / value;

	// 출력
	printf ("Your bmi is %.1f", bmi);

	//-------------------------

	// 함수 종료
	return 0;
}