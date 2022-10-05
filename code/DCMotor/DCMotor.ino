#include <SoftwareSerial.h>
#define BT_RXD 8
#define BT_TXD 9

SoftwareSerial bluetooth(BT_RXD, BT_TXD);

// 3번과 4번 핀은 모터 제어에 관한 핀
int IN1Pin = 3;
int IN2Pin = 4;

// 5번핀은 모터의 힘을 설정해주는 핀
int ENAPin = 5;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  Serial.println("START");
  pinMode(IN1Pin, OUTPUT);
  pinMode(IN2Pin, OUTPUT); // 3, 4번 제어핀들은 핀모드를 출력은로 설정
  analogWrite(ENAPin, 255); //5번 핀에 255의 최대 힘을 설정한다. 
}

void loop() {

   char val = bluetooth.read();
   
  if(bluetooth.available()){
    Serial.write(bluetooth.read());
  }

  if(val == 'a') {
    digitalWrite(IN1Pin, HIGH); 
    digitalWrite(IN2Pin, LOW);
  } 
  
  if(val == 'b') {
   digitalWrite(IN1Pin, LOW);
   digitalWrite(IN2Pin, HIGH);  
  } 

  if(val == 'c') {
  //Brake (Stop) 핀 3, 4에 똑같이 High를 주거나 Low을 주면 은 멈춘다.
   digitalWrite(IN1Pin, HIGH);
   digitalWrite(IN2Pin, HIGH);
  }
}
