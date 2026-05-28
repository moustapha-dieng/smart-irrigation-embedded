#include <Arduino.h>
#include "sensor.h"

const int SENSOR_PIN = A0;

void sensor_init(void) {
    pinMode(SENSOR_PIN, INPUT);
}

int sensor_read(void) {
    return analogRead(SENSOR_PIN);
}
