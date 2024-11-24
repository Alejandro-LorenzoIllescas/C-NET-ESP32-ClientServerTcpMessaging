#include <WiFi.h>

const char *ssid = "ESP32-Access-Point";  
const char *password = "123456789";       

WiFiServer server(5000); 

// To allow 5 simultanius connections
const int maxClients = 5;   
WiFiClient clients[maxClients];  

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


  //  Try to connect new clients
  WiFiClient client = server.available();

  if (client) {
    bool added = false;
    for (int i = 0; i < maxClients; i++) {
      if (!clients[i] || !clients[i].connected()) {
        clients[i] = client; // Add the new client to the list
        Serial.print("New client connected. Assigned to position: ");
        Serial.println(i);
        added = true;
        break;
      }
    }
    if (!added) {
      // Reject new connection if max clients are reached
      Serial.println("Max clients reached. Rejecting connection.");
      client.stop();
    }
  }

  //Manage conecctions
  for (int i = 0; i < maxClients; i++) {
    if (clients[i] && clients[i].connected()) {
      if (clients[i].available()) {
        Serial.print("Data received from client ");
        Serial.println(i);

        // Read 
        String message = clients[i].readStringUntil('\n');
        Serial.print("Message: ");
        Serial.println(message);

        // Send acknowledgment back to the client
        clients[i].println("Message received: \"" + message + "\"");

        // Send message to all other clients
        broadcastMessage(message, i);

      } 
    }
    //for the momment dont control over the client desconnection
  }
}

void broadcastMessage(String message, WiFiClient sender) {
    for (int i = 0; i < maxClients; i++) {
        if (clients[i] && clients[i] != sender) { // Exclude the sender
            clients[i].println(message);
        }
    }
}