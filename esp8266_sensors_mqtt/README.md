This IOT Project is Temperature monitoring system using MQTT and Publish to MQTT Broker. 

Features of this project.
1. Customizable Wifi
  Included Tzapu Wifi Manager to make this device portable. 
  Device can be configured with push button (3000ms) to start as WIFi manager to configure AP
2. OTA
  included hallard/EspMQTTClient, changed qos to 1. file is local here
  In browser type http://esp8266client.local OTA can be performed
  Username is MQTT username and MQTT password
3. Modular design with different C++ files

Components used:
1. Esp8266 - 30 pin version
2. DHT22 & 10K resistor
3. MQ2 
4. Push button and 10K resistor
