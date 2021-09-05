#ifndef DEFINES_H
#define DEFINES_H

#define DEBUG_BUTTONS        true           // prints out button state
#define DEBUG_WIFIBUTTONS    true           // prints out webpage button state
#define DEBUG_JSON           false          // prints out parsed json
#define DEBUG_voltage        false          // prints out voltage infomation
#define DEBUG_current        false          // prints out current information
#define LED_PIN              0              // pin neopixels are connected to -- shouldn't need to be changed
#define LED_COUNT            4              // number of neopixels
#define LED_TYPE             NEO_GRBW       // type of led's used

#define  mqtt_lwt_qos      0
#define  mqtt_lwt_retain   1

#define FIRMWAREVERSION     "1.1.3 :)"

#endif // DEFINES_H