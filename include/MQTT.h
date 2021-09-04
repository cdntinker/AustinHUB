#ifndef mqtt_setup_h
#define mqtt_setup_h

#include <Arduino.h>

void settopics();
void callback(char *topic, byte *payload, unsigned int length);
void reconnect();

void MQTT_init();
void MQTT_loop();

void MQTT_send(const char* Topic, char Buffer[40]);

#endif
