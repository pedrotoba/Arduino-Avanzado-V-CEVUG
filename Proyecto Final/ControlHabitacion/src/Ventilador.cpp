#include "Ventilador.h"

Ventilador::Ventilador(){
  pinMode(pinVen,OUTPUT);
}

void Ventilador::encenderVen(){
  digitalWrite(pinVen,HIGH);
}

void Ventilador::apagarVen(){
  digitalWrite(pinVen,LOW);
}

