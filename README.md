## To build in PlatformIO...

Add a folder named `Distribution` at the root of the project. (for the Post Compile script...)

**Build it.**

## To build in Tarduino...

Make sure you have the ESP8266 set up in your copy of Tarduino:

[How to](https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/)

Install the needed libraries:

* ArduinoJson
* PubSubClient
* Adafruit MCP23008 library
* Adafruit INA219
    * (The Adafruit libraries will add in: Adafruit BusIO, Adafruit NeoPixel, Adafruit GFX Library & Adafruit SSD1306.  You don't need them, but you'll get them anyhow.)
* ESP Async WebServer
    * [How to](https://reacoda.gitbook.io/molemi-iot/introducing-the-nodemcu/display-the-dht11-sensor-reading-on-a-web-server-using-nodemcu./installing-dht-library-on-the-esp8266/installing-the-asynchronous-web-server-library)

Create a folder named `AustinHUB` inside your Arduino folder, copy the content of `src` & `include` to that folder & rename `AustinHUB.cpp` to `AustinHUB.ino`

Tell Tarduino to open `AustinHUB.ino`...

Eeewww...  Ick!  :vomiting_face:
