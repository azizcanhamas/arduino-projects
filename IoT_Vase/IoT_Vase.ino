#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>

char auth[] = "auth_token";
char ssid[] = "wifi_ssid";
char pass[] = "wifi_pass";

int pinValue;

BLYNK_WRITE(V1){
  pinValue=param.asInt();
  Serial.print("blynk_Value: ");
  Serial.print(pinValue);
  Serial.print("\n");
  
  saksiSula(pinValue);
}

void saksiSula(int deger){
  if(pinValue==0) {
    digitalWrite(13,LOW);
  }
  else if(pinValue==1) {
    if(analogRead(A0>1000)){
      while(analogRead(A0)>1000){
        Serial.print("Toprak Kuruluğu: ");
        Serial.print(analogRead(A0));
        Serial.print("\n");
        digitalWrite(13,HIGH);
        delay(2000);
        digitalWrite(13,LOW);
        delay(2000);  
       }
    }
    else{
      digitalWrite(13,LOW);
    }
      
  }
}

void setup()
{
  pinMode(13,OUTPUT);
  pinMode(A0,INPUT);
  Blynk.begin(auth, ssid, pass);
  Serial.begin(9600);
}

void loop()
{
  int d=analogRead(A0);
  Serial.println(d);
  Blynk.run();
}
