#include "ESP8266WiFi.h"

void prinScanResult(int networksFound)
{
  bool t = true;
  for (int i = 0; i < networksFound; i++)
  {
    if (strcmp(WiFi.SSID(i).c_str(),"RTES_TEST") == 0)
    {
      Serial.printf("%d: %s, Ch:%d (%ddBm) %s\n", i + 1, WiFi.SSID(i).c_str(), WiFi.channel(i), WiFi.RSSI(i), WiFi.encryptionType(i) == ENC_TYPE_NONE ? "open" : "");
      t = false;
      break;
    }
  }

  if (t)
  {
    Serial.printf("cannot find ssid\n");
  }
}


void setup()
{
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}


void loop() 
{
    WiFi.scanNetworksAsync(prinScanResult);
    delay(200);    
}
