#ifndef PINOUT_H
#define PINOUT_H 1

#define IN0  2
#define OUT0 3

#define IN1  4
#define OUT1 5

#define IN2  6
#define OUT2 7

#define IN3  8
#define OUT3 9

#define IN4  A0
#define OUT4 A1

#define IN5  A2
#define OUT5 A3

#define IN6  A4
#define OUT6 A5

#define IN7  A6
#define OUT7 A7

const int INPUTS[]={IN0, IN1, IN2, IN3, IN4, IN5, IN6, IN7};
const int INPUTS_LEN = (sizeof INPUTS / sizeof INPUTS[0]);

const int OUTPUTS[]={OUT0, OUT1, OUT2, OUT3, OUT4, OUT5, OUT6, OUT7};
const int OUTPUTS_LEN = (sizeof OUTPUTS / sizeof OUTPUTS[0]);

#endif
