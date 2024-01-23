// C++ code
//
const int tempSensorPin = A3;
const int greenPin = 0;
const int bluePin = 1;
const int redPin = 2;

void setup()
{
  pinMode(tempSensorPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop()
{
  int temperature = analogRead(tempSensorPin);
  
  int redValue = map(temperature, 0, 400, 0, 255);
  int greenValue = map(temperature, 300, 700, 0, 255);
  int blueValue = map(temperature, 600, 1023, 0, 255);
  
  setColor(redValue, greenValue, blueValue);
  
  delay(1000);
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}