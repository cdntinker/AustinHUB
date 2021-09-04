/* animations for neopixel control */

#ifndef neopixel_h
#define neopixel_h

#include <Arduino.h>

void PIXELS_init();
void PIXELS_brightness();

void colorWipe(uint8_t r, uint8_t g, uint8_t b, uint8_t w);

void colorSet(uint8_t c, uint8_t r, uint8_t g, uint8_t b, uint8_t w);

void doubleflash(uint8_t c, uint8_t r, uint8_t g, uint8_t b, uint8_t w, uint8_t r1, uint8_t g1, uint8_t b1, uint8_t w1);
void doubleflashHUB(uint8_t r, uint8_t g, uint8_t b, uint8_t w, uint8_t r1, uint8_t g1, uint8_t b1, uint8_t w1);

/* animation for over / under volt */
void ringupdate();
void voltring(uint8_t r1, uint8_t g1, uint8_t b1, uint8_t w1, uint8_t r2, uint8_t g2, uint8_t b2, uint8_t w2);
void success();
void overrideColor();
#endif
