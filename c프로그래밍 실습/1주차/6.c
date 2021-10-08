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