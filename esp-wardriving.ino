#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(9600);

  // Set WiFi to station mode and disconnect from any previous connection
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  Serial.println("Scanning for Wi-Fi networks...");
}

void loop() {
  // WiFi scan
  int networkCount = WiFi.scanNetworks();
  
  if (networkCount == 0) {
    Serial.println("No networks found.");
  } else {
    Serial.println("Found networks:");
    for (int i = 0; i < networkCount; ++i) {
      Serial.print(WiFi.SSID(i));
      Serial.print(" (Signal strength: ");
      Serial.print(WiFi.RSSI(i));
      Serial.println(" dBm)");
    }
  }

  // Wait for a while before scanning again
  Serial.println("waiting 30 sec");
  delay(30000);
  
}
