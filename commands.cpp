#include "commands.h"

namespace enigma {
namespace serial {

bool send_events=false;
bool last_value[INPUTS_LEN] = {0};
bool value_buffer[INPUTS_LEN][SAMPLE_NB] = {0};

void whois() {
	Serial.print("SensorBoard;");
}

void dsensors() {
	for (int i = 0; i < INPUTS_LEN; i++) {
		Serial.print(i);
		Serial.print(",");
		Serial.print(value_buffer[i][SAMPLE_NB-1]);
		Serial.print(";");
	}
}

void read(int sensor) {
	Serial.print(sensor);
	Serial.print(",");
	Serial.print(value_buffer[sensor][SAMPLE_NB-1]);
	Serial.print(";");
}

void outputs(String &values) {
	for (int i = 0; i < OUTPUTS_LEN; ++i) {
		if (values[i] == '1'){
			digitalWrite(OUTPUTS[i], HIGH);
		} else {
			digitalWrite(OUTPUTS[i], LOW);
		}
	}
	Serial.print("done;");
}

void activate() {
	send_events = true;
	for (int i = 0; i < INPUTS_LEN; ++i)
	{
		last_value[i] = value_buffer[i][SAMPLE_NB-1];
	}
	Serial.print("done;");
}

void deactivate() {
	send_events = false;
	Serial.print("done;");
}

/**
 * Send the occured events
 */
void send_events_if_wanted() {
	if (send_events) {
		for (int i = 0; i < INPUTS_LEN; ++i)
		{
			bool val = value_buffer[i][SAMPLE_NB-1];
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

/**
 * Update sensors state, used for histeresis cycle
 */
void update() {
	for (int i = 0; i < INPUTS_LEN; i++) {
		const bool val = digitalRead(INPUTS[i]);
		if (val) {
			for (int j = 0; j < SAMPLE_NB; j++) {
				value_buffer[i][j] = 1;
			}
			bool old = value_buffer[i][1];
		} else {
			for (int j = SAMPLE_NB-1; j > 0; j--) {
				value_buffer[i][j] = value_buffer[i][j-1];
			}
			value_buffer[i][0] = 0;
		}
	}
	delay(20);
}


} // namespace enigma
} // namespace serial
