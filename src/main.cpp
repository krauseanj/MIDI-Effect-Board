#include <Arduino.h>
#include "config.h"

namespace {
elapsedMillis sampleTimer;
float filteredReading = 0.0f;
int lastSentValue = -1;
}

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(Config::potPin, INPUT);
    analogReadResolution(Config::adcBits);
    analogReadAveraging(16);
    Serial.begin(115200);
    // Do not wait for Serial: the controller also works without a monitor.
    filteredReading = analogRead(Config::potPin);
}

void loop() {
    // Drain incoming USB MIDI so unread messages do not accumulate.
    while (usbMIDI.read()) {}

    if (sampleTimer < Config::sampleIntervalMs) {
        return;
    }
    sampleTimer = 0;

    const int rawReading = analogRead(Config::potPin);
    filteredReading += 0.25f * (rawReading - filteredReading);
    const int ccValue = constrain(
        static_cast<int>(filteredReading * 127.0f / Config::adcMax + 0.5f),
        0, 127);

    if (ccValue != lastSentValue) {
        usbMIDI.sendControlChange(Config::midiCC, ccValue, Config::midiChannel);
        usbMIDI.send_now();
        lastSentValue = ccValue;
        digitalWrite(LED_BUILTIN, ccValue >= 64 ? HIGH : LOW);
        if (Serial) {
            Serial.print("CC ");
            Serial.print(Config::midiCC);
            Serial.print(" = ");
            Serial.println(ccValue);
        }
    }
}
