int distance;
int triggerPin = 12;
int echoPin= 11;
int duration;
int ledPin = 13;//led 핀 제어를 위한 변수
int r;//led 제어를 위한 변수
void setup(){
    Serial.begin(9600);
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(ledPin, OUTPUT);//led 핀 설정
}
void loop(){
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration / (29 * 2);
    Serial.println("Distance(cm)=" + String(distance));
    //-------------------------------------------------
    if (distance >= 30) {// 만약 거리가 30cm 이상이라면
        r = 1000;//1 초마다 깜박거린다
    } else if ((distance >= 10) && (distance < 30)) {// 거리가 30 미만 10 이상이라면
        r = distance*10;// 거리 *10ms 초 마다 깜박거린다
    } else {// 가장 가까이 있다면
        r = 100;//0.1 초마다 깜박거린다
    }
    //-------------------------------------------------
    digitalWrite (ledPin, HIGH);//led 켜기
    delay(r);//r 만큼 기다리기
    digitalWrite (ledPin, LOW);//led 끄기
    delay(r);//r 만큼 기다리기
}