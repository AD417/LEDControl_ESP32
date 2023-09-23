#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 60
// put function declarations here:
int myFunction(int, int);
CRGB leds[NUM_LEDS];
int itr = 0;

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2811, 12, BRG>(leds, NUM_LEDS);
  Serial.begin(9600);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  itr++;
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = (i + itr) % 2 == 0 ? CRGB::Red : CRGB::Blue;
  }
  FastLED.show();
  Serial.println("ON!");
  delay(250);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}