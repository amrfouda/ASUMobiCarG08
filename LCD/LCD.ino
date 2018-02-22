#include <LiquidCrystal.h>
LiquidCrystal lcd (10,8,3,2,1,0);
int sensor;
unsigned int x;
void setup()
{
lcd.begin (16,2);
lcd.print("Temperature");
}
void loop()
{
  sensor=analogRead(A0);
  x=500.0*sensor/1024.0;
  lcd.setCursor(0,1);
  lcd.print(x);
  
}
