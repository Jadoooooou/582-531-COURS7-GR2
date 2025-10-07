#include <Arduino.h>
#include <FastLED.h>
#include <MicroOscSlip.h>
MicroOscSlip<128> monOsc(&Serial);

// key unit
#define BROCHE_ATOM_FIL_BLANC 32
// led in key unit
#define BROCHE_ATOM_FIL_JAUNE 26
// bouton du Atom
#define BROCHE_ATOM_BOUTON 39
// led du Atom
#define BROCHE_ATOM_PIXEL 27

// pixel du key unit
CRGB keyPixel;
// pixel du Atom
CRGB atomPixel;


void setup() {
  pinMode( BROCHE_ATOM_FIL_BLANC , INPUT_PULLUP );
  pinMode( BROCHE_ATOM_BOUTON , INPUT );

  FastLED.addLeds< WS2812, BROCHE_ATOM_FIL_JAUNE , GRB >(&keyPixel, 1); 
  FastLED.addLeds<WS2812, BROCHE_ATOM_PIXEL , GRB>(&atomPixel, 1); 
}

void loop() {

  // oscslip key unit
  int maLectureKey = digitalRead( BROCHE_ATOM_FIL_BLANC );
  // oscslip bouton du Atom
  int maLectureAtomBouton = digitalRead( BROCHE_ATOM_BOUTON );

  delay(100);

  // key unit
  if (maLectureKey == 0) {
    keyPixel = CRGB(255, 255, 0);
  } else {
     keyPixel = CRGB(0, 0, 0);
  }

  // bouton du Atom
  if (maLectureAtomBouton == 0) {
    atomPixel = CRGB(255, 255, 0);
  } else {
    atomPixel = CRGB(0, 0, 0);
  }

  FastLED.show();
}