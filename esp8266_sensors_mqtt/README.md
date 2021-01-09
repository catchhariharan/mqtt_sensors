This IOT Project is Temperature monitoring system using MQTT and Publish to MQTT Broker. 

<B>Features of this project.</B>

1. Customizable Wifi </BR>

a. Included Tzapu Wifi Manager to make this device portable. </BR>
b. Device can be configured with push button (press > 3000ms) to re-start and configure new AP </BR>

2. OTA </BR>

Included hallard/EspMQTTClient, changed qos to 1. (file is local here) </BR>
In browser type http://esp8266client.local </BR>
Username is MQTT username and MQTT password </BR>
OTA can be performed using Firmware update </BR>
Modular design with different C++ files </BR>

3. Used Digital Ocean droplet (Installed Debian and installed Mosquitto MQTT broker, Nodered) One can use Ubuntu or any linux </BR>

4. Components used: </BR>
1. Esp8266 - 30 pin version
2. DHT22 & 10K resistor (between Positive (+) and data pin (middle))
3. MQ2 
4. Push button and 10K resistor

<img src="./Completed_HW_Setup.jpg" width="400px" height="auto">
<img src="./PCB_Layout.jpg" width="800px" height="auto">
