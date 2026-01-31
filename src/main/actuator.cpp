#include <Arduino.h>
#include "actuator.h"

#define LED_PIN 13
#define RELAY_PIN 7  // relais connecté à IN

void actuator_init(void) {
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);

    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, HIGH); // pompe OFF au démarrage
}

void led_on(void) {
    digitalWrite(LED_PIN, HIGH);
}

void led_off(void) {
    digitalWrite(LED_PIN, LOW);
}

void pump_on(void) {
    digitalWrite(RELAY_PIN, LOW);  // active relais → pompe ON
}

void pump_off(void) {
    digitalWrite(RELAY_PIN, HIGH); // désactive relais → pompe OFF
}
