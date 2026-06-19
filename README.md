# InnitLib

InnitLib is a reusable microcontroller library for Arduino-compatible boards.
It provides:
- sensor manager and sensor list
- output manager and output list
- serial telemetry with value pool
- menu manager for button-driven display navigation
- a lightweight application container (`ApplicationInnit`)

## Quick usage

```cpp
#include <Arduino.h>
#include "Innit.h"

ApplicationInnit app;

void setup() {
  app.getSensorManager().createButtonCross("ButtonCross", A1, 511, 697, 838, 930, 6091);
  app.getOutputManager().createSsd1306("Display");
  app.getOutputManager().createMotor(10, 8, 9, 100, "MotorBa");

  // app.getMenuManager().addControll(...)
}

void loop() {
  app.getMenuManager().loop();
  app.getSerialComm().sendingLoop();
}
```

## Library layout

- `app/ApplicationInnit.h` — main application container
- `Sensorik/` — sensors and sensor management
- `Outputs/` — outputs and output management
- `Serial/` — serial telemetry helpers
- `MenuManager/` — button/menu state machine

## Notes

- The library is designed to be configured explicitly from application code.
- `InnitConfig::MAX_SENSORS` and `InnitConfig::MAX_OUTPUTS` control memory use.
