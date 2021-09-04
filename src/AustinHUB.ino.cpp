# 1 "/tmp/tmptsekkjav"
#include <Arduino.h>
# 1 "/home/tinker/Documents/PlatformIO/AustinHUB/src/AustinHUB.ino"
# 41 "/home/tinker/Documents/PlatformIO/AustinHUB/src/AustinHUB.ino"
#include "LIBRARIES.h"

#include "DEFINES.h"

#include "debug.h"
# 68 "/home/tinker/Documents/PlatformIO/AustinHUB/src/AustinHUB.ino"
#include "config.h"
#include "factory_settings.h"



#include "buttons.h"
#include "varibles.h"
# 96 "/home/tinker/Documents/PlatformIO/AustinHUB/src/AustinHUB.ino"
multiButton button = multiButton();






#include "neopixel.h"


#include "wifisave.h"
#include "processing_items.h"
#include "customserver.h"
#include "wifi.h"

#include "ESP_Color.h"
#include "web_json.h"

#include "ina219.h"
#include "press.h"
#include "MQTT.h"


char * getMqttButtonAction(uint8_t state)
{

  static char action[7];
  switch (state)
  {
    case BUTTON_HOLD_STATE:
      sprintf_P(action, PSTR("HOLD"));
      break;
    case 1:
      sprintf_P(action, PSTR("SINGLE"));
      break;
    case 2:
      sprintf_P(action, PSTR("DOUBLE"));
      break;
    case 3:
      sprintf_P(action, PSTR("TRIPLE"));
      break;
    case 4:
      sprintf_P(action, PSTR("QUAD"));
      break;
    case 5:
      sprintf_P(action, PSTR("PENTA"));
      break;
    default:
      sprintf_P(action, PSTR("ERROR"));
      break;
  }
  return action;
}
void buttonPressed(uint8_t button, uint8_t state);
void setup();
void loop();
#line 150 "/home/tinker/Documents/PlatformIO/AustinHUB/src/AustinHUB.ino"
void buttonPressed(uint8_t button, uint8_t state)
{


  uint8_t raw_button = button;
  uint8_t mqtt_button = raw_button + 1;

  if (overrideMODE == false)
  {
    last_press[raw_button] = state;
    lastINAread[raw_button] = millis();
    lastINAmqtt[raw_button] = millis();
  }
  else
  {
    if (port_state[raw_button] == 10 )
    {
      if (state == 3)
      {
        last_press[raw_button] = state;
      }
    }
    if (port_state[raw_button] == 11 )
    {
      if (state == 3)
      {
        last_press[raw_button] = state;
      }
    }
  }

  if (DEBUG_BUTTONS)
  {
    Serial.print(F("Press detected: "));
    Serial.print(F(" BUTTON: "));
    Serial.print(mqtt_button);
    Serial.print(F(" STATE: "));
    Serial.print(state);
    Serial.print(F(" ACTION: "));
    Serial.println(getMqttButtonAction(state));
  }
      sprintf_P(mqtt_button_buffer, PSTR("{\"BUTTON\":%d, \"ACTION\":\"%s\"}"), mqtt_button, getMqttButtonAction(state));

      MQTT_send(out_topic1, mqtt_button_buffer);
      Serial.print("mqtt output: ");
      Serial.println(mqtt_button_buffer);
}


void setup() {
  Serial.begin(115200);
  delay(500);
  DEBUG_Boot();

  DEBUG_Reset();

  parameterSETUP();


  PRESS_init();
    for (uint8_t o = 0; o < 8; o++)
  {

    PRESS_pinMode(o, OUTPUT);
  }

  portlockout();

PIXELS_init();


  colorWipe(0,0,0,0);

  INA_SETUP();

  wifi_start();

  initWebSocket();

  customInit();

MQTT_init();
# 242 "/home/tinker/Documents/PlatformIO/AustinHUB/src/AustinHUB.ino"
  for (uint8_t i = 0; i < 4; i++)
  {
   button.setup(i, buttons[i]);
  }

  button.onButtonPressed(buttonPressed);

  DEBUG_Running();

}

void loop() {

WEB_cleanupClients();
wifi_checkup();
if (restartRequired){OTA_Restart();}
if (factoryRequired){deleteData();}

  if (WiFi.status() == WL_CONNECTED)
  {
    if (strcmp(mqtt_broker, "0") == 0)
    {}
    else
      MQTT_loop();







  }

  if (connected_update == true)
  {
    success();
  }

voltread();
voltanimation();


if (ws_connected != 0)
{
  if ((millis() - lastUpdate) > 500)
  {
    webSENDjson();
  }
}


if (voltlockout == 0)
{
  button.process();

  handleportstate();
  portsSTATE();
  overrideColor();
}
else
{
  portlockout();
}

}