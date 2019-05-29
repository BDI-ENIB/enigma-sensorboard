#include "commands.h"

namespace enigma {
namespace serial {

bool send_events=false;
bool last_value[INPUTS_LEN] = {0};

void whois() {
	Serial.print("SensorBoard;");
}

void dsensors() {
	for (int i = 0; i < INPUTS_LEN; i++) {
		Serial.print(i);
		Serial.print(",");
		Serial.print(int(digitalRead(INPUTS[i])));
		Serial.print(";");
	}
}

void read(int sensor) {
	Serial.print(sensor);
	Serial.print(",");
	Serial.print(int(digitalRead(sensor)));
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
		last_value[i] = digitalRead(INPUTS[i]);
	}
}

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
