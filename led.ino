#include <FastLED.h>
int r1 = 0;
int r2 = 8;
int s = 0;
int StateA = 0;
int StateB = 0;
int StateC = 0;

CRGB bee[5];

CRGB rain[16];

CRGB sun[4];


void setup(){

  FastLED.addLeds<NEOPIXEL, 1>(bee, 5); //bee front+wing
  
  FastLED.addLeds<NEOPIXEL, 2>(rain, 16); //rain
  
  FastLED.addLeds<NEOPIXEL, 8>(sun, 4); //sun1
  FastLED.addLeds<NEOPIXEL, 9>(sun, 3); //sun2
  FastLED.addLeds<NEOPIXEL, 10>(sun, 3); //sun3
  FastLED.addLeds<NEOPIXEL, 11>(sun, 3); //sun4
  FastLED.addLeds<NEOPIXEL, 12>(sun, 3); //sun5
  FastLED.addLeds<NEOPIXEL, 13>(sun, 3); //sun6

}




void loop(){

  // reset
  if (Serial.available() > 0) {
    int com = Serial.read()
    switch (com) {
      case '1';
        StateA = (StateA+1)%2
        break;
      case '2':
        StateB = (StateB+1)%2
        break;
      case '3':
        StateC = (StateC+1)%2
        break;
      default:
        //do i need this?
  }
      
  if StateA == 1: {
    bee[1] = CGRB::Yellow;
    bee[2] = CGRB::Yellow;
    bee[3] = CGRB::Yellow;
    bee[4] = CRGB::Yellow;
    FastLED.show();
  }
  else: {
    bee[1] = CGRB::Black;
    bee[2] = CGRB::Black;
    bee[3] = CGRB::Black;
    bee[4] = CRGB::Black;
    FastLED.show();
  }
    
  if StateB == 1: {
    rain[r1-1] = CRGB::Black;
    rain[r1] = CRGB::Blue;
    rain[r2-1] = CRGB::Black;
    rain[r2] = CRGB::Blue;
    r1 = (r1+1)%16;
    r2 = (r2+1)%16;
    FastLED.show();
  }
  else: {
    rain[r1] = CRGB::Black;
    rain[r2] = CRGB::Black;
    FastLED.show();
  }
        
  if StateC == 1: {
    sun[s-1] = CRGB::Black;
    sun[s] = CRGB(250, 145, 25);
    s = (s+1)%4;
    FastLED.show();
  }
  else: {
    sun[s] = CRGB::Black;
    FastLED.show();
  }
        
}
