#include<Wire.h>
#include

void setup(){
  Serial.begin(9600);
  Wire.begin(4);
  Wire.onReceive(receiveEvent);
}
void loop(){
 delay(500); 
}

void receiveEvent(int howMany){
  while(1<Wire.available()){
    int valorLuz = Wire.read();
    Serial.print("Valor luz: ");
    Serial.print(valorLuz);
    Serial.print('\n');
    
  }
  int valorLuz = Wire.read();
    Serial.print("Valor luz: ");
    Serial.print(valorLuz);
    Serial.print('\n');
}

