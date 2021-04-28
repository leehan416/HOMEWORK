//실습 1
bool val = false;// 반짝이는 것을 통제하는 변수
int r =500;// 주기 기본값
const int ledPin = 13; // led 활용을 위한 핀 설정하는 변수 byte data = 0; // 입력되는 데이터 받아오는 변수
void setup() { // 시작시 실행되는 함수 
    pinMode(ledPin, OUTPUT); 
    Serial.begin(9600); // 속도 설정 
    Serial.println("Hello"); // Hello 출력
}
void loop() { //계속 반복되는 함수
    if (Serial.available() > 0) { // 입력이 있었다면
        data = Serial.read(); // data 로 데이터를 받아온다 //-----------------------------------
        if (data == '\n') { // 만약 데이터가 \n 이라면 (줄 바꿈이라면)
            return; // 함수 종료 
        } else { // 아니라면
            if (data == '@') { // 만약 데이터가 @이라면 val=true;//val 을 true 로 지정
                return; // 함수 종료
            } else if (data == '#') { // 만약 데이터가 #이라면 
                val = false; // val 을 false 로 지정
                return; // 함수 종료
            } else {// 위에 해당하는 값이 없다면 
                if((data>48) && (data<58)) {// 만약 (10진수 기준)1~9 숫자라면
                    r = 100 * (data-48); //주기를 변경
                    return; //함수 종료
                } else {// 위 범위에 맞지 않는 수라면
                Serial.println("Out of range"); // out of range 출력 
                }
            } 
        }
    } 
    //-----------------------------------
    if(val){// 만약 val 이 true 라면 led를 반짝여라 
        digitalWrite(ledPin, HIGH); //on
        delay (r); // 주기만큼 기다리기 
        digitalWrite(ledPin, LOW); //off
        delay(r); // 주기만큼 기다리기
    } 
}


//실습 2
const int ledPin = 13; // 핀 설정을 위한 변수 생성 bool val = false; // led 깜박임 변수
intr=500;// 주기 변수
void setup() { // 코드 실행시 실행되는 함수 
    pinMode(ledPin, OUTPUT); // 핀 설정 
    Serial.begin(9600); // 속도 설정 
    Serial.println("Hello"); // "Hellp"출력
}
void loop() { //계속 반복되는 함수
    byte data; // 데이터 입력 받아오는 변수 
    if (Serial.available() > 0) { // 입력이 있었다면
        data = Serial.read(); // 읽어오기
        int result = function1(data); // 함수의 결과값을 받아오는 변수를 생성한다 
        if (result == -1) // 만인 결과값이 -1 이라먄,
            Serial.println("Out of range"); // "out of range" 출력 
    }
}
int function1(byte data) {
    if(data=='\n')// 칸 넘김 이 읿력되었을 때 ,
        return 0; // 함수 종료
    if (data == '@') { // @가 입력되었을때
        val = true; // 변수를 ture 로 변경한다. 
    } else if(data=='#') {//#가 입력되었을 때
        val = false; // 변수를 false 로 만든다 
    } else if(data>48&&data<58){//10진수 기준으로 1~9 가 입력 되었을 때
        r = 100 * data; // 주기를 변경한다.
    } else { // 위에 대응되는 문자가 아니라면
        return -1; // 함수를 종료하고, -1을 결과값으로 내보낸다 
    }
    //-----------------------------------
    while (val) { // loop 함수를 대신하여 사용할 반복문
        if (Serial.available() > 0) { // 만일 입력이 있었다면, 
            data = Serial.read(); // 데이터를 읽어온다
            if (data == '@') { // 만일 @가 입력되었다면
                val = true; // 변수를 true 로 만든다 
            } else if(data=='#') {// 만일 #가 입력 되었다면,
                return 0; // 함수를 종료한다. = 반복문을 종료한다 
            } else if(data>48&&data<58) {//10진수 기준으로 1~9 가 입력 되었을 떄
                r = 100 * (data-48); // 주기를 변경한다. 
            } else {// 위 숫자의 범위를 넘어가는 숫자라면
                if(data=='\n') {// 만일 칸 넘김이라면 아무것도 하지 않는다 - 출력 방지
                } else {// 칸넘김 이외의 모든 데이터를 입력 받았을 때  
                    Serial.println("Out of range"); // out of range 를 출력한다     
                }
            }
        }
        //----------------------------------- led 동작부분 
        digitalWrite(ledPin, HIGH); //on
        delay (r); //주기만큼 기다린다
        digitalWrite(ledPin, LOW); // off
        delay(r); //주기만큼 기다린다
        //----------------------------------- 
    }
}