#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 187
#define LED_PIN 23

CRGB leds[NUM_LEDS];

CRGBPalette16 lavaPalette =
    CRGBPalette16{CRGB::DarkRed, CRGB::Maroon,  CRGB::DarkRed, CRGB::Maroon,
                  CRGB::Blue, CRGB::Maroon,  CRGB::DarkRed, CRGB::DarkRed,
                  CRGB::DarkRed, CRGB::DarkRed, CRGB::Red,     CRGB::Orange,
                  CRGB::White,   CRGB::Orange,  CRGB::Red,     CRGB::DarkRed};

uint16_t brightnessScale = 150;
uint16_t indexScale = 10;

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);

  FastLED.setBrightness(75);
  // FastLED.clear(true);
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    uint8_t brightness = inoise8(i * brightnessScale, millis() / 10);
    brightness = 75;
    uint8_t index = inoise8(i * indexScale, millis() / 12);
    leds[i] = ColorFromPalette(lavaPalette, index, brightness);

    // leds[i] = CHSV(CRGB::Red, 255, brightness);
  }
  FastLED.show();
}