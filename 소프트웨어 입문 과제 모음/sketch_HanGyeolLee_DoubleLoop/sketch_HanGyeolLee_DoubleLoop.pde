size (400,400);
for (int y = 0;y<400;y+=50){  
  if ((y % 100) == 0){
    for (int x = 0;x<400;x+=100){ 
      fill(255,255,255); //white
      rect(x,y,50,50);
      fill(255,0,0); //red
      rect(x+50,y,50,50);}
  }   
  else {   
    for (int x = 0;x<400;x+=100){ 
      fill(0,255,0); //green
      rect(x,y,50,50);
      fill(0,0,255); //blue
      rect(x+50,y,50,50);
    }
  }
}
