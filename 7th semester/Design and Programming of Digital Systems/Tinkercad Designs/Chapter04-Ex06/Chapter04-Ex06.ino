// C++ code
//
const int trigPin = 7;
const int echoPin = 6;

int readSensor(){
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return int(0.0173 * pulseIn(echoPin,HIGH)); //cm
}

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  Serial.begin(9600);
}

void loop() {
  int value1 = readSensor(); //cm
  delay(2500); //ms
  int value2 = readSensor(); //cm
  
  //velocity = d/t
  float velocity = (abs(value1 - value2)*3600000) / (2500 * 100000) ; //km/h 

  // Εμφανίστε τα αποτελέσματα στο Serial Monitor
  Serial.print("Distance 1: ");
  Serial.print(value1);
  Serial.print(" meters\t");
  Serial.print("Distance 2: ");
  Serial.print(value2);
  Serial.print(" meters\t");

  Serial.print("Speed: ");
  Serial.print(velocity);
  Serial.println(" km/h");

  delay(1000); 
}