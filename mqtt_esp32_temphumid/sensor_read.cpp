/********************************************************************************************************************
 *  Board Settings:
 *  Board: "NodeMCU-32S"
 *  Upload Speed: "115200"
 *  Flash Frequency: "80MHz"
 *  Core Debug Level: "None"
 *  COM Port: Depends *On Your System* Works on small Sony Watch Cable
 *  Version - 1.0
 *  Author - hariharan@svaasya.com
 *********************************************************************************************************************/


#include "sensor_read.h"
//#include "ifttt_http.h"

DHTesp dhtSensor2;
TempAndHumidity sensor2Data;

int dhtPin2 = 16;
int smokeA0 = A0;


// current temperature & humidity, updated in loop()
float t = 0.0;
float h = 0.0;
int g = 0;

bool initflag = 0;



// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;    // will store last time DHT was updated
unsigned long log_previousMillis = 0;    // will store last time DHT was updated

// Updates DHT readings every 1 second
const long interval = 1000;  

// Updates DHT readings every 10 min
const long log_interval = 600000;  



void sensor_setup(void) {
  pinMode(smokeA0, INPUT);
  dhtSensor2.setup(dhtPin2, DHTesp::DHT22);

}

void sensor_task(void) {

  unsigned long currentMillis = millis();
  unsigned long log_currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you updated the DHT values
    previousMillis = currentMillis;
    // Read temperature as Celsius (the default)
    sensor2Data = dhtSensor2.getTempAndHumidity();
    float newT = sensor2Data.temperature;
    // if temperature read failed, don't change t value
    if (isnan(newT)) {
      Serial.println("Failed to read from DHT sensor!");
    }
    else {
      t = newT;
      //Serial.println(t);
    }
    // Read Humidity
    float newH = sensor2Data.humidity;
    // if humidity read failed, don't change h value 
    if (isnan(newH)) {
      Serial.println("Failed to read from DHT sensor!");
    }
    else {
      h = newH;
      //Serial.println(h);
    }
    int newG = analogRead(smokeA0);
    //Serial.println(xPortGetCoreID());
    // if gas sensor read failed, don't change g value 
    if (isnan(newG)) {
      Serial.println("Failed to read from Gas sensor!");
    }
    else {
      g = newG;
      //Serial.println(g);
    }
    
  }
    if (initflag == 0)
    {
      initflag = 1;
      //makeIFTTTRequest();
      //appendmysqldb();
    }
    if (log_currentMillis - log_previousMillis >= log_interval) {
    // save the last time you updated the DHT values
    log_previousMillis = log_currentMillis;
    //makeIFTTTRequest();
    //appendmysqldb();
  }
}

float sensor_read_temperature(void){
	return(t);
}
float sensor_read_humidity(void){
	return(h);
}
int sensor_read_mq2(void){
	return(g);
}
