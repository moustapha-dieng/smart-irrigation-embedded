#include <Arduino.h>
#include "sensor.h"

#define SENSOR_PIN A0

void sensor_init(void) {
}

int sensor_read(void) {
    return analogRead(SENSOR_PIN);
}
