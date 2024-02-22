#include <LiquidCrystal_I2C.h>

//initialize lcd
LiquidCrystal_I2C lcd(0x20,16,2);

void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  
  // Print a message on both lines of the LCD.
  //lcd.cursor(column,row) index starts at 0
  lcd.setCursor(2,0);   //Set cursor to character 2 on line 0
  lcd.print("Hello world!");
  
  lcd.setCursor(2,1);   //Move cursor to character 2 on line 1
  lcd.print("LCD Tutorial");
  pinMode(A3,INPUT);
}

void loop()
{
  Serial.println(analogRead(A3));
  delay(300);

  if(analogRead(A3) == 1023){
  	lcd.clear();
    lcd.print("1");
  }
  else if(analogRead(A3) == 511){
  	lcd.clear();
    lcd.print("2");
  }
  else if(analogRead(A3) == 341){
  	lcd.clear();
    lcd.print("3");
  }
  else if(analogRead(A3) == 256){
  	lcd.clear();
    lcd.print("A");
  }
  else if(analogRead(A3) == 205){
  	lcd.clear();
    lcd.print("4");
  }
  else if(analogRead(A3) == 170){
  	lcd.clear();
    lcd.print("5");
  }
  else if(analogRead(A3) == 146){
  	lcd.clear();
    lcd.print("6");
  }
  else if(analogRead(A3) == 128){
  	lcd.clear();
    lcd.print("B");
  }
  
  else if(analogRead(A3) == 114){
  	lcd.clear();
    lcd.print("7");
  }
  else if(analogRead(A3) == 102){
  	lcd.clear();
    lcd.print("8");
  }else if(analogRead(A3) == 93){
  	lcd.clear();
    lcd.print("9");
  }
  else if(analogRead(A3) == 85){
  	lcd.clear();
    lcd.print("C");
  }
  else if(analogRead(A3) == 79){
  	lcd.clear();
    lcd.print("*");
  }
  else if(analogRead(A3) == 73){
  	lcd.clear();
    lcd.print("0");
  }
  else if(analogRead(A3) == 68){
  	lcd.clear();
    lcd.print("#");
  }
  else if(analogRead(A3) == 64){
  	lcd.clear();
    lcd.print("D");
  }
}