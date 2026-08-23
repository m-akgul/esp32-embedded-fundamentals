#include <Arduino.h>

#define LED_PIN 23
#define BUTTON_PIN 18

const unsigned long DEBOUNCE_TIME = 30;

int lastReading;
int stableState;

unsigned long lastChangeTime = 0;

void setup()
{
    Serial.begin(115200);

    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);

    lastReading = digitalRead(BUTTON_PIN);
    stableState = lastReading;
}

void loop()
{
    int currentReading = digitalRead(BUTTON_PIN);

    if (currentReading != lastReading)
    {
        lastChangeTime = millis();

        lastReading = currentReading;
    }

    if (millis() - lastChangeTime >= DEBOUNCE_TIME)
    {
        if (currentReading != stableState)
        {
            stableState = currentReading;

            Serial.print("Stable state changed to: ");
            Serial.println(stableState);
        }
    }

    if (stableState == LOW)
    {
        digitalWrite(LED_PIN, HIGH);
    }
    else
    {
        digitalWrite(LED_PIN, LOW);
    }
}