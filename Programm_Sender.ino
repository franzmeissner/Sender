#include <usbhid.h>
#include <hiduniversal.h>
#include <usbhub.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>
#include "hidjoystickrptparser.h"


USB Usb;
USBHub Hub(&Usb);
HIDUniversal Hid(&Usb);
JoystickEvents JoyEvents;
JoystickReportParser Joy(&JoyEvents);

void setup() {
        //Baudraten müssen gleich sein  
        Serial.begin(9600);  //USB
        Serial1.begin(9600);  //XBee

        if (Usb.Init() == -1)
                Serial1.println("OSC did not start.");

        delay(50);

        if (!Hid.SetReportParser(0, &Joy))
                ErrorMessage<uint8_t > (PSTR("SetReportParser"), 1);
}

void loop() {
        Usb.Task();
}
