extern "C"
{
  volatile long unsigned timer0_millis = 0;
}

#include <FastLED.h>
#include "SparkFun_SCD30_Arduino_Library.h" //Click here to get the library: http://librarymanager/All#SparkFun_SCD30
#include <Wire.h>

#define NUM_LEDS 4
#define DATA_PIN 7
#define LED_Type WS2812B
CRGB leds[NUM_LEDS];

SCD30 airSensor;

int co2_ppm;
void setup()
{
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  Wire.begin();
  delay(2000);

  // Start sensor using the Wire port, but disable the auto-calibration
  if (airSensor.begin(Wire, false) == false)
  {
    //  // shows red blinking when no sensor is connected
    fill_solid(leds, NUM_LEDS, CRGB(0, 100, 0));
    FastLED.show();
    delay(500);
    fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
    FastLED.show();
    delay(500);
    fill_solid(leds, NUM_LEDS, CRGB(0, 100, 0));
    FastLED.show();
    delay(500);
    fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
    FastLED.show();
    delay(500);
    fill_solid(leds, NUM_LEDS, CRGB(0, 100, 0));
    FastLED.show();
    delay(500);
    fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
    FastLED.show();
    delay(500);
    fill_solid(leds, NUM_LEDS, CRGB(0, 100, 0));
    delay(1000);
    fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
    FastLED.show();
    delay(1000);
    fill_solid(leds, NUM_LEDS, CRGB(0, 100, 0));
    FastLED.show();
    delay(1000);
    fill_solid(leds, NUM_LEDS, CRGB(0, 100, 0));
    FastLED.show();
    delay(1000);
    while (1)
      ;
  }
}

void loop()
{
  if (airSensor.dataAvailable())
  {
    co2_ppm = airSensor.getCO2();
  }
  else

      if (co2_ppm < 1000) // Sets light to green when ppm is below or same as 1000
  {
    for (int i = 0; i < 4; i++)
    {
      leds[i].setRGB(200, 0, 0);
      FastLED.show();
      delay(500);
    }
  }

  if ((co2_ppm > 1000) && (co2_ppm < 2000)) // Sets light to yellow when ppm is between 1000 and 2000
  {
    for (int i = 0; i < 4; i++)
    {
      leds[i].setRGB(245, 221, 7);
      FastLED.show();
      delay(500);
    }
  }

  if (co2_ppm > 2000) // Sets light to green when ppm is above or same as 2000
  {
    for (int i = 0; i < 4; i++)
    {
      leds[i].setRGB(0, 200, 0);
      FastLED.show();
      delay(500);
    }
  }
  delay(500);
}