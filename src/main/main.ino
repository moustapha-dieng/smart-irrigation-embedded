#include <Arduino.h>
#include "sensor.h"
#include "actuator.h"

const int HUMIDITY_THRESHOLD = 700;        // Seuil à ajuster selon le capteur et le sol.
const unsigned long READ_INTERVAL_MS = 1000;

void setup() {
    Serial.begin(9600);
    sensor_init();
    actuator_init();
}

void loop() {
    int humidity = sensor_read();
    Serial.print("Soil moisture: ");
    Serial.println(humidity);

    if (humidity > HUMIDITY_THRESHOLD) {
        led_on();
        pump_on();
    } else {
        led_off();
        pump_off();
    }

    delay(READ_INTERVAL_MS);
}
