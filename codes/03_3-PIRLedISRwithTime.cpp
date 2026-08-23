#include <Arduino.h>

#define PIR_PIN 18
#define LED_PIN 23

volatile bool pirState = false;
volatile unsigned long motionTime = 0;
volatile bool interruptOccurred = false;

void IRAM_ATTR motionISR()
{
    pirState = digitalRead(PIR_PIN);
    motionTime = micros();
    interruptOccurred = true;
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
    if (pirState)
    {
        if (interruptOccurred)
        {
            Serial.print("Motion detected at ");
            Serial.print(motionTime/1000000.0, 5);
            Serial.println(" s");
        }

        digitalWrite(LED_PIN, HIGH);
        interruptOccurred = false;
    }
    else
    {
        digitalWrite(LED_PIN, LOW);
    }
}