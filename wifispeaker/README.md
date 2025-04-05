# Wifi speakers powered by squeezelite

This project is for stereo wifi speakers with perfect syncronization powered by USB Power Delivery.
It's probably just loud enough for a small party, but definitely for regular neighbor-approved volume levels.
The provided PCBs are connected together into a 2-layer stack that fits into a custom 3D-printed enclosure.

**Generally, I would not recommend that you follow the project 1:1. There are some known issues (see below).**
I am very happy with the audio quality of the amplifier, but I'm also not an audiophile.
I put this up on Github as inspiration for advanced users that might want to implement other variants.

## Disclaimer
The information provided here is for informational purposes only. Use it ENTIRELY AT YOUR OWN RISK. There are known issues with the PCBs provided here.

## Amplifier board
The Amplifier used is a [TAS5827](https://www.ti.com/product/TAS5827), a 43-W stereo digital-input Class-D amplifier, which can be configured via resistors, greatly simplifying the software side of the project.

## Control board
The microchip is a ESP32-S3, which runs [squeezelite-esp32](https://github.com/sle118/squeezelite-esp32).
Initially, additional functionality, e.g. LEDs & microphones, were planned, but I ended up not using them. That means that some of the pads, PCB sections, etc., are overkill for a simple wifi speaker.

## 3D-printed enclosure
I chose to print it out of Nylon for its higher temperature resistance.

## Known issues
- Soldering the headers is quite hard, as I did not use thermal reliefs on the header pins.
- WiFi reception is not perfect, and the speakers sometimes drop off the network. I am not sure what the exact reason is, so it could be the hardware / software / or my specific environment.
- There is no direct bluetooth support on the ESP32-S3, you'll need to stream music via wifi.
- The USB-PD chip is overkill. A more simple one that just requests a specific voltage depending on some resistors would be sufficient.
