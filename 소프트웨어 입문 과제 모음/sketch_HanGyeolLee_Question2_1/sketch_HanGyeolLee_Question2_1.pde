float angle = 0f; //sin 함수를 이용하기 위한 각도 변수
float speed_oscillation = .1f; // angle 변수 프레임당 증가량
float r_oscillation = 5; // 꿈틀거리는 정도 (sin 함수의 최댓값)
float x1 = 100; // 애벌레 이동용 x변수
int direction = -1; // 애벌레의 방향
int[] radian_Data = {0, 90, 135, 210}; //반복문 활용을 위한 라디안 데이터

void setup() {
  size(400, 200); //canvas 크기 설정
  noStroke(); // 외부선 제거
}
void draw() {
  background(150, 210, 0); // 배경 생성
  if ((x1 - 15 <= 0) || (x1 + 105 >= width)) // canvas에 에벌레가 접촉했을 시 
    direction *= -1; // 방향 변경
  angle += speed_oscillation;  //꿈틀거리기 위해 angle 증가
  x1 += direction; // 에벌레 이동
  fill(0, 150, 80); //애벌레 색 지정
   //애벌레 생성---------------------------------------------------------
  for (int i = 0; i<4; i++)
   ellipse(x1+30*i, height/2+sin(angle+radians(radian_Data[i]))*r_oscillation, 30, 30);
  //-------------------------------------------------------------------
  fill(0); //눈 색상 설정
  if (direction > 0) //방향이 + x 방향일 때
    ellipse(x1+100, -5+height/2+sin(angle+radians(210))*r_oscillation, 8, 8); // 위 반복문에서 i = 3 일때 생성되는 원에 눈 생성
   else  // 그렇지 않다면
    ellipse(x1-10, height/2-6+sin(angle)*r_oscillation, 8, 8);// 위 반복문에서 i = 0 일때 생성되는 원에 눈 생성
}
