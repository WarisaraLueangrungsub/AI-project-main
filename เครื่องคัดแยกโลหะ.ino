#include <Servo.h>
Servo servo;  
int state = 0;
int SENSOR_PIN = D4;  
int LED = D1;

void setup() {
  Serial.begin(9600);
  pinMode (SENSOR_PIN,INPUT);
  pinMode(D2,OUTPUT);
  pinMode (D1,OUTPUT);
  servo.attach(D2);  
  servo.write(160);
  delay(10000);
  servo.write(0);
  
}


void loop() {
  int ST = digitalRead(SENSOR_PIN); //อ่านค่า
  if (state == 0) {
    if(ST == 1 ){
      servo.write(180);
      Serial.println("ตรวจพบโลหะ");
      digitalWrite(LED, HIGH); 
      Serial.println("LED ON");
      delay(1000);
    }
    else if(ST == 0 ){
      servo.write(0);
      state = 1;
      Serial.println("ไม่พบโลหะ");
      digitalWrite(LED, LOW);
      Serial.println("LED OFF");
    }
  }
 if(state==1){
  delay(300);
  state = 0;
 }
}