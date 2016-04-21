#include "T2.h"

LEDT x;
volatile int state;
long tAnterior=0,tInstante;

void setup() {
    Serial.begin(9600);
    attachInterrupt(0,parpadeo,RISING);
}

void loop(){
  tInstante = millis();
  if(tInstante-tAnterior > 1000){
    tAnterior = tInstante;
    x.red(state);
    x.green(!state);
  }
  
}

void parpadeo(){
 state = !state; 
}



