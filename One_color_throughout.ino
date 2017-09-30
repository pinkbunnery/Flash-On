#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

#define NUMPIXELS 28

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
}

void loop() {

  for(int i=0;i<NUMPIXELS;i++){
    
  pixels.setPixelColor(i, pixels.Color(255,0,0)); // (Red, Green, Blue)

  pixels.show();

  }

}

