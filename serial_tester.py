#!/usr/bin/env python
import serial
import sys
import time

ser = serial.Serial()
ser.baudrate = 115200
ser.port = sys.argv[1]
ser.open()

if not ser.is_open:
	print("Error: could not open serial port " + sys.argv[1])
	quit()


a = 0
i = 0
while True:
	ser.write(chr(a))

	while ser.inWaiting() == 0:
		time.sleep(0.01)
	if ser.read(1) != chr(a):
		print("Error: data corrupted")
		break
	i = i + 1
	print("%d: %d" %(i, a))
	a = a + 1
	if a > 255:
		a = 0
ser.close()
print("Done")

