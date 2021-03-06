int x = 26; // 빨간 원의 좌표 (x, height/2)
int y = 26; // 파란 원의 좌표 (width/2, y)
int diameter = 50; //원의 지름
int directionX = 1; // 빨간 원의 방향
int directionY = 1; // 파란 원의 방향
int alhpa = 150;

void setup(){ 
  size(400, 300); // cansvas 크기 설정
}
void draw(){
  fill(255, 255, 0, 15); //yellow + 투명도를 적용해 궤적이 보이게 함
  rect(0, 0, width, height); //배경 생성 
//-----------------------------------------------접촉 판별
  if (dist(x, height/2, width/2, y) < diameter) //두 원이 접촉했으면
    alhpa = 150; //투명도 적용
  else  //미 접촉시
    alhpa = 255; // 투명도 미적용
//-----------------------------------------------원 생성
  fill(255, 0, 0); // red
  ellipse (x, height/2, diameter, diameter); //원 생성

  fill(0,0,255,alhpa); //blue +
  ellipse (width/2, y, diameter, diameter); //원 생성
//-----------------------------------------------원 방향 변경
  if ((x+diameter/2 >=width) || (x-diameter/2 <=0)) //(원의 중심 + 반지름)이 canvas를 넘어가면
    directionX *= -1; // 방향 변경
  if ((y+diameter/2 >=height) || (y-diameter/2 <=0)) //(원의 중심 + 반지름)이 canvas를 넘어가면
    directionY *= -1; // 방향 변경
//-----------------------------------------------원 방향 변경
  x += 4 /*(빨간 원의 속도 = 4)*/ * directionX; //원 좌표 이동
  y += 2 /*(파란 원의 속도 = 2)*/ * directionY; //원 좌표 이동
}
