#include <stdio.h>

int main(void) {
	// 변수 선언
	int megabytes; // 용량(메가바이트 단위) 
	float seconds; // 전송시간 (소숫점 3자리까지 표시)

	//--------------------------------------
	
	// "File size in megabytes? " 출력
	printf ("File size in megabytes? ");
	// megabytes 입력받기
	scanf ("%d", &megabytes);

	// 전송시간 계산
	seconds = (float)megabytes * 1024 * 1024 * 8 / 100000000;

	// 시간 출력
	printf("It takes %.3f seconds in 100Mbps Wireless LAN.",seconds);
	
	//--------------------------------------
	
	// 함수 종료
	return 0;
}