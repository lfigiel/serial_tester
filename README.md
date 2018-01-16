# serial_tester
Arduino hardware/software serial port tester

## Usage
```
python2 serial_tester.py <port>
```

for example:

```
python2 serial_tester.py /dev/ttyUSB0
```

Here is the test result of software serial running on Leonardo board.  
Arduino 1.8.5  
baudrate 115200  

![alt text](https://raw.githubusercontent.com/lfigiel/serial_tester/master/pics/results.png)

Left column: test no. right: byte sent and received.  
