/*
 * Original Builtin' Blinking LED example for Arduino Uno R3
 * Turns on an LED on foran half second,
 * Then off for the same time, repeatedly.
*/
#include <Arduino.h>
bool state = false;
unsigned long t0, t1;

void setup()
{
  // Initialize LED digital pin as an output + state off
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, state);
  t0 = t1 = millis();
}

void loop()
{
  if (t1 - t0 > 500)
  {
    digitalWrite(LED_BUILTIN, state = !state );
    t0 = t1;
  } else { t1 = millis(); }
}
