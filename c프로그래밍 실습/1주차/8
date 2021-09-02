/*
1-8. 파일 용량을 입력받아 무선랜 전송시간 계산
파일 용량을 메가바이트 단위로 입력받아 이 크기의 파일을 100Mbps 무선랜으로 전송할 때 걸리는 시간을 계산하여 출력하라.

단, 계산방법은 다음과 같다.

100Mbps 무선랜의 전송속도는 초당 1억비트이다.

1메가바이트는 1024*1024 바이트이다. 1바이트는 8비트이다.

전송시간 = 파일의 총비트수 / 전송속도 변수는 다음과 같이 사용하라.

int megabytes; // 용량(메가바이트 단위) 
float seconds; // 전송시간 (소숫점 3자리까지 표시)
int megabytes; // 용량(메가바이트 단위) 
float seconds; // 전송시간 (소숫점 3자리까지 표시)
실행 예)

	File size in megabytes? 500
	It takes 41.943 seconds in 100Mbps Wireless LAN.
*/
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