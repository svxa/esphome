# Electricity meter connection to ESPHome / Home Assistant

If you have a smart meter that supports SML (Smart metering language), you can quite easily obtain the data and use it in your smart home.
However, my electricity meter has no power outlets nearby, which requires a battery-powered solution.
I wanted to be able to mount a very large battery pack (I'm using a 12Ah battery pack), i.e. not a single 18650, so I made a small PCB to connect everything.

The [nologo ESP32-S3 Supermini](https://www.nologo.tech/en/product/esp32/esp32s3supermini/esp32S3SuperMini.html#%E7%AE%80%E4%BB%8B) directly supports battery-powered operation, the only challenge left is connecting a battery to the two pads on the bottom.
I designed a PCB that will take care of this and in addition also has a connector for the actual sensor that will be placed on the electricity meter.

## Disclaimer
Everything you do based on the information provided here is ENTIRELY AT YOUR OWN RISK! I take no responsibility whatsoever, you should treat the information here as purely informational.

## Bill of materials
- [nologo ESP32-S3 Supermini](https://www.nologo.tech/en/product/esp32/esp32s3supermini/esp32S3SuperMini.html#%E7%AE%80%E4%BB%8B)
- 2-pin PH connector (for the battery), e.g. [S2B-PH-SM4-TB](https://www.digikey.com/en/products/detail/jst-sales-america-inc/S2B-PH-SM4-TB/926655)
  - DigiKey Part Number: 455-S2B-PH-SM4-TBTR-ND - Tape & Reel (TR)
  - Manufacturer: JST Sales America Inc.
  - Manufacturer Product Number: S2B-PH-SM4-TB
  - Description: CONN HEADER SMD R/A 2POS 2MM
- 4-pin PH connector (for the sensor), e.g. [S4B-PH-SM4-TB](https://www.digikey.com/en/products/detail/jst-sales-america-inc/S4B-PH-SM4-TB/926657)
  - DigiKey Part Number: 455-S4B-PH-SM4-TBTR-ND - Tape & Reel (TR)
  - Manufacturer: JST Sales America Inc.
  - Manufacturer Product Number: S4B-PH-SM4-TB
  - Description: CONN HEADER SMD R/A 4POS 2MM
- A 3.7V Lithium battery pack with a PH connector
  - e.g. a [1S4P 3.7V 12000mAh battery pack](https://de.aliexpress.com/item/1005005065502474.html)
- An IR reading head. I have one similar to [this](https://wiki.volkszaehler.org/hardware/controllers/ir-schreib-lesekopf)
- A small electrical box, with a hole / slot somewhere to pass through the sensor cable. This is not strictly necessary, it just makes it look less scary to your neighbors :\)
 
## Assembly
Due to the battery connection pads on the ESP32-S3 being on the bottom, I decided to solder it like a surface-mount component.
I also used SMD PH connectors, but through-hole soldering should also be possible with a bit of extra wiring from the PCB battery pads to the ESP32 battery pads.
The PH connectors support through-hole mounting.

## Battery life
I am using a 1S4P battery pack with 12000mAh. Depending on the sleep settings, I can get up to around 3 months of battery life if I read the sensor once every 5 minutes.
For my case, I am using smart (i.e. context dependent) sleep settings that are set by my Home Assistant based on some criteria.
This will lower the reading frequency at night to once an hour. Reading it out about 5min before every full hour was used to make the Home Assistant energy dashboards capture the correct data.

## Configuration
- esphome configuration: Uses MQTT, as I read somewhere that this is more energy saving, you might wanna verify this.
- HA configurations: Two automations and two scripts. They are not copy-paste, make sure you check the variable names in there and add the required helpers.
