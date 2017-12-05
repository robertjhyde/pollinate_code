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
  FastLED.addLeds<NEOPIXEL, 1>(bee, 4); //bee front+wing  
  FastLED.addLeds<NEOPIXEL, 2>(rain, 16); //rain
  FastLED.addLeds<NEOPIXEL, 8>(sun, 18); //sun
  Serial.begin(9600);
}


void loop(){

  if (Serial.available() > 0) {
    int com = Serial.read();
    switch (com) {
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
        
  if (StateC == 1) { //write these manually in functions
    sun[2] = CRGB::Red;
    if (s = 0) {
      first_ring(); }
    else {
      second_ring();
    }
    s = (s+1)%2;
    FastLED.show(); }
  else {
    for (int i=0; i<17; i++) {
    sun[i] = CRGB::Black; }
    FastLED.show();
  }

}
  
  
void first_ring(){
  sun[1] = CRGB::Orange;
  sun[3] = CRGB::Orange;
  sun[6] = CRGB::Orange;
  sun[7] = CRGB::Orange;
  sun[10] = CRGB::Orange;
  sun[12] = CRGB::Orange;
  sun[13] = CRGB::Orange;
  sun[16] = CRGB::Orange;
  sun[0] = CRGB::Black;
  sun[4] = CRGB::Black;
  sun[7] = CRGB::Black;
  sun[8] = CRGB::Black;
  sun[9] = CRGB::Black;
  sun[11] = CRGB::Black;
  sun[14] = CRGB::Black;
  sun[15] = CRGB::Black;
}
  
void second_ring(){
  sun[0] = CRGB::Orange;
  sun[4] = CRGB::Orange;
  sun[7] = CRGB::Orange;
  sun[8] = CRGB::Orange;
  sun[9] = CRGB::Orange;
  sun[11] = CRGB::Orange;
  sun[14] = CRGB::Orange;
  sun[15] = CRGB::Orange;
  sun[1] = CRGB::Black;
  sun[3] = CRGB::Black;
  sun[6] = CRGB::Black;
  sun[7] = CRGB::Black;
  sun[10] = CRGB::Black;
  sun[12] = CRGB::Black;
  sun[13] = CRGB::Black;
  sun[16] = CRGB::Black;
}
