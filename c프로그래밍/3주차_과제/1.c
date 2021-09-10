/*
1.섭씨(Celsius) 온도를 화씨(Fahrenheit) 온도로 변환하는 프로그램을 작성 하시오.
입력 : 섭씨 온도의 값
출력 : 입력 값에 대한 화씨 온도 값
*/

//℉ =℃ * 1.8000+ 32.0032
#include <stdio.h>

int main() {
	double temperature; // 온도 변수
	printf("섭씨 온도를 입력하세요 : "); 
	scanf("%lf", &temperature); // 온도 입력받기
	printf("%lf", temperature * 1.8000 + 32.0032); // 온도 계산하여 출력
}