size(200, 200); //canvas 크기 지정
background(200, 200, 50);//배경색 지정
float radiusX=5; // x 반지름 변수
fill(0, 200, 50); // 원 색상 지정
for (int x=20; x<=180; x+=20) { // x 방향 조작 반복문
  float radiusY = 5; // y 반지름 변수
  for (int y =20;y <=180 ;y+=20){ // y 방향 조작 반복문
    ellipse (x,y,radiusX,radiusY); // 원 생성
    radiusY+=4; // y 반지름 증가
  }
  radiusX+=4; // x 반지름 증가
}