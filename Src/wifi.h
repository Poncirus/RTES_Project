// wifi.h

#ifndef WIFI_H
#define WIFI_H

#include <WiFiUdp.h>

const char SSID[] = "江宸宇的 iPhone";
const char PASSWORD[] = "12345678";

class Wifi
{
public:
	int getWifiStrengh();
	void init();
	void broadcast(const char *message);
	Wifi();
private:
	WiFiUDP udp;
};

#endif
