#pragma once

#include <Arduino.h>

class InnitConfig {
public:
    static constexpr int MAX_SENSORS = 30;
    static constexpr int MAX_OUTPUTS = 30;
    static constexpr int MAX_ERROR_MESSAGES = 5;

    static constexpr int COUNT_MOVING_AVERAGE = 10;

    static constexpr float LOW_SPEED = 0.4;
    static constexpr float MIDDLE_SPEED = 0.6;
    static constexpr float HIGH_SPEED = 0.9;

  
};
