#include <Arduino.h>
#include "sensor.h"
#include "actuator.h"

#define HUMIDITY_THRESHOLD 700  // seuil calibré selon tes tests

void setup() {
    Serial.begin(9600);
    sensor_init();
    actuator_init();
}

void loop() {
    int humidity = sensor_read();
    Serial.println(humidity);

    if (humidity > HUMIDITY_THRESHOLD) {
    led_on();
    pump_on();
} else {
    led_off();
    pump_off();
}


    delay(1000); // lire toutes les secondes
}
