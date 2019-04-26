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
    else if (message.equals("dsensors")) {
      for (int i = 2; i <= 10; i++) {
        Serial.print(int(digitalRead(i)));
      }
      Serial.println(";");
    }
  }
}
