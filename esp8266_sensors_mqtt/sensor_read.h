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

#ifndef _SENSOR_READ_H_
#define _SENSOR_READ_H_

#include <Arduino.h>
#include "DHTesp.h"


void sensor_setup(void);
void sensor_task(void);

float sensor_read_temperature(void);
float sensor_read_humidity(void);
int sensor_read_mq2(void);



#endif //_SENSOR_READ_H_