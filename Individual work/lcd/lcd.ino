#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal.h>

const byte rows = 4; 
const byte cols = 3; 
char keys[rows][cols] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[rows] = {6, 7, 8, 9};
byte colPins[cols] = {10, 13 , 1}; 
Keypad key = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  
  for(int i = 0 ; i < 2 ; i++)
  {
    for(int j = 0 ; j < 16 ; j++)
    {
      char c = key.waitForKey();
      lcd.setCursor(j,i);
      lcd.print(c);  
    }
  }
  lcd.clear();
}
