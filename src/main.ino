#include <Arduino.h>
#include "sensor.h"

#define LED_PIN 13
#define HUMIDITY_THRESHOLD 400

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    int humidity = sensor_read();

    if (humidity < HUMIDITY_THRESHOLD) {
        digitalWrite(LED_PIN, HIGH);
    } else {
        digitalWrite(LED_PIN, LOW);
    }

    delay(1000);
}
