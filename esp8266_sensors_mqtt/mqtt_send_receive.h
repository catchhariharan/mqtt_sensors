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
#ifndef _MQTT_SEND_RECEIVE_H
#define _MQTT_SEND_RECEIVE_H

void mqtt_send_receive_setup(void);
void mqtt_send_receive_loop(void);
void setup_wifi();


#endif //_MQTT_SEND_RECEIVE_H
