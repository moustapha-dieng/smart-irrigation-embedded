#include <Arduino.h>
#include "sensor.h"

#define SENSOR_PIN A0

int sensor_read(void) {
    int value = analogRead(SENSOR_PIN);
    return value;
}
