# ESPHome
ESPHome configuration files

## Standing desk (Fully Jarvis)
This is the configuration for a Fully Jarvis Standing Desk (https://www.fully.com/standing-desks/jarvis-frame-only.html).
I bought mine in 2020

Connected to the ESP using something like this:

RJ45 Screw Terminal Adaptor Female: https://www.amazon.com/Poyiccot-Compatible-Terminal-Connector-Ethernet/dp/B07WKKVZRF

Pinout (Facing the screw terminals, from left to right, 1-8):
1. Unassigned
2. Unassigned
3. Ground
4. Unassigned
5. 5V (I think most other unassigned would also work)
6. Connected to D7 (pin7)
7. Connected to D6 (pin6)
8. Connected to D5 (pin5)

RJ45 Ethernet Splitter Adapter: 1 Male to 2 Female: https://www.amazon.com/Ethernet-Splitter-Yeworth-Networking-Extension/dp/B09PMXTX2K

Male plugged into motor control box, 1 female goes to the control panel, 1 female goes to the ESP

For the multiplication factors below, I
1. Set the delay to a fixed value, e.g. 2 seconds
2. Drive the desk into the lowest position
3. Read the height from the display (or measure it or whatever). Put it into Excel
4. Press the ESP "button" to drive it up
5. Read the height from the display. Put it into Excel
6. Repeat steps 4 and 5 until a few measurements are taken
7. Calculate the height differences, take their average, divide the milliseconds by the height in cm to get the ms/cm value
8. Enter the value in the lambdas below
9. Repeat for going down
