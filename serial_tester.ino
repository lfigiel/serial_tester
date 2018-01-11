#include <SoftwareSerial.h>

#define HARDWARE_SERIAL

SoftwareSerial mySerial(10, 11);  //RX, TX
unsigned char led = 0;
unsigned char i = 0;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    mySerial.begin(115200);
#ifdef HARDWARE_SERIAL
    Serial1.begin(115200);
#endif
}

void loop() {

    uint8_t rx;

    if (mySerial.available() > 0)
    {
        rx = mySerial.read();
        mySerial.write(rx);

#ifdef HARDWARE_SERIAL
        Serial1.write(rx);
#endif
      i++;
    }

    //blink LED to show that eveything is working
    if (i >= 10)
    {
      digitalWrite(LED_BUILTIN, (led^=1));
      i = 0;
    }
}

