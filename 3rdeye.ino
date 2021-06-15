const int trigPin = 9;
  const int echoPin = 10;
  const int buzzer = 11;
  const int ledPin = 13;
  const int mot=12;
  long duration;
  int distance;
  int safetyDistance;
  
void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(mot, OUTPUT);
  Serial.begin(9600);
 

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;

  safetyDistance = distance;

  if (safetyDistance <= 80){
    digitalWrite(buzzer,HIGH);
    digitalWrite(ledPin,HIGH);
    digitalWrite(mot,HIGH);
  }
  else{
    digitalWrite(buzzer, LOW);
    digitalWrite(ledPin, LOW);
    digitalWrite(mot, LOW);
  }
  Serial.print("Distance: ");
  Serial.print(distance);

}
