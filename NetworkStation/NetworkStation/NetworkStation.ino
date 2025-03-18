#include <WiFi.h>
#include <NetworkClient.h>

// Replace with your own network credentials
const char *ssid = "KatieScienceFair";
const char *password = "yourPassword";

const int port = 1107;
NetworkServer server(port);

void setup() {
 
  Serial.begin(9600);
  delay(1000);
 
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("\nConnecting to WiFi Network ..");
 
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(100);
  }
 
  Serial.println();
  Serial.println("Connected to the WiFi network");
  Serial.printf("Local ESP32 IP: %s\n", WiFi.localIP());

  server.begin();
  Serial.println();
  Serial.println("Server started");
  Serial.printf("port: %d\n", port);

}

void loop() {
  NetworkClient client;
  do {
    delay(200);
    client = server.accept();
  } while(!client.connected());

  while (client.connected()) {
    // wait for next request
    int time_out = 10;
    while (time_out > 0 && !client.available()) {
      delay(200);
      time_out--;
    }

    if (time_out <= 0) {
      break;
    }

    // Print connection
    Serial.printf("Connected to: %s\n", client.remoteIP().toString());

    // Get the RSSI, send it
    String rssi = String(WiFi.RSSI());
    Serial.printf("Sending RSSI: %s\n", rssi);
    client.print(rssi);

    // Delay
    delay(200);

    // Empty the buffer
    client.flush();
  }
  
  client.stop();
  Serial.println("Disconnected.");
}
