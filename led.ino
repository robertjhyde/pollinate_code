#include <FastLED.h>


CRGB bee1[];
CRGB bee2[];
CRGB rain[];
CRGB cloud[];



void setup(){

FastLED.addLeds<NEOPIXEL, 1>(leds, 3); //bee front+wing
FastLED.addLeds<NEOPIXEL, 2>(leds, 2); //bee back

FastLED.addLeds<NEOPIXEL, 3>(leds, 2); //left drop
FastLED.addLeds<NEOPIXEL, 4>(leds, 3); //midleft drop
FastLED.addLeds<NEOPIXEL, 5>(leds, 4); //midright drop
FastLED.addLeds<NEOPIXEL, 6>(leds, 5); //right drop

FastLED.addLeds<NEOPIXEL, 7>(leds, 3); //bottom cloud
FastLED.addLeds<NEOPIXEL, 8>(leds, 2); //top cloud


}




void loop(){

if (Serial.available()) {
  if (Serial.read() – ‘0’) {
  
  }
  // reset
  
  
  
  
  if (Serial.read() – ‘1’) {
  
  }
  // bee puzzle
  
  if (Serial.read() – ‘2’) {
  
  }
  // rain puzzle
  
  if (Serial.read() – ‘3’) {
  
  }
  // sun puzzle
  
  
  
  
  if (Serial.read() – ‘1’) && (Serial.read() - '2') {
  
  }
  // bee and rain
  
  if (Serial.read() – ‘1’) && (Serial.read() - '3') {
  
  }
  // bee and sun
  
  if (Serial.read() – ‘2’) && (Serial.read() - '3') {
  
  }
  // rain and sun
  
  
  
  
  if (Serial.read() – ‘1’) && (Serial.read() - '2') && (Serial.read() - '3') {
  
  }
  // all puzzles



}
