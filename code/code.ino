//initialise the pin numbers to the components
const int trigPin = 9;
 const int echoPin = 10;
 const int buzzer = 8;
 const int mot = 1;
 long duration;
 int distance;
 int safetyDistance;
 
void setup() {
 // declare the input and output pins
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(buzzer, OUTPUT);
 pinMode(mot, OUTPUT);
 Serial.begin(9600);
}
void loop() {
 // put your main code here, to run repeatedly:
 //check the signals from trig pin
 digitalWrite(trigPin, LOW); //off the trigpin for 2microseconds
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH); //on the trigpin for 2microseconds
 delayMicroseconds(2);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin,HIGH); //get the duration
 distance=duration*0.034/2; //calculate distance
 safetyDistance = distance; 
 if (safetyDistance <= 20){
 digitalWrite(buzzer,HIGH);
 tone(buzzer,1000,100);
 digitalWrite(mot,HIGH);
 }
 else{
 digitalWrite(buzzer, LOW);
 digitalWrite(mot, LOW);
 }
 Serial.print("Distance: ");
 Serial.print(distance);
}
