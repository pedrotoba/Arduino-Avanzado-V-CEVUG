#include<EEPROM.h>
#include <Wire.h>

int analogPin = 0;
int Direccion = 0;
int DirEnvio=0;
int valorMem = 0;
bool mostrado = false;

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  if(Direccion != 100){
    int valorLuz = analogRead(analogPin);
    EEPROM.write(Direccion,valorLuz);
    //int a = EEPROM.read(Direccion);
    Serial.print("Estoy en direccion/valor = ");
    Serial.print(Direccion);
    Serial.print("/");
    int a = EEPROM.read(Direccion);
    Serial.print(a);
    Serial.print('\n');
    Direccion = Direccion+1;
    mostrado = false;
  }else{
    if(!mostrado){
      Serial.print("Enviado datos...");
      Serial.print('\n');
      mostrado = true;
    }
    Wire.beginTransmission(4);
    valorMem = EEPROM.read(DirEnvio);
    Wire.write(valorMem);
    Wire.endTransmission();
    DirEnvio = DirEnvio+1;
    //Serial.print(valorLuz);
    //Serial.print('\n');
  }
  if(DirEnvio == 100){
   Direccion = 0;
   DirEnvio = 0; 
  }
  delay(200);

}

