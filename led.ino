#include <FastLED.h>
int r1 = 0;
int r2 = 8;
int s = 0;
int StateA = 0;
int StateB = 0;
int StateC = 0;

CRGB bee[4];
CRGB rain[16];
CRGB sun[18];

void setup(){
  FastLED.addLeds<NEOPIXEL, 1>(bee, 4); 
  FastLED.addLeds<NEOPIXEL, 2>(rain, 16);
  FastLED.addLeds<NEOPIXEL, 8>(sun, 18);
  Serial.begin(9600);
}


void loop(){

  if (Serial.available() > 0) {
    int com = Serial.read();
    switch (com) {
      case '0':
        StateA = 0;
        StateB = 0;
        StateC = 0;
        break;
      case '1':
        StateA = (StateA+1)%2;
        break;
      case '2':
        StateB = (StateB+1)%2;
        break;
      case '3':
        StateC = (StateC+1)%2;
        break;
      default:
        int nothing;
    }
  }
  
  
  if (StateA == 1) {
    bee[1] = CRGB::Yellow;
    bee[2] = CRGB::Yellow;
    bee[3] = CRGB::Yellow;
    FastLED.show(); }
  else {
    bee[1] = CRGB::Black;
    bee[2] = CRGB::Black;
    bee[3] = CRGB::Black;
    FastLED.show();
  }
    
  if (StateB == 1) {
    rain[r1-1] = CRGB::Black;
    rain[r1] = CRGB::Blue;
    rain[r2-1] = CRGB::Black;
    rain[r2] = CRGB::Blue;
    r1 = (r1+1)%16;
    r2 = (r2+1)%16;
    FastLED.show(); }
  else {
    r1 = 0;
    r2 = 8;
    for (int i=0; i<15; i++) {
      rain[i] = CRGB::Black; }
    FastLED.show();
  }
        
  if (StateC == 1) {
    sun[2] = CRGB::Orange;
    FastLED.show()
    if (s == 0) {
      first_ring(1);
      second_ring(0);
    }
    if (s == 1) {
      second_ring(1);
      first_ring(0);
    }
    s = (s+1)%2;
  }
  else {
    sun[2] = CRGB::Black;
    FastLED.show();
    first_ring(0);
    second_ring(0);
  }
}
  
  
void first_ring(boolean state){
  if (state == 1) {
  sun[1] = CRGB::Orange;
  sun[3] = CRGB::Orange;
  sun[6] = CRGB::Orange;
  sun[7] = CRGB::Orange;
  sun[10] = CRGB::Orange;
  sun[12] = CRGB::Orange;
  sun[13] = CRGB::Orange;
  sun[16] = CRGB::Orange; }
  if (state == 0) {
  sun[1] = CRGB::Black;
  sun[3] = CRGB::Black;
  sun[6] = CRGB::Black;
  sun[7] = CRGB::Black;
  sun[10] = CRGB::Black;
  sun[12] = CRGB::Black;
  sun[13] = CRGB::Black;
  sun[16] = CRGB::Black; }
  FastLED.show();
}
  
void second_ring(boolean state){
  if (state == 1) {
  sun[0] = CRGB::Orange;
  sun[4] = CRGB::Orange;
  sun[7] = CRGB::Orange;
  sun[8] = CRGB::Orange;
  sun[9] = CRGB::Orange;
  sun[11] = CRGB::Orange;
  sun[14] = CRGB::Orange;
  sun[15] = CRGB::Orange; }
  if (state == 0) {
  sun[0] = CRGB::Black;
  sun[4] = CRGB::Black;
  sun[7] = CRGB::Black;
  sun[8] = CRGB::Black;
  sun[9] = CRGB::Black;
  sun[11] = CRGB::Black;
  sun[14] = CRGB::Black;
  sun[15] = CRGB::Black; }
  FastLED.show();
}
