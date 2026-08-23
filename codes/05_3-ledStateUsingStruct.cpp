#include <Arduino.h>

#define LED_PIN 23
#define BUTTON_PIN 18

enum LedState
{
    LED_OFF,
    LED_ON
};


struct SystemState
{
    LedState led;
    int previousButton;
};


SystemState systemState =
{
    LED_OFF,
    HIGH
};


bool buttonPressed()
{
    int currentButtonState = digitalRead(BUTTON_PIN);

    bool pressed = false;

    if (systemState.previousButton == HIGH &&
        currentButtonState == LOW)
    {
        pressed = true;
    }

    systemState.previousButton = currentButtonState;

    return pressed;
}


void toggleLedState()
{
    if (systemState.led == LED_OFF)
    {
        systemState.led = LED_ON;
    }
    else
    {
        systemState.led = LED_OFF;
    }
}


void updateLed()
{
    if (systemState.led == LED_ON)
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