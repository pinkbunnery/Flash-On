#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(28, 6, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}
void loop() {
  Shine(strip.Color(random(0,256), random(0,256), random(0,256)), 50);
}

void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i <strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void Shine(uint32_t c, uint8_t wait) {
  for (int j = 0; j <10; j++) {
    for (int q = 0; q < 3; q++) {
      for(uint16_t i = 0; i < strip.numPixels(); i = i +3) {
        strip.setPixelColor(i + q, c);
      }
      strip.show();

      delay(wait);

      for(uint16_t i = 0; i < strip.numPixels(); i = i +3) {
        strip.setPixelColor(i + q, 0);
      }
    }
  }
}

