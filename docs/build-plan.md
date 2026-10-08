# Build plan

## Milestones

1. Build and upload the one-pot firmware. Verify CC 20/channel 1 in a MIDI monitor and values near both endpoints. Check that a stationary knob does not flood the monitor.
2. Identify the OLED model, controller, voltage requirements, and interface. Add a display of the current CC value after confirming its wiring.
3. Identify multiplexer models and assign channels for 15 potentiometers and 5 faders. Define CC assignments and calibration per control.
4. Add the two encoders with a suitable decoding method and define their MIDI behavior.
5. Add buttons through the MCP23017 expanders with debounce. Identify whether pads are switches or pressure sensors before choosing their circuits.
6. Validate the complete control surface on a breadboard before soldering and enclosure assembly.
7. Design audio hardware separately once the MIDI controller is stable; an audio interface/preamp/effects processor/sampler requires more than this firmware.

## Details still needed

- OLED model and printed pin labels
- Multiplexer model numbers
- MCP23017 breakout models and address configuration
- Encoder type and pin labels
- Button and pad types
- Fader resistance and terminal layout
- Final enclosure and power arrangement

Record verified wiring and pin assignments here as each milestone is completed.
