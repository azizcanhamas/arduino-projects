#define TRIG_Pin 2
#define ECHO_Pin 3
#define MOTOR_Pin 4

long sure;
long uzaklik;

void setup() {
  pinMode(TRIG_Pin,OUTPUT);
  pinMode(ECHO_Pin,INPUT);
  pinMode(MOTOR_Pin,OUTPUT);

  Serial.begin(9600);
}

void loop() {
  UZAKLIK_Bul();
  if(uzaklik<5){
    digitalWrite(MOTOR_Pin,HIGH);
    delay(750);
    digitalWrite(MOTOR_Pin,LOW);
    delay(3000);
  }
}

void UZAKLIK_Bul(){
  digitalWrite(TRIG_Pin,LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_Pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_Pin,LOW);
  sure=pulseIn(ECHO_Pin,HIGH);
  uzaklik=sure/29.1/2;
  if(uzaklik>=200){
    uzaklik=200;
  }
  SerialPort_Yaz();
}

void SerialPort_Yaz(){
  Serial.print("Uzaklik :");
  Serial.print(uzaklik);
  Serial.println(" cm");
  delay(100);
}
