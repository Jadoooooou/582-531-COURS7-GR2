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

  // 0 et 1 pour appuyer et relacher
  Serial.print(maLectureKey);
  Serial.println();
  delay(100);

  // envoit OSC
  //monOsc.sendInt("/bouton", maLectureKey);
  //delay(100);

  if (maLectureKey == 0) {
    keyPixel = CRGB(255, 255, 0);
     FastLED.show();
  } else {
     keyPixel = CRGB(0, 0, 0);
     FastLED.show();
  }
}