int motorPin = 9;// 모터 동작을 위한 핀 지정
void setup() {
    pinMode(motorPin, OUTPUT);//핀 모드 세팅
    Serial.begin(9600);//통신 속도 설정
    while (!Serial);// 통신 가능한 시점까지 대기
    Serial.println("Speed0to255");// 통신 가능한 시점이 되었을 때 출력
}
void loop() {
    if (Serial.available()) {// 만약 입력이 있다면
        int speed = Serial.parseInt();// 변수에 저장한다
        if ((speed > 0) && (speed <= 255)) {// 만약 0~255 사이의 값이라면
            analogWrite(motorPin, speed);// 모터를 입력 받은 값 만큼 작동시킨다
        } else if (speed > 255) {// 만약 256 이상의 값이 입력되었다면,
            analogWrite(motorPin, 0);// 모터의 동력을 차단한다.
        }
    }
}