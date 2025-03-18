 #include "WiFi.h"

// the setup function runs once when you press reset or power the board
void blinkPattern(uint8_t outputPin) {
  blink(outputPin, 250, 100);
  blink(outputPin, 250, 100);
  blink(outputPin, 500, 800);
}

void on(uint8_t outputPin) {
  digitalWrite(outputPin, HIGH);
}

void off(uint8_t outputPin) {
  digitalWrite(outputPin, LOW);
}

void blink(uint8_t outputPin, uint32_t duration, uint32_t wait) {
  on(outputPin);
  delay(duration);
  off(outputPin);
  delay(wait);
}

void wiFiSetup() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
}

void networkScan() {
  // Serial.println("Scan start");

  // WiFi.scanNetworks will return the number of networks found.
  int n = WiFi.scanNetworks();
  // Serial.println("Scan done");
  if (n == 0) {
    Serial.println("no networks found");
  } else {
    // Serial.print(n);
    // Serial.println(" networks found");
    // Serial.println("Nr | SSID                             | RSSI | CH | Encryption");
    bool found = false;
    for (int i = 0; i < n; ++i) {
      // if (!WiFi.SSID(i).equals("KatieScienceFair")) {
      if (!WiFi.SSID(i).equals("LinksRaft")) {
        continue;
      }
      // Print SSID and RSSI for each network found
      // Serial.printf("%2d", i + 1);
      found = true;
      Serial.print(" | ");
      Serial.printf("%-32.32s", WiFi.SSID(i).c_str());
      Serial.print(" | ");
      Serial.printf("%4d", WiFi.RSSI(i));
      // Serial.print(" | ");
      // Serial.printf("%2d", WiFi.channel(i));
      // Serial.print(" | ");
      // switch (WiFi.encryptionType(i))
      // {
      //   case WIFI_AUTH_OPEN:
      //     Serial.print("open");
      //     break;
      //   case WIFI_AUTH_WEP:
      //     Serial.print("WEP");
      //     break;
      //   case WIFI_AUTH_WPA_PSK:
      //     Serial.print("WPA");
      //     break;
      //   case WIFI_AUTH_WPA2_PSK:
      //     Serial.print("WPA2");
      //     break;
      //   case WIFI_AUTH_WPA_WPA2_PSK:
      //     Serial.print("WPA+WPA2");
      //     break;
      //   case WIFI_AUTH_WPA2_ENTERPRISE:
      //     Serial.print("WPA2-EAP");
      //     break;
      //   case WIFI_AUTH_WPA3_PSK:
      //     Serial.print("WPA3");
      //     break;
      //   case WIFI_AUTH_WPA2_WPA3_PSK:
      //     Serial.print("WPA2+WPA3");
      //     break;
      //   case WIFI_AUTH_WAPI_PSK:
      //     Serial.print("WAPI");
      //     break;
      //   default:
      //     Serial.print("unknown");
      // }
      Serial.println();
      delay(10);
    }
    if (!found)
      Serial.println("Network not found");
  }

  // Serial.println();

  // Delete the scan result to free memory for code below.
  WiFi.scanDelete();
}

