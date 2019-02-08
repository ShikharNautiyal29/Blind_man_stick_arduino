int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo
long duration;
int dist;
int Buzz=13;
int ledPin = 8;
int ldrPin = A1;
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(Buzz,OUTPUT);
  digitalWrite(Buzz,LOW);
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
}
 
void loop()
{
  int ldrStatus = analogRead(ldrPin);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  dist = (duration/2) / 29.1;     
  if (dist<50 && dist>25)
{
  Serial.print(dist); Serial.println("Object Alert");
  digitalWrite(Buzz,HIGH);
    delay(60);
  digitalWrite(Buzz,LOW);
    delay(60);
}
if(dist<25 && dist>15)
{
  Serial.print(dist); Serial.println("Object Alert");
  digitalWrite(Buzz,HIGH);
    delay(40);
  digitalWrite(Buzz,LOW);
    delay(40);
}  
  if(dist<15)
{
  Serial.print(dist); Serial.println("Object Alert");
  digitalWrite(Buzz,HIGH);
    delay(15);
  digitalWrite(Buzz,LOW);
    delay(15);
}  
if (ldrStatus <= 200) {

digitalWrite(ledPin, HIGH);

Serial.print("Its DARK, Turn on the LED : ");

Serial.println(ldrStatus);

} 
else {

digitalWrite(ledPin, LOW);

Serial.print("Its BRIGHT, Turn off the LED : ");

Serial.println(ldrStatus);

}
  
  delay(100);
  }
