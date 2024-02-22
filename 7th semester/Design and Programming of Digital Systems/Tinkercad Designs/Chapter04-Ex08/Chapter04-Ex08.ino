// C++ code
//
const int buttonPin = 7;
const int ledPin = 4;

int buttonState;
int ledState;
int lastButtonState;
unsigned long buttonPressTime = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  delay(200); // time to de-bounce
  buttonState = digitalRead(buttonPin);

  if (digitalRead(buttonPin) != lastButtonState) {
    if (buttonState == HIGH) { 
      buttonPressTime = millis(); 
    } else {
      unsigned long buttonReleaseTime = millis();
      unsigned long buttonPressDuration = buttonReleaseTime - buttonPressTime;
      
      Serial.println(buttonPressDuration);

      if (buttonPressDuration > 3000) {
        flashLED();
      } else {
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
      }
     
    }
  }
  lastButtonState = buttonState;
  
}

void flashLED() {
  for (int i = 0; i < 10; ++i) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
}
