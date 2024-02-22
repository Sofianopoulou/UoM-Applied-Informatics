// C++ code
//

const int tempSensorPin = A0;
const int led[] = {5, 4, 3, 2};
const int temp[] = {0, 15, 30, 45, 50};
const int length = 4, period = 1;
int i, temperature;
float degrees;

void setup()
{
  pinMode(tempSensorPin, INPUT);
  for(i=0; i<length;i++) { 
  	pinMode(led[i], OUTPUT);
  }
}

void loop()
{
  temperature = analogRead(tempSensorPin);
  degrees = ( float(temperature) * 5 / 1023 ) * 100 - 50;
  
  if(degrees > temp[length]) {
    flashLeds();
    temperature = 0; //to keep the flashing going
  }
  else {
    for (i=0;i<length;i++) {
      if(degrees >=temp[i]) {
        digitalWrite(led[i], HIGH);
      } else {
		 digitalWrite(led[i], LOW);
      }
  	}
  }
  while (temperature == analogRead(tempSensorPin)) {
    delay(1000);
  }
  
}
  
  void flashLeds() {
    int ms = period * 1000 / 2;
    for (i = 0; i < length; i++) {
     digitalWrite(led[i], HIGH);
    }
    delay(ms);
    
    for(i=0; i<length; i++){
    digitalWrite(led[i], LOW);
    }
    delay(ms);
  }