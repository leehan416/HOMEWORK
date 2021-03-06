float r=15;
float speedX = 1.5;  
float speedY = 0.8; 

float x1=100; 
float y1=150; 
int directionX1 = 1; 
int directionY1 = -1; 

float x2=50; 
float y2=80; 
int directionX2=-1; 
int directionY2=-1; 

float x3=200; 
float y3=30; 
int directionX3=-1; 
int directionY3=-1; 

void setup() { 
  size(300, 200); 
  noStroke(); 
  smooth(); 
  ellipseMode(RADIUS); 
}
void draw() { 
  background(0, 150, 80); 
  
  //_________________________________________________________
  fill(255); 
  ellipse(x1, y1, r, r); 
  x1 += speedX*directionX1; 
  
  if((x1+r > width) || (x1-r < 0)) directionX1 = -directionX1; 
  y1 += speedY*directionY1; 
  
  if((y1+r > height) || (y1-r < 0)) directionY1 = -directionY1; 
  
  //_________________________________________________________
  fill(255, 0, 0); 
  ellipse(x2, y2, r, r); 
  
  x2 += speedX*directionX2; 
  
  if((x2+r > width) || (x2-r < 0)) directionX2 = -directionX2; 
  y2 += speedY*directionY2; 
  
  if((y2+r > height) || (y2-r < 0)) directionY2 = -directionY2; 
  //_________________________________________________________
  fill(0,255, 0); 
  ellipse(x3, y3, r, r); 
  
  x3 += speedX*directionX3; 
  
  if((x3+r > width)|| (x3-r < 0)) directionX3 = -directionX3; 
  y3 += speedY*directionY3; 
  
  if((y3+r > height) || (y3-r < 0)) directionY3 = -directionY3; 
  
  //_________________________________________________________

  float d12 = dist(x1, y1, x2, y2); 
  float d23 = dist(x2, y2, x3, y3); 
  float d31 = dist(x1, y1, x3, y3); 
  
  if(d12 < (r+r)) { 
    directionX1 = -directionX1; 
    directionY1 = -directionY1; 
    directionX2 = -directionX2;  
    directionY2 = -directionY2;  
  } 
    if(d23 < (r+r)) { 
    directionX2 = -directionX2; 
    directionY2 = -directionY2; 
    directionX3 = -directionX3;  
    directionY3 = -directionY3;  
  } 
    if(d31 < (r+r)) { 
    directionX1 = -directionX1; 
    directionY1 = -directionY1; 
    directionX3 = -directionX3;  
    directionY3 = -directionY3;  
  } 
}
