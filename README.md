Classic LED Builtin For Arduino Uno R3 With VS Code + PlatformIO 
================================================================

1. If needed Install first [ VSCode ](https://code.visualstudio.com/)
2. Then Install [PlatformIO Core](https://docs.platformio.org/page/core.html)
3. PlatformIO is an alternative Tool to code on µControllers boards such as Arduino, ESP, etc...

```shell
# Target : Arduino CPP for UNO R3
/*
 * Original Builtin' Blinking LED example for Arduino Uno R3
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 * 
 * 
 */
#include <Arduino.h>

void setup()
{
  Serial.begin( 115200 );
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  // wait for a second
  delay(1000);
  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);
   // wait for a second
  delay(1000);
  Serial.println( " Bouh!" );
}
```
