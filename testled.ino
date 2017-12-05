#include <FastLED.h>
int r1 = 0;
int r2 = 8;
int s = 0;

CRGB bee[4];
CRGB rain[16];
CRGB sun[18];

void setup(){
  FastLED.addLeds<NEOPIXEL, 1>(bee, 4); //bee front+wing  
  FastLED.addLeds<NEOPIXEL, 2>(rain, 16); //rain
  FastLED.addLeds<NEOPIXEL, 8>(sun, 18); //sun
}


void loop(){

  if (Serial.available() > 0) {
    int com = Serial.read();
    switch (com) {
      case '0':
        bee[1] = CRGB::Black;
        bee[2] = CRGB::Black;
        bee[3] = CRGB::Black;
        r1 = 0;
        r2 = 8;
        for (int i=0; i<15; i++) {
          rain[i] = CRGB::Black; }
        s = 0;
        for (int i=0; i<17; i++) {
          sun[i] = CRGB::Black; }
        FastLED.show();
        break;
      case '1':
        bee[1] = CRGB::Yellow;
        bee[2] = CRGB::Yellow;
        bee[3] = CRGB::Yellow;
        break;
      case '2':
        rain[r1-1] = CRGB::Black;
        rain[r1] = CRGB::Blue;
        rain[r2-1] = CRGB::Black;
        rain[r2] = CRGB::Blue;
        r1 = (r1+1)%16;
        r2 = (r2+1)%16;
        FastLED.show();
        break;
      case '3':
        sun[2] = CRGB::Red;
        if (s = 0) {
          first_ring(); }
        else {
          second_ring();
        }
        s = (s+1)%2;
        FastLED.show();
        break;
      default:
        int nothing;
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
