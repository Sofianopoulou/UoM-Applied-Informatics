#include <LiquidCrystal.h>

const int soilSensorPin = A1;
const int buttonPin = 12;
int sensorValue, percentSensorValue, buttonState;
LiquidCrystal lcd(2, 3, 4, 5, 6, 7, 8, 9, 10, 11);

void setup() {
  pinMode(soilSensorPin, INPUT);
  pinMode(buttonPin, INPUT);
  for (int i=2;i<12;i++) pinMode(i, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Humidity:");
}

void loop() {
  
  buttonState = digitalRead(buttonPin);
  
  if(buttonState == HIGH) {
  	sensorValue = analogRead(soilSensorPin);
    percentSensorValue = sensorValue/100;
    
    lcd.setCursor(0,1);
  	lcd.print(percentSensorValue);
    lcd.print("%");
    delay(1000);
  }
  
  while (buttonState == digitalRead(buttonPin)) {
    delay(200); // time to de-bounce
  }
  
  
}
