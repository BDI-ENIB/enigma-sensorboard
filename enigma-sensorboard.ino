#include "pinout.h"

void setup() {
	Serial.begin(9600);

	for (int i = 0; i < INPUTS_LEN; i++)
		pinMode(INPUTS[i], INPUT);
	for (int i = 0; i < OUTPUTS_LEN; i++){
		pinMode(OUTPUTS[i], OUTPUT);
		digitalWrite(OUTPUTS[i], OUTPUT);
	}
}

/**
 * Call : whois;
 * Returns: name;
 */
void whois() {
	Serial.println("SensorBoard;");
}

/**
 * Call: dsensors;
 * Returns: numeric value of each sensor, in the order of INPUTS ex: 00100100;
 */
void dsensors() {
	for (int i = 0; i < INPUTS_LEN; i++) {
		Serial.print(int(digitalRead(INPUTS[i])));
	}
	Serial.println(";");
}

/**
 * Call: sensorX; with X the sensor number
 * Returns: X;
 *		X: The sensor value
 */
void read(int sensor) {
	Serial.print(int(digitalRead(sensor)));
	Serial.println(";");
}

/**
 * Call: setoutsXXXXXXXX;
 * 		X: numeric value of the output
 * Returns: done;
 */
void outputs(String &values) {
	for (int i = 0; i < OUTPUTS_LEN; ++i) {
		if (values[i] == '1'){
			digitalWrite(OUTPUTS[i], HIGH);
		} else {
			digitalWrite(OUTPUTS[i], LOW);
		}
	}
	Serial.println("done;");
}

void loop() {
	if (Serial.available() > 0) {
		// read the incoming byte:
		String message = Serial.readStringUntil(';');

		// test the obtained string to know the received command

		if (message.equals("whois")) {
			whois();
		}
		else if (message.equals("dsensors")) {
			dsensors();
		}
		else if (message.startsWith("setouts")) {
			message.remove(0, 7);
			outputs(message);
		}
		else if (message.startsWith("sensor")) {
			message.remove(0, 6);
			read(INPUTS[message.toInt()]);
		}
	}
}
