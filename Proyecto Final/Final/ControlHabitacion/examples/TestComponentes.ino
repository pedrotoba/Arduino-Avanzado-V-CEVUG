#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

int boton1 = 7;
int boton2 = 8;
int ledRojo = 10;
int ledVerde = 9;
int estado1 = 0;
int estado2 = 0;

void setup() {
  lcd.begin(16,2);
  pinMode(boton1,INPUT);
  pinMode(boton2,INPUT);
  pinMode(ledRojo,OUTPUT);
  pinMode(ledVerde,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  estado1 = digitalRead(boton1);
  estado2 = digitalRead(boton2);

  if(digitalRead(boton1) == HIGH){
    lcd.setCursor(0,1);
    lcd.write(">Entra if");
    Serial.println("entra");
    digitalWrite(ledVerde,HIGH);
  }
  else{
     lcd.setCursor(0,1);
      lcd.write(">Entra else");
      Serial.println("entra else");
      digitalWrite(ledVerde,LOW);
  }

  delay(500);
 
 }

