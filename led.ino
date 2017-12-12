#include <FastLED.h> //import and use the FastLED code library
int r1 = 0; //a variable to control which rain drop is on at a point in time
int r2 = 8; //a variable to control the second rain drop that is on at a point in time
int s = 0; //a variable to control which ring of the sun is to be illuminated
int StateA = 0; //a variable to determine if the bee LEDs should be on
int StateB = 0; //a variable to determine if the rain LEDs should be on
int StateC = 0; //a variable to determine if the sun LEDs should be on

CRGB bee[4]; //naming the LED strips in the FastLED library
CRGB rain[16];
CRGB sun[18];

void setup(){
  FastLED.addLeds<NEOPIXEL, 1>(bee, 4); 
  FastLED.addLeds<NEOPIXEL, 2>(rain, 16);
  FastLED.addLeds<NEOPIXEL, 8>(sun, 18);
  Serial.begin(9600); //refresh rate of 9600 bits per second
}


void loop(){

  if (Serial.available() > 0) {
    int com = Serial.read();
    switch (com) {
      case '0':
        StateA = 0;
        StateB = 0;
        StateC = 0;
        break; //otherwise the switch case will run through all cases when one is triggered
      case '1':
        StateA = (StateA+1)%2;
        break;
      case '2':
        StateB = (StateB+1)%2;
        break;
      case '3':
        StateC = (StateC+1)%2;
        break;
      default: //nessessary, if a serial input is anything other than the cases above
        int nothing;
    }
  }
  
  
  if (StateA == 1) {
    bee[1] = CRGB::Yellow; //sets the number 1 LED in the bee strip to the colour Yellow
    bee[2] = CRGB::Yellow;
    bee[3] = CRGB::Yellow;
    FastLED.show(); }
  else {
    bee[1] = CRGB::Black; //sets the number 1 LED in the bee strip to the colour Black (off)
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
    for (int i=0; i<15; i++) { //loops for each LED in the strip
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


void first_ring(boolean state){ //function to turn on/off the first ring of the sun LEDs
  if (state == 1) { //if input is a 1, turn on
  sun[1] = CRGB::Orange;
  sun[3] = CRGB::Orange;
  sun[6] = CRGB::Orange;
  sun[7] = CRGB::Orange;
  sun[10] = CRGB::Orange;
  sun[12] = CRGB::Orange;
  sun[13] = CRGB::Orange;
  sun[16] = CRGB::Orange; }
  if (state == 0) { //if input is a 0, turn off
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
  
void second_ring(boolean state){ //function to turn on/off the second ring of the sun LEDs
  if (state == 1) { //if input is a 1, turn on
  sun[0] = CRGB::Orange;
  sun[4] = CRGB::Orange;
  sun[7] = CRGB::Orange;
  sun[8] = CRGB::Orange;
  sun[9] = CRGB::Orange;
  sun[11] = CRGB::Orange;
  sun[14] = CRGB::Orange;
  sun[15] = CRGB::Orange; }
  if (state == 0) { //if input is a 0, turn off
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
