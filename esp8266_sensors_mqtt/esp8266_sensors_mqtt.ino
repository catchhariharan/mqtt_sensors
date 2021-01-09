/********************************************************************************************************************
 *  Board Settings:
 *  Board: "NodeMCU 1.0 ESP-12E"
 *  Upload Speed: "115200"
 *  Flash Frequency: "80MHz"
 *  Core Debug Level: "None"
 *  COM Port: Depends *On Your System* Works on small Sony Watch Cable
 *  Version - 1.0
 *  Author - hariharan@svaasya.com
 *********************************************************************************************************************/




#include "sensor_read.h"
#include "mqtt_send_receive.h"
#include "config.h"
#include "wifiman.h"


void setup() {
  Serial.begin(115200);
  wifiman_setup();
  // default settings
  // (you can also pass in a Wire library object like &Wire2)
  //status = bme.begin();  
  sensor_setup();   

  mqtt_send_receive_setup();  
}



void loop() {
  wifiman_loop();  
  sensor_task();  
  mqtt_send_receive_loop();
}