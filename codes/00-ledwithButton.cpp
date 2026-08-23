#include <Arduino.h>

#define LED_PIN 23
#define BUTTON_PIN 18

int previousState = 0;

void setup()
{
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    previousState = digitalRead(BUTTON_PIN);
}

void loop()
{
    int buttonState = digitalRead(BUTTON_PIN);
    if (buttonState != previousState)
    {
        Serial.print("State changed: ");
        Serial.println(buttonState);

        previousState = buttonState;
    }
    if (buttonState != HIGH)
    {
        digitalWrite(LED_PIN, HIGH);
    }
    else
    {
        digitalWrite(LED_PIN, LOW);
    }
    
}