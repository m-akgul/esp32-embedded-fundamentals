#include <Arduino.h>

#define PIR_PIN 18
#define LED_PIN 23

volatile bool motionDetected = false;

void IRAM_ATTR motionISR()
{
    motionDetected = digitalRead(PIR_PIN);
}

void setup()
{
    Serial.begin(115200);

    pinMode(PIR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);

    attachInterrupt(
        digitalPinToInterrupt(PIR_PIN),
        motionISR,
        CHANGE
    );
}

void loop()
{
    digitalWrite(LED_PIN, motionDetected ? HIGH : LOW);
}