int diameter = 0; // 원의 지름
int val = 2; // 원 증가/감소 크기 변수
void setup() {
    size (600, 600); // canvas 크기 지정
    noStroke(); // 윤곽선 제거
}
void draw(){
    if ((diameter > width) || (diameter < 0)){ // 원이 canvas 를 넘어가거나, 원 지름이 0 보다 작을떄
        val *= -1; // 증/감 변경
    }
    fill (0, 95, 135); // 배경색 지정
    rect(0, 0, width, height); // 배경 생성

    translate (width/2, height/2); // canvas 의 중심으로 좌표 이동
    
    if (val > 0){ // val 이 양수라면 - 원이 커지는 중 이라면
        fill (0, diameter, 0); // 색상을 원 지름 만큼 Green 값을 주어 색상이 변화 하는것이 보이도록 한다
    } else { // 그렇지 않다면
        fill (0, 0, (400-diameter));// 색상을 원 지름 만큼 blue 값을 주어 색상이 변화 하는것이 보이도록 한다
    }
    ellipse(0, 0, diameter, diameter); //원 생성
    diameter += val; // 원지름 증가/ 감소
}