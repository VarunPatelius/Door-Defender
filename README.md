# Door-Defender
Door Defender is a device I created because I was tired of getting caught off guard when my parents entered my room. This device is featured on BlueHandCoding's Tik Tok [here](https://www.tiktok.com/@bluehandcoding/video/7047873010337910022).

## Parts
(*These parts are usually sold in large quantities, but only one is needed*)

As stated in the Tik Tok, Door Defender is built using the following:
* [ESP8266](https://www.amazon.com/HiLetgo-Internet-Development-Wireless-Micropython/dp/B081CSJV2V/ref=sr_1_4?crid=2U9CHZF7H7JNC&keywords=esp8266&qid=1640998566&sprefix=esp8266%2Caps%2C116&sr=8-4) - This is the brains of Door Defender and is used to communicate with the ultrasonic sensor and your computer.
* [HC-SR04 Ultrasonic Sensor](https://www.amazon.com/Smraza-Ultrasonic-Distance-Mounting-Duemilanove/dp/B01JG09DCK/ref=sr_1_3?keywords=hc+sr04+ultrasonic+sensor&qid=1640998674&sprefix=hc+sr%2Caps%2C130&sr=8-3) - This is the sensor used to detect if the door is opened.
* [Breadboard](https://www.amazon.com/Eiechip-Breadboard-Solderless-Prototype-Universal/dp/B07RN4BTDF/ref=sr_1_3?crid=AAOQK8KPKYHW&keywords=breadboard+with+adhesive&qid=1640998736&sprefix=breadboard+with+adhesive%2Caps%2C105&sr=8-3) - The breadboard allows for the ESP8266 and the HC-SR04 to be connected together. The adhesive backing also allows it to be stuck next to a door.
* [Power/Data Cable](https://www.amazon.com/Anker-3-Pack-Powerline-Micro-USB/dp/B015MJLEUS/ref=sr_1_1?keywords=micro+usb+data+cable&qid=1638925059&refinements=p_72%3A1248879011%2Cp_89%3AAmazon+Basics%7CAnker%2Cp_n_feature_ten_browse-bin%3A23555330011%2Cp_n_condition-type%3A2224371011&rnid=2224369011&s=pc&sr=1-1) - It is really important to have a good cable to connect to your ESP8266 to both power it and send all the code to it. While many people do have their own Micro USB cables, if they don't work, I suggest this cable.
* [Jumper Cables](https://www.amazon.com/GenBasic-Female-Solderless-Breadboard-Prototyping/dp/B077N7J6C4/ref=sr_1_5?crid=DQOD36XXHEF7&keywords=arduino+male+to+female&qid=1640998952&s=electronics&sprefix=arduino+male+to+female%2Celectronics%2C93&sr=1-5) - Used to connect everything on the breadboard.

## Software
The following programs/software is necessary for Door Defender:
* [Arduino IDE](https://www.arduino.cc/en/software) - Used to write and send code to the ESP8266 (*Follow the instrcutions on the Amazon page for the ESP8266 for setup*). This project makes use of version 2.3.0 of the ESP8266 Library.
* [Python](https://www.python.org/downloads) - This is what is run on the local computer to exceute the Python program.
* [UART Drivers](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers) - This driver is necessary in order for you to send your code over to the ESP8266

## Setup
The setup is fairly simple if you are familiar with creating virtual environments and flashing code to a microcontroller.

1. Clone or download the .zip for this Github repo to your machine.
2. Open the [file](https://github.com/VarunPatelius/Door-Defender/blob/main/doorClosed.ino) and then replace the 'xxx' with the necessary information.
3. Assemble Door Defender according to the pin numbers shown in the code. This can then be placed anywhere you want.
4. To get the local server running, createa virtual environment and install flask and pyautogui.

This is the schematic:
![Door Defender Schematic](https://raw.githubusercontent.com/VarunPatelius/Door-Defender/main/github/doorDefenderSchematic.png)

PLEASE READ ALL THE COMMENTS FOR THE CODE BEFORE FLASHING OR RUNNING
