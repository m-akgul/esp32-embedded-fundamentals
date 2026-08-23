#include <Arduino.h>

#define LDR_PIN 34

void setup()
{
    Serial.begin(115200);

    pinMode(LDR_PIN, INPUT);
}

void loop()
{
    int value = analogRead(LDR_PIN);

    Serial.println(value);

    delay(100);
}