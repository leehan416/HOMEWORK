size(300, 200); //canvas 크기 지정
background(150, 100, 200); //배경색 지정
noStroke(); //윤곽선 제거
int h0=15; //초록색 계열 사각형의 높이 
int h1=135; //빨간색 계열 사각형의 높이 
int y=30; //사각형의 y위치
int val=1; //사각형 색상과 높이 변경을 위한 변수
for (int x=15; x<=270; x+=15) { // x 방향 조작 반복문
    if (val > 0) {//val 변수가 0보다 클때
        fill(0, 100, 0);//초록색 계열 색상 지정
        rect (x, y, 10, h1);// 사각형 생성
        h1-=15; // 다음 초록색 계열 사각형의 높이 감소
  } else { //그렇지 않다면
        fill(100, 0, 0); // 빨간색 계열 색상 지정
        rect (x, y, 10, h0);//사각형 생성
        h0+=15; // 다음 빨간색 계열 사각형의 높이 증가
  }
  val*=-1; //다음 사각형 종류 변경(val에 -1 을 곱한다 - 음수 혹은 양수로 변경)
}