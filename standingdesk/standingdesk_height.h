#include "esphome.h"

class DeskHeightSensor : public Component, public UARTDevice, public Sensor {
 public:
  DeskHeightSensor(UARTComponent *parent) : UARTDevice(parent) {}

  void setup() override {
    // nothing to do here
  }

  int readline(int readch, uint8_t *buffer, int len)
  {
    static int pos = 0;
    int rpos;

    if (readch > 0) {
      switch (readch) {
        
        case 126: // 126 is the last value
          buffer[pos++] = readch;
          rpos = pos;
          pos = 0;  // Reset position index ready for next time
          return rpos;
        default:
          if (pos < len-1) {
            buffer[pos++] = readch;
            buffer[pos] = 0;
          }
      }
    }
    // No end of line has been found, so return -1.
    return -1;
  }

  void loop() override {
    const int max_line_length = 9;
    static uint8_t buffer[max_line_length];
    while (available()) {

      // uint8_t incomingByte = read();
      // ESP_LOGD("DEBUG", "Incoming byte is: %i", incomingByte);

      if(readline(read(), buffer, max_line_length) > 0) {

        if((buffer[0] == 242) && (buffer[1] == 242) && (buffer[2] == 1) && (buffer[3] == 3) && (buffer[6] == 7) && (buffer[8] == 126)) {
          publish_state((buffer[4]*255.0+buffer[5])/10.0);
        }
      }
    }
  }
};
