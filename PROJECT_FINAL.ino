#define ledR 6
#define ledG 5
#define ledB 3
const int trigPin=9;
const int echoPin=10;
long duration;
int distance;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledR,OUTPUT);
  pinMode(ledG,OUTPUT);
  pinMode(ledB,OUTPUT);
  Serial.begin(9600);
}


void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
duration=pulseIn(echoPin, HIGH);
distance=duration*0.034/2;
//Serial.print("Distance");
//Serial.println(distance);
 
 if((distance<10)) 
   {
    analogWrite(ledB,255);
    delay(1000);
    Serial.println("Someone at the Door, Please Check!");
    analogWrite(ledG,255);
    analogWrite(ledB,255);
    delay(1000);
    analogWrite(ledG,0);
    analogWrite(ledB,0);
    delay(10);
    analogWrite(ledB,255);
    delay(1000);
    
   }
   else if(distance>10)
   {
    analogWrite(ledR,0);
    analogWrite(ledG,0);
    analogWrite(ledB,0);
  }
}
