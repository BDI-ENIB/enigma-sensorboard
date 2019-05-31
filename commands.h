#ifndef COMMANDS_H
#define COMMANDS_H 1

#include <Arduino.h>

#include "pinout.h"

#define SAMPLE_NB 40

namespace enigma {
namespace serial {

/**
 * Call : whois;
 * Returns: name;
 */
void whois();

/**
 * Call: dsensors;
 * Returns: sending; and then numeric value of each sensor, the same way as if each sensor was updated, see the Watching doc
 */
void dsensors();

/**
 * Call: sensorX; with X the sensor number
 * Returns: X,Y;
 *		Y: The sensor value
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

/**
 * Update sensors state, used for histeresis cycle
 */
void update();

} // namespace enigma
} // namespace serial

#endif
