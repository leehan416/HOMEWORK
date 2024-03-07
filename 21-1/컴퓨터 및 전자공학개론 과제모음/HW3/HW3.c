//5---------------------------------------
void setup() {
    pinMode(13, OUTPUT); 
}
void loop() {
    digitalWrite(13, HIGH);
    delay(2000); digitalWrite(13, LOW); 
    delay(2000);
}
//6---------------------------------------
void setup() {
    pinMode(13, OUTPUT);
}
void loop() {
    digitalWrite(13, HIGH);
    delay(1000); digitalWrite(13, LOW); 
    delay(10);
} 
//7---------------------------------------
void setup() {
    pinMode(13, OUTPUT);
}
int val = 1;
int time = 500; 
void loop() {
    if (val % 4 == 0)
        time = 2500;
    else 
        time = 500;
    digitalWrite(13, HIGH); 
    delay(time); 
    digitalWrite(13, LOW); 
    delay(500);
    val ++;
}

//---------------------------------------Bonus Question.
void setup() {
    pinMode(13, OUTPUT); 
}
void loop() {
    analogWrite(13, /*밝기*/ 127);
    // digitalwrite (13, HIGH) 의 절반 정도 밝기를 가진다 delay(1000);
    analogWrite(13, 0);
    // digitalwrite (13, LOW); 와 같은 역할을 한다.
    delay(1000); 
}