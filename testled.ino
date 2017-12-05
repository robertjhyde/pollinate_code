#include "FastLED.h"
int i1 = 0;
int i2 = 0;
int i3 = 8;

CRGB leds[7];
CRGB leds2[16];

void setup() {
  FastLED.addLeds<NEOPIXEL, 1>(leds, 7);
  FastLED.addLeds<NEOPIXEL, 2>(leds2, 16);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    int inp = Serial.read();
    switch (inp) {
      case '1':
        leds[i1-1] = CRGB::Black;
        leds[i1] = CRGB::Red;
        leds2[i2-1] = CRGB::Black;
        leds2[i2] = CRGB::Orange;
        i1 = (i1+1)%7;
        i2 = (i2+1)%16;
        FastLED.show();
        break;
      case '2':   
        leds[i1-1] = CRGB::Black;
        leds[i1] = CRGB::Orange;
        leds2[i2-1] = CRGB::Black;
        leds2[i2] = CRGB::Blue;
        leds2[i3-1] = CRGB::Black;
        leds2[i3] = CRGB::Blue;
        i1 = (i1+1)%7;           // set our current dot to red
        i2 = (i2+1)%16;
        i3 = (i3+1)%16;
        FastLED.show();
        break;
      default:
        leds[i1] = CRGB::Black;
        leds2[i2] = CRGB::Black;
        FastLED.show();
    }
  }
}
