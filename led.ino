#include <FastLED.h>
int r = 0;
int s = 0;

CRGB bee[4];

CRGB rain[15];

//CRGB cloud1[3];
//CRGB cloud2[2];

CRGB sun[4];


void setup(){

  FastLED.addLeds<NEOPIXEL, 1>(bee, 4); //bee front+wing
  
  FastLED.addLeds<NEOPIXEL, 2>(rain, 15); //rain
  //FastLED.addLeds<NEOPIXEL, 3>(rain, 3); //midleft drop
  //FastLED.addLeds<NEOPIXEL, 4>(rain, 3); //midright drop
  //FastLED.addLeds<NEOPIXEL, 5>(rain, 3); //right drop
  
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
        bee[1] = CGRB::Yellow;
        bee[2] = CGRB::Yellow;
        bee[3] = CGRB::Yellow;
        bee[4] = CRGB::Yellow;
        FastLED.show();
        break;
      case '2':
        rain[r-1] = CRGB::Black;
        rain[r] = CRGB::Blue;
        r = (r+1)%91;
        FastLED.show();
        break;
      case '3':
        sun[s-1] = CRGB::Black;
        sun[s] = CRGB(250, 145, 25);
        s = (s+1)%91;
        FastLED.show();
        break;
      default:
        bee[1] = CGRB::Black;
        bee[2] = CGRB::Black;
        bee[3] = CGRB::Black;
        bee[4] = CGRB::Black;
        sun[i] = CRGB::Black;
        rain[i] = CRGB::Black;
        FastLED.show();
    
}
