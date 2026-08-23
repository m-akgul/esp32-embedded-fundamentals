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


bool buttonPressed()
{
    int currentButtonState = digitalRead(BUTTON_PIN);

    bool pressed = false;

    if (previousButtonState == HIGH &&
        currentButtonState == LOW)
    {
        pressed = true;
    }

    previousButtonState = currentButtonState;

    return pressed;
}


void toggleLedState()
{
    if (ledState == LED_OFF)
    {
        ledState = LED_ON;
    }
    else
    {
        ledState = LED_OFF;
    }
}


void updateLed()
{
    if (ledState == LED_ON)
    {
        digitalWrite(LED_PIN, HIGH);
    }
    else
    {
        digitalWrite(LED_PIN, LOW);
    }
}


void setup()
{
    Serial.begin(115200);

    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);

    digitalWrite(LED_PIN, LOW);
}


void loop()
{
    if (buttonPressed())
    {
        toggleLedState();
    }

    updateLed();
}