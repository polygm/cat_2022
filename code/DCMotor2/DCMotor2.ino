#include <SoftwareSerial.h>
#define BT_RXD 8
#define BT_TXD 9

SoftwareSerial bluetooth(BT_RXD, BT_TXD);

// 3번과 4번 핀은 모터 제어에 관한 핀
int IN1Pin = 3;
int IN2Pin = 4;
int sensorpin1 = 6;
int sensorpin2 = 7;
int val1 = 0; // 포토센서핀 값을 받는다 기본 0
int val2 = 0; // 2번포토센서값
int buttonpin = 12;

// 5번핀은 모터의 힘을 설정해주는 핀
int ENAPin = 5;
int buzzerPin = 13;

unsigned long time_previous, time_previous1, time_current = 0;
const long delayTime = 1000;
boolean buzzerState = false;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  Serial.println("START");
  pinMode(IN1Pin, OUTPUT);
  pinMode(IN2Pin, OUTPUT); // 3, 4번 제어핀들은 핀모드를 출력은로 설정
  analogWrite(ENAPin, 255); //5번 핀에 255의 최대 힘을 설정한다. 
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonpin, INPUT);

  int button = 0;
}



void loop() {

   char val = bluetooth.read();
   val2 = digitalRead(sensorpin2);
   
  if(bluetooth.available()){
    Serial.write(bluetooth.read());
  }



  while(val == 'a') {
    val1 = digitalRead(sensorpin1);
      Serial.println(val1);
    if(val1 == LOW){
      digitalWrite(IN1Pin, HIGH); 
      digitalWrite(IN2Pin, LOW);
      }
     else{
      digitalWrite(IN1Pin, LOW);
      digitalWrite(IN2Pin, LOW);
      Serial.print("STOP");
      tone(buzzerPin, 131);
      delay(500);
      noTone(buzzerPin);
      break;
     }
    }
  
  while(val == 'b') {
    val2 = digitalRead(sensorpin2);
      Serial.println(val2);
    if(val2 == LOW){
      digitalWrite(IN1Pin, LOW); 
      digitalWrite(IN2Pin, HIGH);
      }
     else{
      digitalWrite(IN1Pin, LOW);
      digitalWrite(IN2Pin, LOW);
      Serial.print("STOP");
      tone(buzzerPin, 131);
      delay(500);
      noTone(buzzerPin);
      break;
     }
    }

  if(val == 'c') {
  //Brake (Stop) 핀 3, 4에 똑같이 High를 주거나 Low을 주면 은 멈춘다.
   digitalWrite(IN1Pin, HIGH);
   digitalWrite(IN2Pin, HIGH);
  }
 }
