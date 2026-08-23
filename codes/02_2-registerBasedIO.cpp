#include <Arduino.h>

#include "soc/gpio_reg.h"
#include "soc/soc.h"

#define LED_PIN 23
#define BUTTON_PIN 18

void setup()
{
    Serial.begin(115200);

    // Configure GPIO18 as input with internal pull-up.
    pinMode(BUTTON_PIN, INPUT_PULLUP);

    // Enable GPIO23 output driver directly.
    REG_SET_BIT(GPIO_ENABLE_REG, (1 << LED_PIN));
}

void loop()
{
    uint32_t gpioState = REG_READ(GPIO_IN_REG);

    int buttonState = (gpioState >> BUTTON_PIN) & 1;

    if (buttonState == 0)
    {
        // Button pressed → LED ON
        REG_WRITE(GPIO_OUT_W1TS_REG, (1 << LED_PIN));
    }
    else
    {
        // Button released → LED OFF
        REG_WRITE(GPIO_OUT_W1TC_REG, (1 << LED_PIN));
    }

    Serial.println(buttonState);
}