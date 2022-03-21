#define trig 2
#define echo 3
#define sag_Motor_Enable 5
#define sag_Ileri 6
#define sag_Geri 7
#define sol_Ileri 8
#define sol_Geri 9
#define sol_Motor_Enable 10

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

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(5);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  sure=pulseIn(echo,HIGH);

  mesafe=sure/29.1/2;

  Serial.print("Mesafe :  ");
  Serial.print(mesafe);
  Serial.println(" cm");

  if(mesafe<15){
    geri();
    delay(500);
    sol();    
    delay(250);
  }

  else{
    ileri();
  }
}

void ileri(){
  digitalWrite(sol_Geri,LOW);
  digitalWrite(sag_Geri,LOW);
  
  digitalWrite(sol_Ileri,HIGH);
  digitalWrite(sag_Ileri,HIGH);
  
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

void sol(){
  digitalWrite(sol_Ileri,LOW); 
  digitalWrite(sag_Geri,LOW);
  
  digitalWrite(sag_Ileri,HIGH);
  digitalWrite(sol_Geri,HIGH);
  
  analogWrite(sag_Motor_Enable,150);
  analogWrite(sol_Motor_Enable,150);
}
