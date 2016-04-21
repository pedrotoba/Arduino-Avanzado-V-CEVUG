#include "T2.h"

LEDT::LEDT(){
 pinMode(R1,OUTPUT);
 pinMode(R2,OUTPUT);
 pinMode(V1,OUTPUT);
}

void LEDT::highAll(){
  digitalWrite(R1,HIGH);
  digitalWrite(R2,HIGH);
  digitalWrite(V1,HIGH);
}
void LEDT::lowAll(){
  digitalWrite(R1,LOW);
  digitalWrite(R2,LOW);
  digitalWrite(V1,LOW);
}
void LEDT::Parpadear(){
  highAll();
  delay(1000);
  lowAll();
  delay(1000);
}

void LEDT::red(volatile int estado){
    digitalWrite(R1,estado);
    digitalWrite(R2,estado);
}

void LEDT::green(volatile int estado){
    digitalWrite(V1,estado);
}

