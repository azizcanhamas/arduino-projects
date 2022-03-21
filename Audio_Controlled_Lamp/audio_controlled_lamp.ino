#define role 4
#define ses  5

int gurultu_sayaci=1;
int ilk_ses_ani=0;
int ses_suresi=0;

void setup() {
  pinMode(role,OUTPUT);
  digitalWrite(role,HIGH);
  
  pinMode(ses,INPUT);
}

void loop() {
  int ses_durum=digitalRead(ses);
  
  if(ses_durum==1){
    digitalWrite(role,!digitalRead(role));
  } 
}
