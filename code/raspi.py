# -*- coding: utf-8 -*-

import serial

serialCOM = serial.Serial('/dev/ttyACM0',9600)

while True:

     valor = raw_input('Choose H (High) or L (Low):')

     serialCOM.write(valor)

serialCOM.close()