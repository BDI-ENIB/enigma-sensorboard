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
      for (int i = 0; i < DIGITAL_SENSORS_LEN; i++) {
        Serial.print(int(digitalRead(DIGITAL_SENSORS[i])));
      }
      Serial.println(";");
    }
  }
}
