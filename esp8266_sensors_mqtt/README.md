This IOT Project is Temperature monitoring system using MQTT and Publish to MQTT Broker. 

<B>Features of this project.</B>

<B> 1. Customizable Wifi </B> </BR>

a. Included Tzapu Wifi Manager to make this device portable. </BR>
b. Device can be configured with push button (press > 3000ms) to re-start and configure new AP </BR>

<B> 2. OTA </B> </BR>

a. Included hallard/EspMQTTClient, changed qos to 1. (file is local here) </BR>
b. In browser type http://esp8266client.local </BR>
c. Username is MQTT username and MQTT password </BR>
d. OTA can be performed using Firmware update </BR>

<B> 3. Modular design with different C++ files </B> </BR>

<B> 4. Used Digital Ocean droplet (Installed Debian and installed Mosquitto MQTT broker, Nodered) One can use Ubuntu or any linux </B> </BR>

<B> 4. Components used: </B> </BR>
1. Esp8266 - 30 pin version
2. DHT22 & 10K resistor (between Positive (+) and data pin (middle))
3. MQ2 
4. Push button and 10K resistor

<img src="./Completed_HW_Setup.jpg" width="400px" height="auto">
<img src="./PCB_Layout.jpg" width="800px" height="auto">
