#include "pinout.h"

bool send_events = FALSE;
bool last_value[INPUTS_LEN] = {0};

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

/**
 * Activate watching
 * 
 * Call: activate;
 * Returns: done;
 */
void activate() {
	send_events = TRUE;
	for (int i = 0; i < INPUTS_LEN; ++i)
	{
		last_value[i] = digitalRead(INPUTS[i]);
	}
}

/**
 * Dectivate watching
 * 
 * Call: deactivate;
 * Returns: done;
 */
void deactivate() {
	send_events = FALSE;
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
		else if (message.equals("activate")) {
			activate();
		}
		else if (message.equals("deactivate")) {
			deactivate();
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

	if (send_events) {
		for (int i = 0; i < INPUTS_LEN; ++i)
		{
			bool val = digitalRead(INPUTS[i]);
			if (val != last_value[i]) {
				Serial.print(i);
				Serial.print(",");
				Serial.print(int(val));
				Serial.print(";");
				last_value[i] = val;
			}
		}
	}
}
