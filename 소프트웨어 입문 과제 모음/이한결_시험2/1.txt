float angle = 0f; // 각도 변수
int count; // 회전 횟수 count 하는 변수
int val; //  회전 횟수 지정 변수
int p = 1; // 회전 방향 변수
void setup(){
    size (200,200); //canvas 크기 조정
    smooth(); // 부드럽게 
    noStroke(); // 윤곽선 제거 
    Reset(); // 데이터 리셋
}
void draw(){
    if (angle >= 3.15f ){ // 사각형이 1회 회전했다면
        angle = 0f; // 각도 초기화
        count++; // 회전 횟수 +1
        if (count >= val){ // 회전 횟수가 초기 지정값을 넘어갔다면 
            Reset(); // 데이터 리셋
            p *= -1; // 방향 변경
        }
    }
    fill (150, 0, 150); // 배경 색 지정
    rect(0, 0, width, height); // 배경 생성
    fill (255); // 사각형 색상 지정
    translate (100, 100); // 좌표 이동
    rotate(p*angle); // 좌표 회전
    rect(-40,-40,80,80); // 사각형 생성
    angle +=.1f; // 회전을 위해 각도 변수 증가
}
void Reset(){ // 데이터 리셋 함수
    val  = (int)random (3, 5); // 회전 횟수 랜덤 지정 (자연수)
    count = 0; // 이전 회전 횟수 초기화
}