#include<LiquidCrystal.h>

LiquidCrystallcd(7,8,9,10,11,12);

void setup(){
    lcd.begin(16,2);
    lcd.clear();
}
void loop(){
    lcd.setCursor(0,0);
    lcd.write("Changetheworld");
    lcd.setCursor(0,1);
    lcd.write("22100594");
    delay(1000);
    lcd.clear();
    delay(1000);
}