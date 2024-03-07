float y = 0f; // 빨간 선의 y 좌표
float x = 0f; // 파란 선의 x 좌표
int val = 1; // 방향 변수
void setup() {
    size (200, 200); //canvas 크기 지정
    strokeWeight(1); // 선 굵기 지정
}
void draw() {
    if (((y >= height) && (x >= width)) || ((y < 0) && (x < 0))) { // 선이 canvas 를 넘어갔다면
        val *=-1; // 방향 변경
    }
    fill (220, 220, 0, 30); //배경 색 지정
    rect(0, 0, width, height); // 배경 생성 
    //-------------------------------- red line
    stroke(255, 0, 0, 300-y); // 선 색상 지정
    line (0, y, width, y); // 선 생성
    y+=val; // 선 이동
    //-------------------------------- blue line
    stroke(0, 0, 255, 300-x); // 선 색상 지정
    line (x, 0, x, height); // 선 생성 
    x+=val; // 선 이동
}