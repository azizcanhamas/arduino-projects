#include <DHT.h>

#define LDR_Pin A0
#define FAN_Pin 15
#define ISINEM_Pin 13
#define ISINEM_Tip DHT11
#define LED_Pin 12
#define TOPRAKNEM_Pin 14
#define SUMOTORU_Pin 16

DHT dht(ISINEM_Pin,ISINEM_Tip);

int Karanlik_Isik=550;
String FAN_Status="KAPALI !";
String LED_Status="KAPALI !";
String SUMOTORU_Status="KAPALI !";
String TOPRAKNEM_Status="NEMSİZ !";

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  pinMode(LDR_Pin,INPUT);
  pinMode(FAN_Pin,OUTPUT);
  pinMode(ISINEM_Pin,INPUT);
  pinMode(LED_Pin,OUTPUT);
  pinMode(TOPRAKNEM_Pin,INPUT);
  pinMode(SUMOTORU_Pin,OUTPUT);
}

void loop() {
  PRINT_SystemStatus();
  
  if(LDR_Oku()>0 && LDR_Oku()<=Karanlik_Isik) LED_Durum_Degistir(1);
  else LED_Durum_Degistir(0);

  if(ISINEM_Oku(0)>=28||ISINEM_Oku(1)>=95) FAN_Durum_Degistir(1);
  else FAN_Durum_Degistir(0);

  if(TOPRAKNEM_Oku()==1)SUMOTORU_Durum_Degistir(1);
  else SUMOTORU_Durum_Degistir(0);
  
}

int LDR_Oku(){
  return analogRead(LDR_Pin);
}

void LED_Durum_Degistir(int i){
  if(i==1){
    digitalWrite(LED_Pin,HIGH);
    LED_Status="ACIK !";
  }
  else if(i==0){
    digitalWrite(LED_Pin,LOW);
    LED_Status="KAPALI !";
  }
}

int ISINEM_Oku(int i){
  if(i==0) return dht.readTemperature();
  else if(i==1) return dht.readHumidity();
}

void FAN_Durum_Degistir(int i){
  if(i==1){
    digitalWrite(FAN_Pin,HIGH);
    FAN_Status="ACIK !";
  }
  else if(i==0){
    digitalWrite(FAN_Pin,LOW);
    FAN_Status="KAPALI !";
  }
}

int TOPRAKNEM_Oku(){
  int value=digitalRead(TOPRAKNEM_Pin);
  if(value==0)TOPRAKNEM_Status="NEMLİ !";
  else if(value==1)TOPRAKNEM_Status="NEMSİZ !";
  
  return value;
}

void SUMOTORU_Durum_Degistir(int i){
  if(i==1){
    SUMOTORU_Status="ACIK !";
    digitalWrite(SUMOTORU_Pin,HIGH);
    delay(3000);
    digitalWrite(SUMOTORU_Pin,LOW);
    delay(7000);
  }
  else if(i==0){
    digitalWrite(SUMOTORU_Pin,LOW);
    SUMOTORU_Status="KAPALI !";
  }
}


void PRINT_SystemStatus(){
  Serial.print("Ortam Isik Degeri: ");
  Serial.println(LDR_Oku());

  Serial.print("Fan Durumu: ");
  Serial.println(FAN_Status);

  Serial.print("Ortam Nem Degeri: ");
  Serial.print("%");
  Serial.println(dht.readHumidity());

  Serial.print("Ortam Sıcaklik Degeri : ");
  Serial.print(dht.readTemperature());
  Serial.println(" *C");

  Serial.print("LED Durumu : ");
  Serial.println(LED_Status);

  Serial.print("Toprak-Nem Durumu : ");
  Serial.println(TOPRAKNEM_Status);

  Serial.print("Su Motoru Durumu : ");
  Serial.println(SUMOTORU_Status);

  Serial.println("************************************");

  delay(1000);
}
