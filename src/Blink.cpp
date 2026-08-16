/*
 * Original Builtin' Blinking LED example for Arduino Uno R3
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include <Arduino.h>
bool state = true;
void setup()
{
  Serial.begin( 115200 );
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  // turn the LED on & off on a single line
  digitalWrite(LED_BUILTIN, state = !state);
  delay(1000);
}
