// C++ code
//
const int trigPin = 3;
const int echoPin = 2;  
const int piezoPin = 8;  
int value;

int readSensor(){
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //pulseIn: returns the length of the pulse in ms while ECHO is HIGH
  return int(0.01723 * pulseIn(echoPin, HIGH)); //(34460x 10^-6) /2
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(piezoPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  Serial.begin(9600);
}

void loop() {
  value = readSensor();
  Serial.print("Distance: ");
  Serial.print(value);
  Serial.print("cm");
  while( abs(value - readSensor()) <= 2 ) delay(100);

  // Change the sound of the piezo based on distance
  //tone(pin, frequency, duration in ms)
  if (value < 100) {
    tone(piezoPin, 1000, 1000);  // Low distance
    delay(350);
  } else if (value < 200) {
    tone(piezoPin, 500, 1000);  // Medium distance
    delay(350);
  } else if (value < 300) {
    tone(piezoPin, 2000, 1000);  // Maximum distance
    delay(350);
  }
   else {
    noTone(piezoPin);  // No sound for greater distance
    delay(1000);
  }
}
