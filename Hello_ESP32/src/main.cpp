#include <Arduino.h>

#define LED 2

// put function declarations here:
//int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED,HIGH);
  delay(1500);
  digitalWrite(LED,LOW);
  delay(500);
  Serial.println("Oi");
}
