#include "pinout.h"
#include "commands.h"

void setup() {
	Serial.begin(2000000);

	for (int i = 0; i < INPUTS_LEN; i++)
		pinMode(INPUTS[i], INPUT);
	for (int i = 0; i < OUTPUTS_LEN; i++){
		pinMode(OUTPUTS[i], OUTPUT);
		digitalWrite(OUTPUTS[i], OUTPUT);
	}
}

void loop() {
	if (Serial.available() > 0) {
		// read the incoming byte:
		String message = Serial.readStringUntil(';');

		// test the obtained string to know the received command

		if (message.equals("whois")) {
			enigma::serial::whois();
		}
		else if (message.equals("dsensors")) {
			enigma::serial::dsensors();
		}
		else if (message.equals("activate")) {
			enigma::serial::activate();
		}
		else if (message.equals("deactivate")) {
			enigma::serial::deactivate();
		}
		else if (message.startsWith("setouts")) {
			message.remove(0, 7);
			enigma::serial::outputs(message);
		}
		else if (message.startsWith("sensor")) {
			message.remove(0, 6);
			enigma::serial::read(INPUTS[message.toInt()-1]);
		}
	}

	enigma::serial::send_events_if_wanted();
}
