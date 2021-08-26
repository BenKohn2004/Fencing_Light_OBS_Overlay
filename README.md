# Fencing_Light_OBS_Overlay

The output of a Leon Paul or St George scorebox is done through 8 pins, either RJ45 or 8 pin din connector: 

https://www.leonpaul.com/content/leon-paul-wireless-fencing-instructions.pdf

The power connections are used with pins that denote each lamp color:
Green/Red/White Green/White Red/Yellow Green/Yellow Red
 
This project uses the connections to power relays, which connects the Transmitting/Client ESP8266 input pins to ground creating a signal. The Transmitting/Client ESP8266 then sends the signal to a Receiving/Server ESP8266 which outputs the signal to a Pro Micro Arduino. The Pro Micro acts as a Human Interface Device, i.e. Keyboard, which outputs HotKeys F13 through F20 to OBS showing/hiding overlay objects.

The ESP8266 requires the additional board manager JSON: 
http://arduino.esp8266.com/stable/package_esp8266com_index.json and was run as NodeMCU, ESP-12E.

The Micro Pro was run as an Arduino Leonardo.

Since F13 through F20 are non-traditional keystrokes, a separate program, Micro_Pro_HID_Key_Setting, was used to input the keys while assigning hotkeys in OBS.
The Pro-Micro can become unresponsive if its upload is interrupted. This can be fixed by placing it into bootloading by connecting GND to RST just prior to uploading a new program from the Arduino IDE.

The JSON overlay, Fencing_Camera_Overlay_Using_ScoreBoard_Plus.json, can be imported into OBS and used with the included image to create the overlay.

This intended as a low cost and proof of concept solution. Much of the design and implementation can and will be refined.
