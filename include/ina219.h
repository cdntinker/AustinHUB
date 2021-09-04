//
#ifndef ina219_h
#define ina219_h

void INA_SETUP();
void voltread();
void voltanimation();                       // animation of volt conditions on led's
void get_INA(uint8_t port);                 // send what port you need a value calcuated for
void mqtt_INA(uint8_t port, const char *m); // send what port you need a value sent for

#endif
