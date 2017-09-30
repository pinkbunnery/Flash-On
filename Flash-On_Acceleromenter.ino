#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_NeoPixel.h>
float oldX, oldY; //decimal number; makes 2 variables
float x, y;
int numLED = 1; //number of LEDs
Adafruit_NeoPixel strip = Adafruit_NeoPixel(28, 6); // (NUMLED, PIN)

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setAccelRange(LIS3DH_RANGE_4_G);

  strip.begin();
  strip.show();
}

void loop() { //this is where the main code goes for the lights

  strip.show();

  x = CircuitPlayground.motionX();        //get x coordinate
  y = CircuitPlayground.motionY();        //get y coordinate

  float difY = oldY - y;
  float difX = oldX - x;

  oldY = y; //oldY and oldX is the loop before the first one 
  oldX = x; 

  if(abs(difY) > 1 || abs(difX) > 1) { //sensitivity level
  //animation below vv
  /* strip.setPixelColor(random(0,1) , random(0,255),random(0,255),random(0,255)); */ //if you were to choose those pins to light up random colors
    strip.setPixelColor(random(0,3) , 255, 255, 255); //(LED, RED, GREEN, BLUE); max color - 255 or (random (starting pin, ending pin - 1), RGB);
    strip.setPixelColor(random(3,7) , 255, 255, 255);
    strip.setPixelColor(random(7,11) , 255, 255, 255);
    strip.setPixelColor(random(11,15) , 255, 255, 255);
    strip.setPixelColor(random(15,19) , 255, 255, 255);
    strip.setPixelColor(random(19,25) , 255, 255, 255); 
    strip.setPixelColor(random(25,29) , 255, 255, 255); //there are 28 NeoPixels on my dress
    strip.show();
    delay(30); //how long the LED will light up for
    strip.clear();
  }

  delay(20); //speed for checking movement
  
}

