int column[9]={13,12,11,10,9,8,7,6,5};
int layer[3]={A0,A1,A2};

void setup() {
  for(int i=0;i<9;i++){
    pinMode(column[i],OUTPUT);
  }

  for(int i=0;i<3;i++){
    pinMode(layer[i],OUTPUT);
  }
}

void loop() {
  turnOff();
  turnOn();
}

void turnOff(){
  for(int i=0;i<9;i++){
    digitalWrite(column[i],1);
    
  }
  for(int i=0;i<3;i++){
    digitalWrite(layer[i],0);
  }
}

void turnOn(){
  for(int i=0;i<3;i++){
    digitalWrite(layer[i],1);
  }
  for(int i=0;i<9;i++){
    digitalWrite(column[i],0);    
  }
}
