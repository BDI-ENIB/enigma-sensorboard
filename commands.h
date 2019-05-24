#ifndef COMMANDS_H
#define COMMANDS_H 1

#include <Arduino.h>

#include "pinout.h"

namespace enigma {
namespace serial {

/**
 * Call : whois;
 * Returns: name;
 */
void whois();

/**
 * Call: dsensors;
 * Returns: numeric value of each sensor, in the order of INPUTS ex: 001010100;
 */
void dsensors();

/**
 * Call: sensorX; with X the sensor number
 * Returns: X;
 *		X: The sensor value
 */
void read(int sensor);

/**
 * Call: setoutsXXXXXXXXX;
 * 		X: numeric value of the output
 * Returns: done;
 */
void outputs(String &values);

/**
 * Activate watching
 * 
 * Call: activate;
 * Returns: done;
 */
void activate();

/**
 * Deactivate watching
 * 
 * Call: deactivate;
 * Returns: done;
 */
void deactivate();

/**
 * Send the occured events
 */
void send_events_if_wanted();

} // namespace enigma
} // namespace serial

#endif
