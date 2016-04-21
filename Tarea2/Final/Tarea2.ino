#include "T2.h"

//Declaracion de una variable de tipo LEDT
LEDT x;

//Variable usada para realizar la interrupcion
volatile int state;

//Variables para medir el tiempo
long tAnterior=0,tInstante;

void setup() {
    Serial.begin(9600);
    //Inicializacion de la interrupcion
    attachInterrupt(0,parpadeo,RISING);
}

void loop(){
  //Medida del tiempo en milisegundos
  tInstante = millis();
  if(tInstante-tAnterior > 1000){
    tAnterior = tInstante;
    //Encendido o apagado de los leds
    x.red(state);
    x.green(!state);
  }
  
}

//Funcion que cambia la variable para la interrupcion
void parpadeo(){
 state = !state; 
}



