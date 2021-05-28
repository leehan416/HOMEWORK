#include <Servo.h> // Servo 모터를 활용하기 위한 라이브러리 설정
//----------------------------------------
Servo ServoR; // 우측 Servo 모터 선언 
Servo ServoL; // 좌측 Servo 모터 선언
//----------------------------------------
int goalAngle = 180; // 목표 각도 변수 (default = 180)
int nowAngle = 30; // 현재 각도 변수 (default = 30)
int perMove = 5; // 각 이동당 이동할 각도 
//----------------------------------------
int angleList[] = {30, 50, 70, 90}; // 각도 리스트 
//----------------------------------------
bool timeVer = false; // 주기 버전인가?
int timeSum = 0; // 시간 체크를 위한 변수 (각 프레임당 1씩 더하여 시간 연산)
int timeVal = 100; // 변경 주기 시간 변수 
//----------------------------------------
int type = 0; //모터 활동 변수 | 0 = 정지 1 = 상승 2 = 하강 
//----------------------------------------
void setup() { 
	for (int a = 2; a < 7; a++) // 핀모드 세팅 2 ~ 6
		pinMode(a, INPUT); 
//----------------------------------------
    //Servo모터 핀번호 설정
	ServoR.attach(8); 
	ServoL.attach(9);    
//----------------------------------------
    // Servo초기 각도 설정
	ServoR.write (nowAngle); 
	ServoL.write (nowAngle);
}
//----------------------------------------
void loop() {
	for (int a = 0; a < 5; a++) { // 버튼 클릭 검사 0 ~ 3 = 각도버전 | 4 = 주기 버전 
		if (digitalRead(a + 2) == HIGH) { // 클릭되었다면
			if (a == 4) { // 주기 버전
				if (!timeVer) { // 주기 버전이 아니라면
					goalAngle = RandomSet(); // 초기 세팅
					timeVer = true;
				}
			} else { // 각 버전
				timever = false; // 주기 버전과 충돌 방지
				if (type > 0) // 모터가 작업중이라면
					return; // 함수 종료 
				goalAngle = angleList[a]; // 각 버튼에 지정되어 있는 각도로 초기화 
				type = TypeSet(); // 상승 하강 작업 세팅
			}
		}
	}
//----------------------------------------
	if (timeVer) { // 주기 버전 시간 검사 
		timeSum ++; // 프레임 증가
		if (timeSum >= timeVal) { // 지정한 시간이 되었다면
			goalAngle = RandomSet(); // 각도 변경
			timeSum = 0; // 시간 초기화
			type = TypeSet(); // 상승 하강 작업 세팅
		}
	}
//----------------------------------------
	if (type > 0) { // 모터가 작동중으로 세팅되어 있다면
		if (type == 1) { // 상승
			if (goalAngle <= nowAngle)  // 목표에 도달했다면
				type = 0;//작동중지
			else  // 그렇지 않다면
				nowAngle += perMove; // 모터 작동	
		} else { // 하강
			if (goalAngle >= nowAngle) // 목표에 도달했다면
				type = 0; // 작동중지
			else // 그렇지 않다면
				nowAngle -= perMove; // 모터 작동
		}
//----------------------------------------
        //각 이동
		ServoL.write (nowAngle);
		ServoR.write (nowAngle);
		delay(100); 
	}
}
//----------------------------------------
int RandomSet() { // 랜덤 활용 함수
	int a  = 0; // return할 변수
	while (true) { // 이전 각도와 다른 각도를 return 하기 위한 반복문
		a = angleList[random(0, 3)];
		if (a != nowAngle) {
			return a; 
		}
	}
    return 0;
}
int TypeSet() { // 어느 방향으로 작동해야하는지 설정하는 함수
	if (nowAngle < goalAngle) // 상승해야한다면
		return  1;
	else // 하강해야 한다면
		return  2;
	return 0;
}