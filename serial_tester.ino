#include <SoftwareSerial.h>

#define SOFTWARE_SERIAL

SoftwareSerial mySerial(10, 11);  //RX, TX
unsigned char led = 0;
unsigned char i = 0;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
#ifdef SOFTWARE_SERIAL
    mySerial.begin(115200);
#else
    Serial1.begin(115200);
#endif
}

void loop() {

#ifdef SOFTWARE_SERIAL
    if (mySerial.available() > 0)
    {
      mySerial.write(mySerial.read());
#else
    if (Serial1.available() > 0)
    {
      Serial1.write(Serial1.read());
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

