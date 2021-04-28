int x;
int y; 

void setup() { 
  size(200, 200); 
  stroke(0, 255, 0);
  strokeWeight(5); 
  background(0, 0, 0);
  x = 0;
  y = 0;
} 
void draw() { 
  if (x >200){
    x = 0;
    y += 19;
    if (y >200){
      background(0, 0, 0);
      y = 0;
    }

  }
  line(0, y, x, y); 
  x++;
} 
