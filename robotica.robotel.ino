int enA=6; 
int in1=A0;
int in2=A1;
int in3=A2;
int in4=A3;
int enB=5;
int r=11;
int Left=A4;
int centru = A6;
int Right = A5;

const int trigPin= 8;
const int echoPin = 7;
long duration;
int distance;



void setup() {

pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);

pinMode(enA,OUTPUT);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);

pinMode(enB,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);

pinMode(r,OUTPUT);

pinMode(Left,INPUT);
pinMode(Right,INPUT);
pinMode(centru,INPUT);

}





void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration=pulseIn(echoPin, HIGH);
  
  distance = duration*0.034/2;
  
  Serial.print("distance = ");
  Serial.print(distance);
  Serial.print("\n");
  
  if(distance<30){stop();
  } else if(digitalRead(Left)==0 && digitalRead(Right)==0){
          mersDrept();
  } else if(digitalRead(Left)==0 && !digitalRead(Right)==0){
          virajStanga();
  } else if(!digitalRead(Left)==0 && digitalRead(Right)==0){
          virajDreapta();
  } else if(!digitalRead(Left)==0 && !digitalRead(Right)==0){
          stop();
}
}



void stop(){

  analogWrite(enA, 0); // Any value between 0 and 255
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  

  analogWrite(enB, 0); // Any value between 0 and 255
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  
}


void mersDrept(){
  
  analogWrite(enA, 200); // Any value between 0 and 255
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  
  

  analogWrite(enB, 200); // Any value between 0 and 255
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
  
}

void virajStanga(){
  
  analogWrite(enA, 200); // Any value between 0 and 255
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  analogWrite(enB, 200); // Any value between 0 and 255
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void virajDreapta(){
  
  analogWrite(enA, 200); // Any value between 0 and 255
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  
  analogWrite(enB, 200); // Any value between 0 and 255
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
  
}

void mersSpate(){
  
  analogWrite(enA, 200); // Any value between 0 and 255
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  

  analogWrite(enB, 200); // Any value between 0 and 255
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
}
