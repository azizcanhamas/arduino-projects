#include <IRremote.h>

#define trig 2
#define echo 3
#define sag_Motor_Enable 5
#define sag_Ileri 6
#define sag_Geri 7
#define sol_Ileri 8
#define sol_Geri 9
#define sol_Motor_Enable 10

#define ileriye 0x16
#define geriye 0x17
#define saga 0x12
#define sola 0x13
#define durdur 0x35
 
int IR=12;

IRrecv irRecv(IR);
decode_results results;

long sure;
int mesafe;

void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(sag_Motor_Enable,OUTPUT);
  pinMode(sag_Ileri,OUTPUT);
  pinMode(sag_Geri,OUTPUT);
  pinMode(sol_Ileri,OUTPUT);
  pinMode(sol_Geri,OUTPUT);
  pinMode(sol_Motor_Enable,OUTPUT);
  pinMode(IR,OUTPUT);

  Serial.begin(9600);

  irRecv.enableIRIn();
}

void loop() {
  
  if(irRecv.decode(&results)){
    Serial.println(results.value,HEX);
    

    if(results.value==ileriye){
      ileri();
    }
    if(results.value==durdur){
      dur();
    }
    if(results.value==geriye){
      geri();
    }
    if(results.value==sola){
      sol();
    }
    if(results.value==saga){
      sag();
    }

    irRecv.resume();
  }
  delay(100);

  

}

void dur(){
  digitalWrite(sol_Ileri,LOW);
  digitalWrite(sol_Geri,LOW);
  digitalWrite(sag_Ileri,LOW);
  digitalWrite(sag_Geri,LOW);

  analogWrite(sol_Motor_Enable,0);
  analogWrite(sag_Motor_Enable,0);
}

void ileri(){
  digitalWrite(sol_Geri,LOW);
  digitalWrite(sag_Geri,LOW);
  
  digitalWrite(sol_Ileri,HIGH);
  digitalWrite(sag_Ileri,HIGH);
  
  analogWrite(sol_Motor_Enable,150);
  analogWrite(sag_Motor_Enable,150);
}

void sol(){
  digitalWrite(sol_Ileri,LOW); 
  digitalWrite(sag_Geri,LOW);
  
  digitalWrite(sag_Ileri,HIGH);
  digitalWrite(sol_Geri,HIGH);
  
  analogWrite(sag_Motor_Enable,150);
  analogWrite(sol_Motor_Enable,150);
}

void sag(){
  digitalWrite(sol_Ileri,HIGH); 
  digitalWrite(sag_Geri,HIGH);
  
  digitalWrite(sag_Ileri,LOW);
  digitalWrite(sol_Geri,LOW);
  
  analogWrite(sol_Motor_Enable,150);
  analogWrite(sag_Motor_Enable,150);
}

void geri(){
  digitalWrite(sol_Ileri,LOW);
  digitalWrite(sag_Ileri,LOW);
  
  digitalWrite(sol_Geri,HIGH);
  digitalWrite(sag_Geri,HIGH);

  analogWrite(sol_Motor_Enable,150);
  analogWrite(sag_Motor_Enable,150);

  
}
