## Classic LED Builtin For Arduino Uno R3, ESP-01, Wemos D1R32, etc... With VS Code + PlatformIO 

1. If needed Install first [ VSCode ](https://code.visualstudio.com/)
2. Then Install [PlatformIO Core](https://docs.platformio.org/page/core.html)
3. PlatformIO is an alternative Tool to code on µControllers boards such as Arduino, ESP, etc...

```cpp
/*
  Example classique de la led embarquée clignotante( LED_BUILTIN )
  Légèrement remanié :
    + Framework : 
        #include <Arduino.h> becôz PlatformiIO
    + Bool state :
        equiv. "LOW" & "HIGH" mais permet un swap rapide( inversion de l'état )
        sans une redondance de digitalWrite()
    + Millis() plutot que delay() :
        millis() impose un bout de code ( calcul du delta )
        mais millis() n'est pas bloquant contrairement a delay() qui met en pause le cpu. 
    
    Testé sur ESP-01S, Arduino UNO R3 et Wemos D1R32
    cFx / Rescigno Franck.
*/
#include <Arduino.h>
bool state = false;
unsigned long t0, t1;

void setup()
{
  // On initialise la sortie digitale reliée à la led embarquée pour une sortie + etat off
  pinMode(LED_BUILTIN, OUTPUT);
  /*
    Utiliser la constante prédéfinie LED_BUILTIN permet une portabilité du code
    d'une carte µcontrolleur à une autre.
    Sur Arduino R3, la led embarquée est reliée au GPIO 13
    Quand sur un ESP-01S elle est reliée au GPIO2
    Seul changement, le fichier de configuration pour cibler la compilation : platformio.ini
  */
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

```
