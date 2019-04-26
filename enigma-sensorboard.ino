#include "pinout.h"

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    String message = Serial.readStringUntil(';');
    if (message.equals("whois")) {
      Serial.println("SensorBoard;");
    }
  }
}
