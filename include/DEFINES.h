
/* Convert a #defined value to a string */
#define ST(A) #A
#define STR(A) ST(A)
////////////////////
// This is probably more complex than it really needs to be...
#define ST2a(A, B) #A
#define ST2b(A, B) #B
#define STR2a(A) ST2a(A)
#define STR2b(B) ST2b(B)
////////////////////

//  Most (if not all) of this should come from platformio.ini when building under PlatformIO.

#ifndef DEFINES_H
#define DEFINES_H

#ifndef DEBUG_BUTTONS
#define DEBUG_BUTTONS      false          // prints out button state
#endif

#ifndef DEBUG_WIFIBUTTONS
#define DEBUG_WIFIBUTTONS  false          // prints out webpage button state
#endif

#ifndef DEBUG_JSON
#define DEBUG_JSON         false          // prints out parsed json
#endif

#ifndef DEBUG_voltage
#define DEBUG_voltage      false          // prints out voltage infomation
#endif

#ifndef DEBUG_current
#define DEBUG_current      false          // prints out current information
#endif

#define LED_PIN            0              // pin neopixels are connected to
#define LED_COUNT          4              // number of neopixels

#ifndef LED_TYPE
#define LED_TYPE           NEO_GRBW       // type of led's used
#endif

#define  mqtt_lwt_qos      0
#define  mqtt_lwt_retain   1

#ifndef FIRMWAREVERSION
#define FIRMWAREVERSION     "1.1.3 :)"
#endif

#endif // DEFINES_H