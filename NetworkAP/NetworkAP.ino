
#include <WiFi.h>
#include <NetworkClient.h>
#include <WiFiAP.h>

// Set these to your desired credentials.
const char *ssid = "KatieScienceFair";
const char *password = "yourPassword";

NetworkServer server(80);

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println();
  Serial.println("Configuring access point...");

  // You can remove the password parameter if you want the AP to be open.
  // a valid password must have more than 7 characters
  if (!WiFi.softAP(ssid, password)) {
    Serial.println("Soft AP creation failed.");
    while (1);
  }
  Serial.print("AP SSID: ");
  Serial.println(WiFi.softAPSSID());
  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());
  server.begin();

  Serial.println("Server started");
  Serial.println("Katie's Science Fair 2025");
}

const char * serverIp = "192.168.4.2";
const int port = 1107;

void loop() {
  NetworkClient client;
  int line_count = 0;

  // Connect to remote server
  if (client.connect(serverIp, port)) {

    while (client.connected()) {
      // Print connection string
      // Serial.printf("Connected to server: %s:%d\n", client.remoteIP().toString(), client.remotePort());
      
      // Send a byte
      client.print(" ");

      // wait for response
      while (!client.available() && client.connected()) {
      }

      if (!client.connected()) {
        break;
      }

      // Read and display remote RSSI
      String remoteRssi = client.readString();
      // Serial.printf("Reported RSSI:  %s\n", remoteRssi);
      Serial.println(remoteRssi);

      line_count++;
      if (line_count == 20) {
        Serial.println();
        line_count = 0;
      }

      // Delay before next round
      delay(100);
    }

    Serial.println("Disconnected...");
  }
}
