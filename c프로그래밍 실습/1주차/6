/*
1-6. 날수를 입력받아 시,분,초 계산
날 수를 입력받아 이 날 수에 해당되는 기간을 시간, 분, 초로 각각 환산한 값을 계산하여 출력하라.

단, 계산식은 다음과 같다.

시 = 날 수 * 24

분 = 날 수 24 60

초 = 날 수 24 60 * 60

변수는 다음과 같이 사용하라.

int days;     // 입력받은 날 수 
int hours;    // 환산한 시간 
int minutes;  // 환산한 분 
int seconds;  // 환산한 초 

실행 예)

	Days? 25
	25 days is 600 hours.
	25 days is 36000 minutes.
	25 days is 2160000 seconds.
*/

#include <stdio.h>

int main(void) {
	//변수 선언
	int days;        // 입력받은 날 수 
	int hours;       // 환산한 시간 
	int minutes;     // 환산한 분 
	int seconds;     // 환산한 초 

	//------------------

	// "Days? " 출력
	printf ("Days? ");
	// days 입력받기
	scanf("%d", &days);
	// 시간 계산
	hours = days * 24;
	// 분 계산
	minutes = hours * 60;
	// 초 계산
	seconds = minutes * 60;
	//결과 출력 
	printf ("%d days is %d hours.\n",days,hours);
	printf ("%d days is %d minutes.\n",days,minutes);
	printf ("%d days is %d seconds.\n",days,seconds);
	
	//------------------
	
	// 함수 종료 
	return 0;
}