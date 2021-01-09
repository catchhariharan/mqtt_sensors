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

#include "config.h"
#include "sensor_read.h"
#include "EspMQTTClient.h"


long lastMsg = 0;
const int LED_PIN = 16;

EspMQTTClient client(
//  "192.168.4.1",  // MQTT Broker server ip
  "128.199.22.248",  // MQTT Broker server ip
  1883,              // The MQTT port, default to 1883. this line can be omitted
  "hari",   // Can be omitted if not needed
  "hari0512",   // Can be omitted if not needed
  "esp8266client"     // Client name that uniquely identify your device
);

void OutputEventReceived(const String& message)
{
	//#ifdef SERIAL_DEBUG_ENABLE
	//Serial.println("message received from esp32/output: " + message);
	//#endif
	if (message == "on")
	{
		digitalWrite(LED_PIN, LOW);
	}
	else if (message == "off")
	{
		digitalWrite(LED_PIN, HIGH);
	}

}


void mqtt_send_receive_setup()
{
  pinMode(LED_PIN,OUTPUT);
  // Optionnal functionnalities of EspMQTTClient : 
  //client.enableDebuggingMessages(); // Enable debugging messages sent to serial output
  client.enableOTA();	
  client.enableHTTPWebUpdater(); // Enable the web updater. User and password default to values of MQTTUsername and MQTTPassword. These can be overrited with enableHTTPWebUpdater("user", "password").
  client.enableLastWillMessage("esp8266client/lastwill", "I am going offline");  // You can activate the retain flag by setting the third parameter to true
  client.enableMQTTPersistence();
}

// This function is called once everything is connected (Wifi and MQTT)
// WARNING : YOU MUST IMPLEMENT IT IF YOU USE EspMQTTClient
void onConnectionEstablished()
{
  // Subscribe to "mytopic/test" and display received message to Serial
  client.subscribe("esp8266/toggle_led", OutputEventReceived);
  // Subscribe to "mytopic/wildcardtest/#" and display received message to Serial
  client.subscribe("esp8266/wildcardtest/#", [](const String & topic, const String & payload) {
    Serial.println("(From wildcard) topic: " + topic + ", payload: " + payload);
  });

  // Execute delayed instructions
  //client.executeDelayed(5 * 1000, []() {
  //  client.publish("mytopic/wildcardtest/test123", "This is a message sent 5 seconds later");
  //});
}

void mqtt_send_receive_loop()
{
  long now = millis();
  if (now - lastMsg > 1000) {
	    lastMsg = now;

	  client.publish("esp8266/temperature", String(sensor_read_temperature()).c_str()); // You can activate the retain flag by setting the third parameter to true
	  client.publish("esp8266/humidity", String(sensor_read_humidity()).c_str()); // You can activate the retain flag by setting the third parameter to true
	  client.publish("esp8266/mq2", String(sensor_read_mq2()).c_str()); // You can activate the retain flag by setting the third parameter to true
  
  }
  client.loop();
}