#include <Arduino.h>

#include "soc/gpio_reg.h"
#include "soc/soc.h"

#define LED_PIN 23
#define BUTTON_PIN 18

void setup()
{
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);

    Serial.begin(115200);
}

void loop()
{
    int buttonState =
        (REG_READ(GPIO_IN_REG) >> BUTTON_PIN) & 1;

    if (buttonState == 0)
    {
        REG_SET_BIT(GPIO_OUT_REG, (1 << LED_PIN));
    }
    else
    {
        REG_CLR_BIT(GPIO_OUT_REG, (1 << LED_PIN));
    }

    Serial.println(buttonState);
}