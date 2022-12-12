

#include <Servo.h>
#include <LiquidCrystal.h>


Servo myservo1;
Servo myservo2;
Servo myservo3;

#define echoPin 6 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 5 //attach pin D3 Arduino to pin Trig of HC-SR04
#define buzzerPin 8


long duration; 
int distance; 
int measurement;

int val = 0;
int i;
int k = 0;

const int rs = 32, en = 30, d4 = 28, d5 = 26, d6 = 24, d7 = 22;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  myservo1.attach(9,700,2200);
  myservo2.attach(8,700,2200);
  myservo3.attach(7,700,2200);

  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 

  Serial.begin(9600);

  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(1, 0);


  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2; 

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
 
 
  lcd.print("Waiting..");
  lcd.setCursor(0,1);
  lcd.print("Give me a high 5!");
  lcd.setCursor(1,0);
 
  if((distance == 3)){
    i=0;
    lcd.print("YAYYYYY!");
    lcd.setCursor(0,1);
    lcd.print("High 5 incoming...!");
    delay(500);
  myservo1.write(2000);
  myservo2.write(2000);
  myservo3.write(850);
  k = 1;

  }
  if(k == 1){
    delay(1000);
    k = 0;
  }

 myservo1.write(1400);
 myservo2.write(1400);
 myservo3.write(1450);

  delay(100);
  lcd.clear();




  
  
  



                 
}
