#include "commands.h"

namespace enigma {
namespace serial {

bool send_events=false;
bool last_value[INPUTS_LEN] = {0};

/**
 * Call : whois;
 * Returns: name;
 */
void whois() {
	Serial.println("SensorBoard;");
}

/**
 * Call: dsensors;
 * Returns: numeric value of each sensor, in the order of INPUTS ex: 001100100;
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
 * Call: setoutsXXXXXXXXX;
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
	send_events = true;
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
	send_events = false;
}

void send_events_if_wanted() {
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
} // namespace enigma
} // namespace serial
