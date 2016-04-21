int pinLedR = 13;
int pinLedV = 12;
int pot;
int boton=2;
long tAnterior,tInstante;
int estado = 0;

void setup() {
  pinMode(pinLedR,OUTPUT);
  pinMode(pinLedV,OUTPUT);
  pinMode(boton,INPUT);
  Serial.begin(9600);
}

void loop() {
  
  tInstante = millis();
  pot = analogRead(0);
  
  //Medida de tiempos
  Serial.print("Tiempo: ");
  Serial.print(tInstante-tAnterior);
  Serial.print("\n");
  tAnterior = tInstante;
  
  //Mostrar por consola el valor del potenciometro
  Serial.print("Valor potenciometro: ");
  Serial.print(pot);
  Serial.print("\n");
  delay(500);
  
  estado = digitalRead(boton);
  
  if(estado == HIGH){ //Para el led rojo
   if(pot <=500){
     digitalWrite(pinLedR,LOW);
     digitalWrite(pinLedV,LOW);
   }
   else{
     digitalWrite(pinLedR,HIGH);
     digitalWrite(pinLedV,LOW);
   }
  }
  else{ //Para el led verde
   if(pot <=500){
     digitalWrite(pinLedV,LOW);
     digitalWrite(pinLedR,LOW);
   }
   else{
     digitalWrite(pinLedV,HIGH);
     digitalWrite(pinLedR,LOW);
   }
  }

}
