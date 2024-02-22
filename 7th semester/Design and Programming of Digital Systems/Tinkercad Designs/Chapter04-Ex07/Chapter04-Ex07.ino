// C++ code
// + δεύτερη παροχής τάσης για δύναμη στους κινητήρες

int VR = 0;
int motor1Speed, motor2Speed;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  VR = analogRead(A0);
  motor1Speed = map(VR, 0, 1023, 255, 0);   
  motor2Speed = map(VR, 0, 1023, 0, 255);
  analogWrite(9, motor1Speed);
  //delay(1000);
  analogWrite(10, motor2Speed);
  delay(1000);
}