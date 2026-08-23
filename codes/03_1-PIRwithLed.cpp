#include <Arduino.h>

#define PIR_PIN 18
#define LED_PIN 23

void setup()
{
    Serial.begin(115200);

    pinMode(PIR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    bool motion = digitalRead(PIR_PIN);

    digitalWrite(LED_PIN, motion ? HIGH : LOW);
}