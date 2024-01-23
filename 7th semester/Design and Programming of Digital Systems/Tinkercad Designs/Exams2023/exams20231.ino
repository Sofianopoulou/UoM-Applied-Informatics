// C++ code
//

const int tempSensorPinOne = A0;
const int tempSensorPinTwo = A1;
const int buttonPin = 2;
const int redLed = 5;
const int greenLed = 4;
int temperatureOne, temperatureTwo, buttonState;
float degreesOne, degreesTwo, difference;

void setup()
{
  pinMode(tempSensorPinOne, INPUT);
  pinMode(tempSensorPinTwo, INPUT);
  pinMode(buttonPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  Serial.begin(9600);
}

void loop()
{ 
  buttonState = digitalRead(buttonPin);
    
  if(buttonState == HIGH) {
    temperatureOne = analogRead(tempSensorPinOne);
  	temperatureTwo = analogRead(tempSensorPinTwo);
  	degreesOne = ( float(temperatureOne) * 5 / 1023 ) * 100 - 50;
  	degreesTwo = ( float(temperatureTwo) * 5 / 1023 ) * 100 - 50;
    
    difference = abs(degreesOne - degreesTwo);
    Serial.println(difference);
    
    if(difference > 15) {
      digitalWrite(redLed, HIGH);
      delay(5000);
      digitalWrite(redLed, LOW);
    }
    else {
      digitalWrite(greenLed, HIGH);
      delay(5000);
      digitalWrite(greenLed, LOW);
    }
  }
     
  while (buttonState == digitalRead(buttonPin)) {
    delay(200); // time to de-bounce
  }
      
}