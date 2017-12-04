#include <FastLED.h>
int r1 = 0;
int r2 = 0;
int s = 0;

CRGB bee[3];

CRGB rain1[2];
CRGB rain2[3];

CRGB cloud1[3];
CRGB cloud2[2];

CRGB sun[4];


void setup(){

  FastLED.addLeds<NEOPIXEL, 1>(bee, 3); //bee front+wing
  
  FastLED.addLeds<NEOPIXEL, 2>(rain1, 2); //left drop
  FastLED.addLeds<NEOPIXEL, 3>(rain2, 3); //midleft drop
  FastLED.addLeds<NEOPIXEL, 4>(rain2, 3); //midright drop
  FastLED.addLeds<NEOPIXEL, 5>(rain2, 3); //right drop
  
  FastLED.addLeds<NEOPIXEL, 6>(cloud1, 3); //bottom cloud
  FastLED.addLeds<NEOPIXEL, 7>(cloud2, 2); //top cloud
  
  FastLED.addLeds<NEOPIXEL, 8>(sun, 4); //sun1
  FastLED.addLeds<NEOPIXEL, 9>(sun, 4); //sun2
  FastLED.addLeds<NEOPIXEL, 10>(sun, 4); //sun3
  FastLED.addLeds<NEOPIXEL, 11>(sun, 4); //sun4
  FastLED.addLeds<NEOPIXEL, 12>(sun, 4); //sun5
  FastLED.addLeds<NEOPIXEL, 13>(sun, 4); //sun6

}




void loop(){

  // reset
  if (Serial.available() > 0) {
    int com = Serial.read()
    switch (com) {
      case '1';
        bee[1] = CGRB::Yellow
        bee[2] = CGRB::Yellow
        bee[3] = CGRB::Yellow
        FastLED.show();
      case '2':
        rain2[i-1] = CRGB::Black;
        rain2[i] = CRGB::Blue;
        r2 = (r2+1)%91;
        FastLED.show();
      case '3':
        sun[i-1] = CRGB::Black;
        sun[i] = CRGB::Blue;
        s = (s+1)%91;
        FastLED.show();
    
    
}
