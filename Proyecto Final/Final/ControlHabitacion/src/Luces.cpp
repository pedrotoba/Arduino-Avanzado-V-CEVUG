#include "Luces.h"

Luz::Luz(){
  pinMode(pinLuz,OUTPUT);
}

void Luz::encenderLuz(){
  digitalWrite(pinLuz,HIGH);
}

void Luz::apagarLuz(){
  digitalWrite(pinLuz,LOW);
}

void Luz::parpadeo(){
  digitalWrite(pinLuz,HIGH);
  delay(200);
  digitalWrite(pinLuz,LOW);
  delay(200);
  
}

