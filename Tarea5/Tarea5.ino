
int potPin = A0;
int valorPot = 0;

void setup() {
 Serial.begin(9600);
}

void loop() {
    valorPot = analogRead(potPin)/4;
    Serial.write(valorPot);
    delay(10);  // we have to make a delay to avoid overloading the serial port
}
