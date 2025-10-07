#include <Arduino.h>
#include <FastLED.h>
#include <MicroOscSlip.h>
MicroOscSlip<128> monOsc(&Serial);

// key unit
#define BROCHE_ATOM_FIL_BLANC 32
// led in key unit
#define BROCHE_ATOM_FIL_JAUNE 26

CRGB keyPixel;

void setup() {
  pinMode( BROCHE_ATOM_FIL_BLANC , INPUT_PULLUP );
  Serial.begin(115200);
  FastLED.addLeds< WS2812, BROCHE_ATOM_FIL_JAUNE , GRB >(&keyPixel, 1); 
}

void loop() {

  // oscslip_bouton
  int maLectureKey = digitalRead( BROCHE_ATOM_FIL_BLANC );
  monOsc.sendInt("/bouton", maLectureKey);
  delay(100);

  // couleur_pixel
  keyPixel = CRGB(255,255,0); 
  FastLED.show();
}