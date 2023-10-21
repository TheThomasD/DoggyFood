#include <Arduino.h>
#include <SPI.h>

void setup() {
  Serial.begin(115200);
  pinMode(8, OUTPUT);
}

void loop() {
  Serial.println("Hello World!");
  digitalWrite(8,1);
  delay(1000);
  digitalWrite(8,0);
  delay(1000);
}
