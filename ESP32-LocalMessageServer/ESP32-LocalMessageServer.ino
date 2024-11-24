#include <WiFi.h>

const char *ssid = "ESP32-Access-Point";  
const char *password = "123456789";       

WiFiServer server(5000); 

void setup() {
  Serial.begin(115200);
  Serial.println("Serial print test");
 
  WiFi.softAP(ssid, password);
  Serial.print("Access Point created with address: ");
  Serial.println(WiFi.softAPIP()); 

  server.begin();
  Serial.println("TCP Server started listening on port 5000");
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("Client connected");
    while (client.connected()) {
      if (client.available()) {
        Serial.println("Bytes recived by the client");
        String message = client.readStringUntil('\n');
        Serial.print("Message: ");
        Serial.println(message);

        client.println("Mesage received: \"" + message + "\"");
      }
    }

    client.stop();
    Serial.println("Client disconnected");
  }
}