#include <FastLED.h>

CRGB bee[3];
CRGB rain1[2];
CRGB rain2[3];
CRGB rain3[3];
CRGB rain4[3];
CRGB cloud1[3];
CRGB cloud2[2];
CRGB sun[4];


void setup(){

  FastLED.addLeds<NEOPIXEL, 1>(bee, 3); //bee front+wing
  
  FastLED.addLeds<NEOPIXEL, 2>(rain1, 2); //left drop
  FastLED.addLeds<NEOPIXEL, 3>(rain2, 3); //midleft drop
  FastLED.addLeds<NEOPIXEL, 4>(rain3, 3); //midright drop
  FastLED.addLeds<NEOPIXEL, 5>(rain4, 3); //right drop
  
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
  if (Serial.available()) {
    com = Serial.read()
    if com == '1' {
      StateA = (StateA+1)%2; }
    if com == '2' {
      StateB = (StateB+1)%2; }
    if com == '3' {
      StateC = (StateC+1)%2; }
    
    
}
