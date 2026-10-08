# MIDI Effect Board

Custom Teensy 4.1 MIDI controller. The first milestone reads one B10K potentiometer and sends USB MIDI Control Change values from 0 to 127.

## Current scope

Firmware runs on the Teensy; no desktop application is required. Audio processing, sampling, the OLED, multiplexers, MCP23017 expanders, and the remaining controls are future milestones.

## Hardware for the first test

- Teensy 4.1 with soldered headers
- One B10K potentiometer, breadboard, and jumper wires
- USB data cable
- Multimeter for checking connections

Disconnect USB before wiring. Connect one outer pot terminal to Teensy 3.3V, the other outer terminal to GND, and the wiper to pin 14 (A0). Confirm the wiper using your multimeter; do not assume an unfamiliar pot's terminal layout. Never feed 5V into Teensy signal pins. Use USB power only for this milestone.

## Development setup

1. Install Visual Studio Code: https://code.visualstudio.com/
2. Install the PlatformIO IDE extension in VS Code.
3. Open this repository folder (the folder containing platformio.ini).
4. Let PlatformIO install the Teensy toolchain and Arduino framework.
5. Click PlatformIO Build (checkmark), then connect the Teensy and click Upload (arrow).
6. If upload requests it, press the Teensy's program button once.

With PlatformIO Core available in your terminal, the equivalent commands are:

```powershell
pio run
pio run --target upload
pio device monitor
```

The USB configuration includes both MIDI and serial diagnostics. Open the serial monitor at 115200 baud to see CC values. In your DAW or MIDI monitor, enable the Teensy MIDI input and turn the knob. Expect CC 20 on channel 1, spanning 0 through 127. The initial knob value is transmitted at startup. Close the serial monitor before uploading if the port is busy.

## Files

- src/main.cpp: firmware entry point (setup and loop)
- include/config.h: pin assignment, MIDI settings, and sampling interval
- platformio.ini: Teensy 4.1 build and USB configuration
- docs/build-plan.md: assembly milestones and hardware questions

## Saving changes with Git

Run these from your cloned repository after building and reviewing the files:

```powershell
git status
git add README.md platformio.ini .gitignore src include docs
git commit -m "Add Teensy MIDI controller starter"
git push
```

If Git asks for an author identity, configure your preferred name and email (a GitHub noreply email is also an option) before committing.

## References

- Teensy 4.1 specifications and pinout: https://www.pjrc.com/store/teensy41.html
- Teensy USB MIDI API: https://www.pjrc.com/teensy/td_midi.html
- PlatformIO Teensy board: https://docs.platformio.org/en/latest/boards/teensy/teensy41.html

## Validation

This starter must be compiled locally and tested on the actual board. Check the wiring before applying power, then verify the knob endpoints and stationary behavior. A little boundary jitter can still occur; smoothing reduces noise but does not eliminate it.
