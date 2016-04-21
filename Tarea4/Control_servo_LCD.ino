//Control de servo con LCD
//2014 - Sebastián de los Angeles
//Este código se basa en los siguientes tutoriales disponibles en
//la página oficial de Arduino ( http://arduino.cc ):
// Knob: http://arduino.cc/en/Tutorial/Knob de Michal Rinott ( http://people.interaction-ivrea.it/m.rinott )
// LiquidCrystal - "Hello World!": http://arduino.cc/en/Tutorial/LiquidCrystal de Tom Igoe
//

#include <Servo.h> 
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Conexiones del LCD

Servo miServo; //Creación del objeto Servo para acceder al mismo
 
int pot_pin = 0;  // Pin del potenciómetro
int servo_pin = 9; // Pin de control del servo
int val;    // Variable donde almacenaremos el valor del potenciómetro
int val2;   // Variable auxiliar para cálculos con el valor del potenciómetro

void setup() 
{ 
  lcd.begin(16, 2); //Activación del LCD
  miServo.attach(servo_pin);  // Activación del servo en el pin designado
} 
 
void loop() 
{ 
  lcd.setCursor(0,0); //Posicionamiento del cursor en el primer renglón, primera posición del LCD
  lcd.print("Posicion"); //Escribimos "Posición" en el LCD
  
  val = analogRead(pot_pin);             // Lee el valor del potenciómetro (un valor entre 0 y 1023) 
  val2 = map(val, 0, 1023, 0, 179);     // Escalado del valor del potenciómetro para usarlo con el servo (un valor entre 0 y 180) 
  miServo.write(val2);                  // Aplica el valor calculado al servo
  delay(15);  // Demora para esperar a que el servo aplique los cambios indicados
  
  if(val2<100){// Mejora la visualización de los valores en la pantalla, poniendo un 0 delante de los valores menores que 100
    lcd.setCursor(0,1); //Posicionamiento del cursor en el segundo renglón, primera posición del LCD
    lcd.write("0");     //Escribimos el "0" delante
    lcd.setCursor(1,1);
    lcd.print(val2);    // Escribimos el valor que le pasamos al servo en pantalla.
  }
  else{
    lcd.setCursor(0,1); //Posicionamiento del cursor en el segundo renglón, primera posición del LCD
    lcd.print(val2);    // Escribimos el valor que le pasamos al servo en pantalla.
  }
}
