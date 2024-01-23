// C++ code
//
const int tempSensorPin = A0;
const int redPin = 11;
const int bluePin = 10;
const int greenPin = 9;

void setup()
{
  pinMode(tempSensorPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int temperature = analogRead(tempSensorPin);
  
  //e.g. map(analogRead(pin), 0, 1023, -50, 200);
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