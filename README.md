# RaspiArduinoSerial
This repository is created in order to submit the necessary code for establishing a communication between Arduino and Raspberry via serial connection. It is as simple as connecting the Arduino supply wire into the Raspberry Pi USB entry and making the following connection in the Arduino:

![Arduino connection](/images/img.png)

## Contents

- [Arduino code](#arduino-code)
- [Raspberry Pi code](#raspberry-pi-code)

## Arduino code
<a href="https://www.arduino.cc"><img src="https://upload.wikimedia.org/wikipedia/commons/8/87/Arduino_Logo.svg" alt="Arduino Logo" align="left" style="margin-right: 25px" height=150></a>

The Arduino code is very simple. It just opens the serial communication and it writes a 1 or a 0 in the pin depending on the letter it is send.

```bash
int led = 13;
void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.read()>0){
    if(Serial.read() == 'H'){
       digitalWrite(led, HIGH);
    }
  
    else if(Serial.read() == 'L'){
      digitalWrite(led, LOW);
    }
  }
}
```

## Raspberry Pi code
<a href="https://www.raspberrypi.org"><img src="https://www.raspberrypi.org/wp-content/uploads/2012/03/raspberry-pi-logo.png" alt="Raspberry Pi Logo" align="left" style="margin-right: 25px" height=150></a>

We will program the Raspberry Pi functionality in Python. This way, a minimun knowledge about the language in necessary.

```bash
# -*- coding: utf-8 -*-

import serial

serialCOM = serial.Serial('/dev/ttyACM0',9600)

while True:

     valor = raw_input('Choose H (High) or L (Low):')

     serialCOM.write(valor)

serialCOM.close()
```
