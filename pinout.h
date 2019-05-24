#ifndef PINOUT_H
#define PINOUT_H 1

#include <Arduino.h>

#define IN1  3
#define OUT1 2

#define IN2  5
#define OUT2 4

#define IN3  7
#define OUT3 6

#define IN4  9
#define OUT4 8

#define IN5  11
#define OUT5 10

#define IN6  A6
#define OUT6 A7

#define IN7  A4
#define OUT7 A5

#define IN8  A2
#define OUT8 A3

#define IN9  A0
#define OUT9 A1

const int INPUTS[]={IN1, IN2, IN3, IN4, IN5, IN6, IN7, IN8, IN9};
const int INPUTS_LEN = (sizeof INPUTS / sizeof INPUTS[0]);

const int OUTPUTS[]={OUT1, OUT2, OUT3, OUT4, OUT5, OUT6, OUT7, OUT8, OUT9};
const int OUTPUTS_LEN = (sizeof OUTPUTS / sizeof OUTPUTS[0]);

#endif
