#!/usr/bin/env python
import serial
import sys
import time

delay = 0.01    #sec

ser = serial.Serial()
ser.baudrate = 115200
ser.port = sys.argv[1]
ser.open()

if not ser.is_open:
	print("Error: could not open serial port " + sys.argv[1])
	quit()

tx = 0
i = 0
while True:
	ser.write(chr(tx))

	while ser.inWaiting() == 0:
		time.sleep(delay)
	rx=ser.read(1)
	if rx != chr(tx):
		print("Error: sent: %d, got: %d" %(tx, ord(rx)))
		break
	i = i + 1
	print("%d: %d" %(i, tx))
	tx = tx + 1
	if tx > 255:
		tx = 0
ser.close()
print("Done")

