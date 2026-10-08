#pragma once

#include <Arduino.h>

namespace Config {
constexpr uint8_t potPin = A0;  // Teensy pin 14
constexpr uint8_t midiChannel = 1;
constexpr uint8_t midiCC = 20;
constexpr uint32_t sampleIntervalMs = 5;
constexpr uint8_t adcBits = 10;
constexpr uint16_t adcMax = (1U << adcBits) - 1;
}
