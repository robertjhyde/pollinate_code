#include "FastLED.h"
int i1 = 0;
int i2 = 0;
int i3 = 8;
int s = 0;

CRGB sun[18];
CRGB leds2[16];

void setup() {
  FastLED.addLeds<NEOPIXEL, 1>(sun, 18);
  FastLED.addLeds<NEOPIXEL, 2>(leds2, 16);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    int inp = Serial.read();
    switch (inp) {
      case '1':
        sun[2] = CRGB::Red;
        if (s = 0) {
          first_ring(); }
        else {
          second_ring();
        }
        s = (s+1)%2;
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


void first_ring(){
  sun[1] = CRGB::Red;
  sun[3] = CRGB::Red;
  sun[6] = CRGB::Red;
  sun[7] = CRGB::Red;
  sun[10] = CRGB::Red;
  sun[12] = CRGB::Red;
  sun[13] = CRGB::Red;
  sun[16] = CRGB::Red;
  sun[0] = CRGB::Black;
  sun[4] = CRGB::Black;
  sun[7] = CRGB::Black;
  sun[8] = CRGB::Black;
  sun[9] = CRGB::Black;
  sun[11] = CRGB::Black;
  sun[14] = CRGB::Black;
  sun[15] = CRGB::Black;
  }
}
  
void second_ring(){
  sun[0] = CRGB::Red;
  sun[4] = CRGB::Red;
  sun[7] = CRGB::Red;
  sun[8] = CRGB::Red;
  sun[9] = CRGB::Red;
  sun[11] = CRGB::Red;
  sun[14] = CRGB::Red;
  sun[15] = CRGB::Red;
  sun[1] = CRGB::Black;
  sun[3] = CRGB::Black;
  sun[6] = CRGB::Black;
  sun[7] = CRGB::Black;
  sun[10] = CRGB::Black;
  sun[12] = CRGB::Black;
  sun[13] = CRGB::Black;
  sun[16] = CRGB::Black;
  }
}
