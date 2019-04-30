ENIgma SensorBoard
==================

This is the code for the SensorBoard of robots Summer and Winter.

## Serial Interface

All commands end with `;` and all answers end with `;` too.

In the examples, the carets are only there to specify the direction of the message.
`>` are sent to the board and `<` are sent by the board.

### Whois

Permits identification of the board.

Command: `whois`  
Answer: `Name of the board`

Example:
```
> whois;
< SensorBoard;
```

### Digital Sensors

Read all sensors and send their values.

Command: `dsensors`  
Answer: `XXXXXXXX`, where `X` is either `0` or `1` depending on the sensor value.

Example:
```
> dsensors;
< 01000111;
```

### Getting only one value

Reads only the called sensor.

Command: `sensorX`, where `X` is the number of the sensor, from 0 to 7.  
Answer: `X`, where `X` is either `0` or `1` depending on the sensor value.

Examples:
```
> sensor2;
< 0;
> sensor7;
< 1;
```

### Digital Outputs

On this board, each sensor plug comes with a digital output.
This is the command to set their values.

Command: `setoutsXXXXXXXX`, where `X` is the output value for that sensor, either `0` or `1`.  
Answer: `done`, when all outputs are configured.

Example:
```
> setouts01000110;
< done;
```

### (De)Activate watching

Watching can be enabled (and disabled) on the board. See [Watching](#watching) for more info.

Commands: `activate` and `deactivate`  
Answer: `done`

## Watching

Watching can be enabled (and disabled) on the board.
See [(De)Activate watching](#deactivate-watching) for more info on activating and deactivating it.

When watching is enabled, the board will automatically send values if a sensor value changes.
The send data is in the form `sensor#,value` with `sensor#` the number of the sensor
between 0 and 7 and `value` either `0` or `1` depending on the sensor new value.
