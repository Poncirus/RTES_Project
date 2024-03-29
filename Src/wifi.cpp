// wifi.cpp

#include "wifi.h"
#include "Arduino.h"

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

//#define DEBUG

#define PORT 8110

Wifi::Wifi()
{
	
}

void Wifi::init()
{
#ifdef DEBUG
	Serial.println("start connect wifi");
#endif
	WiFi.mode(WIFI_STA);
	WiFi.begin(SSID, PASSWORD);
	while (WiFi.status() != WL_CONNECTED) 
	{
		delay(500);
#ifdef DEBUG
		Serial.print("*");
#endif
	}
	
#ifdef DEBUG
	Serial.println("    WiFi connection Successful");
#endif


}

int Wifi::getWifiStrengh()
{
	int r = 0;
	int sig = 0;
	delay(200);
	int times = 0;
	while(times < 3)
	{
		r = WiFi.RSSI();
		if(r == 0)
		{
			times = 0;
			continue;
		}

		if(r == sig)
		{
			times++;
		}
		else
		{
			sig = r;
			times = 0;
		}
		
		delay(200);
	}
    return r;
}

void Wifi::broadcast(const char *message)
{
#ifdef DEBUG
	Serial.print("wifi send: ");
	Serial.println(message);
#endif
	udp.beginPacket("255.255.255.255", 8110);
	udp.write(message, strlen(message));
	udp.endPacket();
}