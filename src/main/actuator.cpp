#include <Arduino.h>
#include "actuator.h"

const int LED_PIN = 13;
const int RELAY_PIN = 7;

// Le module relais utilisé ici est actif à l'état bas.
const int RELAY_ON = LOW;
const int RELAY_OFF = HIGH;

void actuator_init(void) {
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);

    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, RELAY_OFF);
}

void led_on(void) {
    digitalWrite(LED_PIN, HIGH);
}

void led_off(void) {
    digitalWrite(LED_PIN, LOW);
}

void pump_on(void) {
    digitalWrite(RELAY_PIN, RELAY_ON);
}

void pump_off(void) {
    digitalWrite(RELAY_PIN, RELAY_OFF);
}
