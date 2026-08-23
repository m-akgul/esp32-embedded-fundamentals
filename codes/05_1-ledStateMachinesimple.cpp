#include <Arduino.h>

#define LED_PIN 23
#define BUTTON_PIN 18

enum LedState
{
    LED_OFF,
    LED_ON
};

LedState ledState = LED_OFF;

int previousButtonState = HIGH;

void setup()
{
    Serial.begin(115200);

    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);

    digitalWrite(LED_PIN, LOW);
}

void loop()
{
    int currentButtonState = digitalRead(BUTTON_PIN);

    // Detect a button press: HIGH → LOW
    if (previousButtonState == HIGH &&
        currentButtonState == LOW)
    {
        Serial.println("Button pressed");
        if (ledState == LED_OFF)
        {
            ledState = LED_ON;
            Serial.println("LED ON");
        }
        else
        {
            ledState = LED_OFF;
            Serial.println("LED OFF");
        }
    }

    previousButtonState = currentButtonState;

    if (ledState == LED_ON)
    {
        digitalWrite(LED_PIN, HIGH);
        Serial.println("LED HIGH");
    }
    else
    {
        digitalWrite(LED_PIN, LOW);
    }
}